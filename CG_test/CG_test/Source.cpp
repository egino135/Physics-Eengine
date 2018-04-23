#define NDEBUG

// Std. Includes
#include <string>
#include <memory>

#define GRAVITY	9.80665 //m/s*s

// GLEW
#define GLEW_STATIC
#include <GL/glew.h>

// GLFW
#include <GLFW/glfw3.h>

// My includes
#include "Shader.h"
#include "Camera.h"
#include "vertexOp.h"
#include "ObjectOp.h"


// GLM Mathemtics
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/string_cast.hpp>

// Other Libs
#include<GL/freeglut.h>

// Properties
GLuint screenWidth = 1200, screenHeight = 800;

// Function prototypes
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
void mouse_callback(GLFWwindow* window, double xpos, double ypos);
void Do_Movement();

// Camera
Camera camera(glm::vec3(0.0f, 3.0f, 10.0f));
bool keys[1024];
bool firstMouse = true;


//local

GLfloat deltaTime = 0.0f;
GLfloat lastFrame = 0.0f;
int pressNumber = 0;
bool PhongEnable = true;

float consumeRate = 0.95;

long double gameTime = 0.0;
float timePerOnce = 0.0015;


//static member
unsigned int Ball::ballNum = 0;
unsigned int Cube::cubeNum = 0;






void drawTestObject(Shader shader, GLuint VAO)
{
	shader.Use();

	glBindVertexArray(VAO);

	glm::mat4 model;

	model = glm::mat4();
	model = glm::translate(model, glm::vec3(5.0, 0.5, 5.0));
	glUniformMatrix4fv(glGetUniformLocation(shader.Program, "model"), 1, GL_FALSE, glm::value_ptr(model));
	glDrawArrays(GL_TRIANGLES, 0, 36);

	model = glm::mat4();
	model = glm::translate(model, glm::vec3(10.0, 0.5, 1.0));
	model = glm::rotate(model, (float)(glm::radians(22.5f)), glm::vec3(0.0, 1.0, 0.0));
	glUniformMatrix4fv(glGetUniformLocation(shader.Program, "model"), 1, GL_FALSE, glm::value_ptr(model));
	glDrawArrays(GL_TRIANGLES, 0, 36);

	model = glm::mat4();
	model = glm::translate(model, glm::vec3(3.0, 0.5 * 1.5, -2.0));
	model = glm::scale(model, glm::vec3(1.5, 1.5, 1.5));
	model = glm::rotate(model, (float)(glm::radians(45.5f)), glm::vec3(0.0, 1.0, 0.0));

	glUniformMatrix4fv(glGetUniformLocation(shader.Program, "model"), 1, GL_FALSE, glm::value_ptr(model));
	glDrawArrays(GL_TRIANGLES, 0, 36);

	glBindVertexArray(0);
}
void drawLigthPos(Shader shader, GLuint VAO)
{
	// Draw the lamps
	shader.Use();

	glBindVertexArray(VAO);
	glm::mat4 model;


	for (GLuint i = 0; i < 2; i++)
	{
		model = glm::mat4();
		model = glm::translate(model, pointLightPositions[i]);
		//model = glm::scale(model, glm::vec3(0.2f)); // Make it a smaller cube
		glUniformMatrix4fv(glGetUniformLocation(shader.Program, "model"), 1, GL_FALSE, glm::value_ptr(model));
		//lampModel.Draw(lampShader);
		glDrawArrays(GL_TRIANGLES, 0, 36);
	}
	glBindVertexArray(0);
}
void renderFloorCube(Shader shader, GLuint VAO, Cube floorCube[6])
{
	for (int i = 0; i < 6; i++)
	{
		if (floorCube[i].isCollision())
		{
			glUniform3f(glGetUniformLocation(shader.Program, "material.ambint"), 0.9, 0.3, 0.3);
			glUniform3f(glGetUniformLocation(shader.Program, "material.diffuse"), 0.9, 0.3, 0.3);
			glUniform3f(glGetUniformLocation(shader.Program, "material.specular"), 0.9, 0.3, 0.3);
			floorCube[i].render(shader, VAO);
			shader.setDefaultMaterial();
		}
		else
		{
			floorCube[i].render(shader, VAO);
		}
		
	}
}
void renderLight(Shader shader, GLuint VAO, Cube light[2])
{
	for (int i = 0; i < 2; i++)
	{
		light[i].render(shader, VAO);
	}
}
int testCollisionDetect(Ball& ball, Cube cube[6])
{
	for (int i = 0; i < 6; i++)
	{
		if (ball.collisionTest(cube[i]))
		{
			/*ball.colliding();
			cube[i].colliding();*/
			//printf("#%d Cube colliding!\n", cube[i].serialNumber);
			return cube[i].serialNumber;
		}
	}
	return -1;
}
bool testCollisionBall(Ball& b1, Ball& b2)
{
	if (b1.collisionTest(b2))
	{
		//b1.colliding();
		//b2.colliding();
		return true;
	}
	else
		return false;
}
void Give_force(Ball& ball, float force)
{
	if (keys[GLFW_KEY_UP])
		ball.addForce(glm::vec3(0.0, 0.0, force));
		//ball.rotatePositon(glm::vec3(0.0, 15.0, 0.0));
	if (keys[GLFW_KEY_DOWN])
		ball.addForce(glm::vec3(0.0, 0.0, -force));
		//ball.rotatePositon(glm::vec3(0.0, -15.0, 0.0));
	if (keys[GLFW_KEY_LEFT])
		ball.addForce(glm::vec3(-force, 0.0, 0.0));
	if (keys[GLFW_KEY_RIGHT])
		ball.addForce(glm::vec3(force, 0.0, 0.0));
	if (keys[GLFW_KEY_COMMA])	// '<'
		ball.addForce(glm::vec3(0.0, force, 0.0));
	if (keys[GLFW_KEY_PERIOD])	// '>'
		ball.addForce(glm::vec3(0.0, -force, 0.0));
}
// The MAIN function, from here we start our application and run our Game loop
int main()
{
	// Init GLFW
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	GLFWwindow* window = glfwCreateWindow(screenWidth, screenHeight, "LearnOpenGL", nullptr, nullptr); // Windowed
	glfwMakeContextCurrent(window);

	// Set the required callback functions
	glfwSetKeyCallback(window, key_callback);
	glfwSetCursorPosCallback(window, mouse_callback);
	glfwSetScrollCallback(window, scroll_callback);

	// Options
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

	// Initialize GLEW to setup the OpenGL Function pointers
	glewExperimental = GL_TRUE;
	glewInit();

	// Define the viewport dimensions
	glViewport(0, 0, screenWidth, screenHeight);

	// Setup some OpenGL options
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);

	// Setup and compile our shaders
	//Shader shader("newShaders/non_texture.vert", "newShaders/non_texture.frag");
	Shader shader("newShaders/complete.vert", "newShaders/complete.frag");
	Shader lampShader("newShaders/lamp.vert", "newShaders/lamp.frag");

	GLuint cubeVAO = generateCubeVAO();
	GLuint lightVAO = generateCubeVAO();

	//floor's mass is unlimited big!	P = mv,P is also big!
	//it can rebound any object
	Cube floorCube[6] =
	{
		{ glm::vec3(0.0, 0.0, 0.0),		glm::vec3(0.01, 0.01, 0.01),	1000000.0, 10.0f, 10.0f, 0.1f },
		{ glm::vec3(0.0, 0.0, 10.0),	glm::vec3(0.01, 0.01, 0.01),	1000000.0, 10.0f, 10.0f, 0.1f },
		{ glm::vec3(0.0, 0.0, 0.0),		glm::vec3(0.01, 0.01, 0.01),	1000000.0, 10.0f, 0.1f, 10.0f },
		{ glm::vec3(0.0, 10.0, 0.0),	glm::vec3(0.01, 0.01, 0.01),	1000000.0, 10.0f, 0.1f, 10.0f },
		{ glm::vec3(0.0, 0.0, 0.0),		glm::vec3(0.01, 0.01, 0.01),	1000000.0, 0.1f, 10.0f, 10.0f },
		{ glm::vec3(10.0, 0.0, 0.0),	glm::vec3(0.01, 0.01, 0.01),	1000000.0, 0.1f, 10.0f, 10.0f }
	};
	Cube light[2] =
	{
		{ glm::vec3(pointLightPositions[0].x - 0.5, pointLightPositions[0].y - 0.5, pointLightPositions[0].z - 0.5) },	//length, width, height = 1.0 
		{ glm::vec3(pointLightPositions[1].x - 0.5, pointLightPositions[1].y - 0.5, pointLightPositions[1].z - 0.5) }
	};
	GeneralCube generalCube;

	//Ball testBall(glm::vec3(2.0, 2.0, 2.0), glm::vec3(0.0, 0.0, 0.0), glm::vec3(0.5, 0.2, 0.2));	//position is left-botton cornor
	//Ball myBall(glm::vec3(2.3, 4.0, 2.0), glm::vec3(0.0, 0.0, 0.0));
	GeneralBall generalBall("img/floor.jpg");
	generalBall.generateBall(glm::vec3(2.0, 2.0, 2.0), glm::vec3(0.0, 0.0, 0.0), glm::vec3(0.5, 0.2, 0.2));
	generalBall.generateBall(glm::vec3(2.3, 4.0, 2.0), glm::vec3(0.0, 0.0, 0.0));

	for (int i = 0; i < 18; i++)
		generalBall.generateBall();

	Ball& testBall = generalBall.ballVector[0];

	//////////////////////////////////////////////////
	// Game loop
	while (!glfwWindowShouldClose(window))
	{
		// Check and call events
		glfwPollEvents();
		Do_Movement();

		// Set frame time
		GLfloat currentFrame = gameTime;
		if (keys[GLFW_KEY_KP_0])
		testBall.addTorque_motion(glm::vec3(0.0, 0.0, 1.0));
			gameTime += timePerOnce;
		//GLfloat currentFrame = glfwGetTime();
		deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;


		// Clear the colorbuffer
		glClearColor(0.75f, 0.75f, 0.75f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		// Transformation matrices
		glm::mat4 projection = glm::perspective(camera.Zoom, (float)screenWidth / (float)screenHeight, 0.1f, 100.0f);
		glm::mat4 view = camera.GetViewMatrix();
		
		//set shaders
		shader.Use();
		shader.setShader(projection, view, camera.Position, camera.Front);
		lampShader.Use();
		lampShader.setShader(projection, view, camera.Position, camera.Front);

		//get some force or accelration
		generalBall.addGravity((glm::vec3(0.0, -GRAVITY, 0.0)));
		Give_force(testBall, 15.0);


		for (int i = 0; i < generalBall.ballVector.size(); i++)
		{
			Ball& ball = generalBall.ballVector[i];
			int collisionCubeNumber = testCollisionDetect(ball, floorCube);
			if (collisionCubeNumber == -1)
			{
				//
			}
			else
			{
				ball.unMove();
				ballCollideFloor(ball, collisionCubeNumber, consumeRate);
			}
		}
		for (int i = 0; i < generalBall.ballVector.size() - 1 ; i++)
		{
			Ball& b1 = generalBall.ballVector[i];
			for (int j = i + 1; j < generalBall.ballVector.size(); j++)
			{
				Ball& b2 = generalBall.ballVector[j];
				if (testCollisionBall(b1, b2))
				{
					b1.unMove();
					b2.unMove();
					ballCollideBall(b1, b2, consumeRate);
					ballCollideBall_rotate2(b1, b2);
				}
			}
		}
		generalBall.move(deltaTime);
		
		//printf("%f, %f, %f\n", testBall.getCenter().x, testBall.getCenter().y, testBall.getCenter().z);

		//render
		generalBall.render(shader);
		generalBall.renderAABB(shader, generalCube.VAO);
		renderFloorCube(shader, generalCube.VAO, floorCube);
		renderLight(lampShader, generalCube.VAO, light);

		//no use class object to render
		//drawTestObject(shader, cubeVAO);
		//drawLigthPos(lampShader, lightVAO);
		
		//initial some parameter
		for (int i = 0; i < 6; i++)
		{
			floorCube[i].initialize();
		}

		generalBall.initialize();

		// Swap the buffers
		glfwSwapBuffers(window);
	}

	glfwTerminate();
	return 0;
}

#pragma region "User input"

// Moves/alters the camera positions based on user input
void Do_Movement()
{
	// Camera controls
	if (keys[GLFW_KEY_W])
		camera.ProcessKeyboard(FORWARD, deltaTime);
	if (keys[GLFW_KEY_S])
		camera.ProcessKeyboard(BACKWARD, deltaTime);
	if (keys[GLFW_KEY_A])
		camera.ProcessKeyboard(LEFT, deltaTime);
	if (keys[GLFW_KEY_D])
		camera.ProcessKeyboard(RIGHT, deltaTime);
	if (keys[GLFW_KEY_KP_0])
		pressNumber = 0;
	if (keys[GLFW_KEY_KP_1])
		pressNumber = 1;
	if (keys[GLFW_KEY_KP_2])
		pressNumber = 2;
	if (keys[GLFW_KEY_KP_3])
		pressNumber = 3;
	if (keys[GLFW_KEY_KP_4])
		pressNumber = 4;
	if (keys[GLFW_KEY_KP_5])
		pressNumber = 5;
	if (keys[GLFW_KEY_KP_6])
		pressNumber = 6;
	if (keys[GLFW_KEY_KP_7])
		pressNumber = 7;
	if (keys[GLFW_KEY_KP_8])
		pressNumber = 8;
	if (keys[GLFW_KEY_KP_9])
		pressNumber = 9;
}

// Is called whenever a key is pressed/released via GLFW
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);

	if (action == GLFW_PRESS)
		keys[key] = true;
	else if (action == GLFW_RELEASE)
		keys[key] = false;
	if (key == GLFW_KEY_P && action == GLFW_PRESS)
		PhongEnable = true;
	if (key == GLFW_KEY_G && action == GLFW_PRESS)
		PhongEnable = false;
		
}
void mouse_callback(GLFWwindow* window, double xpos, double ypos)
{
	static int lastX, lastY;
	if (firstMouse)
	{
		lastX = xpos;
		lastY = ypos;
		firstMouse = false;
	}

	GLfloat xoffset = xpos - lastX;
	GLfloat yoffset = lastY - ypos;

	lastX = xpos;
	lastY = ypos;

	camera.ProcessMouseMovement(xoffset, yoffset);
}
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
	camera.ProcessMouseScroll(yoffset * 0.1);
}
