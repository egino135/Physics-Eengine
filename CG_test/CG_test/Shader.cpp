#include "Shader.h"

#include <glm/gtc/type_ptr.hpp>
#include <opencv2\opencv.hpp>



// Point light positions
glm::vec3 pointLightPositions[] = {
	glm::vec3(5.0f, 5.0f, 5.0f),
	glm::vec3(-1.7f, 0.9f, 1.0f)
};
glm::vec3 spotLight[] =
{
	glm::vec3(0.1f, 0.1f, 0.1f),	//ambient
	glm::vec3(0.5f, 0.5f, 0.5f),	//diffuse
	glm::vec3(0.7f, 0.7f, 0.7f)		//specular
};
glm::vec3 defaultMaterial[] =
{
	glm::vec3(0.3, 0.3, 0.3),	//ambient
	glm::vec3(0.5, 0.5, 0.5),	//diffuse
	glm::vec3(0.2, 0.2, 0.2)	//specular
};

GLint loadTexture(const char * imagepath)
{
	//loadPNG_bind_texture(imagepath);	//some wrong, so paste it
	IplImage *image = cvLoadImage(imagepath, CV_LOAD_IMAGE_UNCHANGED);
	if (!image)
	{
		std::cout << imagepath << std::endl;
		puts("load image error!");

		return 0;
	}
	for (int i = 0; i < image->width; i++)
	{
		for (int j = 0; j < image->height; j++)
		{
			CvScalar s = cvGet2D(image, j, i);
			CvScalar a = cvScalar(s.val[2], s.val[1], s.val[0], s.val[3]);
			cvSet2D(image, j, i, a);
		}
	}
	GLuint textureID;
	glGenTextures(1, &textureID);
	glBindTexture(GL_TEXTURE_2D, textureID);
	if (image->nChannels == 4)
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image->width, image->height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image->imageData);
	else
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image->width, image->height, 0, GL_RGB, GL_UNSIGNED_BYTE, image->imageData);
	glGenerateMipmap(GL_TEXTURE_2D);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glBindTexture(GL_TEXTURE_2D, 0);
	cvReleaseImage(&image);
	return textureID;
}


Shader::Shader(const GLchar* vertexPath, const GLchar* fragmentPath)
{
	// 1. Retrieve the vertex/fragment source code from filePath
	std::string vertexCode;
	std::string fragmentCode;
	std::ifstream vShaderFile;
	std::ifstream fShaderFile;
	// ensures ifstream objects can throw exceptions:
	vShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	fShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	try
	{
		// Open files
		vShaderFile.open(vertexPath);
		fShaderFile.open(fragmentPath);
		//if (!vShaderFile)std::cout << vertexPath << " fail to open" << std::endl;
		//if (!fShaderFile)std::cout << fragmentPath << " fail to open" << std::endl;
		std::stringstream vShaderStream, fShaderStream;
		// Read file's buffer contents into streams
		vShaderStream << vShaderFile.rdbuf();
		fShaderStream << fShaderFile.rdbuf();
		// close file handlers
		vShaderFile.close();
		fShaderFile.close();
		// Convert stream into string
		vertexCode = vShaderStream.str();
		fragmentCode = fShaderStream.str();
	}
	catch (std::ifstream::failure e)
	{
		std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
	}
	const GLchar* vShaderCode = vertexCode.c_str();
	const GLchar * fShaderCode = fragmentCode.c_str();
	// 2. Compile shaders
	GLuint vertex, fragment;
	GLint success;
	GLchar infoLog[512];
	// Vertex Shader
	vertex = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertex, 1, &vShaderCode, NULL);
	glCompileShader(vertex);
	// Print compile errors if any
	glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(vertex, 512, NULL, infoLog);
		std::cout << vertexPath << "\nERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
	}
	// Fragment Shader
	fragment = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragment, 1, &fShaderCode, NULL);
	glCompileShader(fragment);
	// Print compile errors if any
	glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(fragment, 512, NULL, infoLog);
		std::cout << fragmentPath << "\nERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
	}
	// Shader Program
	this->Program = glCreateProgram();
	glAttachShader(this->Program, vertex);
	glAttachShader(this->Program, fragment);
	glLinkProgram(this->Program);
	// Print linking errors if any
	glGetProgramiv(this->Program, GL_LINK_STATUS, &success);
	if (!success)
	{
		glGetProgramInfoLog(this->Program, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
	}
	// Delete the shaders as they're linked into our program now and no longer necessery
	glDeleteShader(vertex);
	glDeleteShader(fragment);


	defaultTextureID = loadTexture("img/white.png");

}
void Shader::Use()
{
	glUseProgram(this->Program);
}
void Shader::setSimpleShader(glm::vec3 cameraPos, glm::vec3 cameraFront)
{
	// Set the lighting uniforms
	glUniform3f(glGetUniformLocation(this->Program, "viewPos"), cameraPos.x, cameraPos.y, cameraPos.z);
	// Directional light
	glUniform3f(glGetUniformLocation(this->Program, "directLight.direction"), -0.2f, -1.0f, -0.3f);
	glUniform3f(glGetUniformLocation(this->Program, "directLight.ambient"), 0.5f, 0.5f, 0.5f);
	glUniform3f(glGetUniformLocation(this->Program, "directLight.diffuse"), 0.7f, 0.7f, 0.7f);
	glUniform3f(glGetUniformLocation(this->Program, "directLight.specular"), 0.7f, 0.7f, 0.7f);
	// Point light 1
	glUniform3f(glGetUniformLocation(this->Program, "pointLights[0].position"), pointLightPositions[0].x, pointLightPositions[0].y, pointLightPositions[0].z);
	glUniform3f(glGetUniformLocation(this->Program, "pointLights[0].ambient"), 0.05f, 0.05f, 0.05f);
	glUniform3f(glGetUniformLocation(this->Program, "pointLights[0].diffuse"), 0.0f, 0.3f, 0.3f);
	glUniform3f(glGetUniformLocation(this->Program, "pointLights[0].specular"), 0.0f, 1.0f, 1.0f);
	glUniform1f(glGetUniformLocation(this->Program, "pointLights[0].constant"), 1.0f);
	glUniform1f(glGetUniformLocation(this->Program, "pointLights[0].linear"), 0.09);
	glUniform1f(glGetUniformLocation(this->Program, "pointLights[0].quadratic"), 0.032);
	// Point light 2
	glUniform3f(glGetUniformLocation(this->Program, "pointLights[1].position"), pointLightPositions[1].x, pointLightPositions[1].y, pointLightPositions[1].z);
	glUniform3f(glGetUniformLocation(this->Program, "pointLights[1].ambient"), 0.05f, 0.05f, 0.05f);
	glUniform3f(glGetUniformLocation(this->Program, "pointLights[1].diffuse"), 0.3f, 0.0f, 0.0f);
	glUniform3f(glGetUniformLocation(this->Program, "pointLights[1].specular"), 1.0f, 0.0f, 0.0f);
	glUniform1f(glGetUniformLocation(this->Program, "pointLights[1].constant"), 1.0f);
	glUniform1f(glGetUniformLocation(this->Program, "pointLights[1].linear"), 0.09);
	glUniform1f(glGetUniformLocation(this->Program, "pointLights[1].quadratic"), 0.032);
	// SpotLight
	glUniform3f(glGetUniformLocation(this->Program, "spotLight.position"), cameraPos.x, cameraPos.y, cameraPos.z);
	glUniform3f(glGetUniformLocation(this->Program, "spotLight.direction"), cameraFront.x, cameraFront.y, cameraFront.z);
	glUniform3f(glGetUniformLocation(this->Program, "spotLight.ambient"), spotLight[0].r, spotLight[0].g, spotLight[0].b);
	glUniform3f(glGetUniformLocation(this->Program, "spotLight.diffuse"), spotLight[1].r, spotLight[1].g, spotLight[1].b);
	glUniform3f(glGetUniformLocation(this->Program, "spotLight.specular"), spotLight[2].r, spotLight[2].g, spotLight[2].b);
	glUniform1f(glGetUniformLocation(this->Program, "spotLight.constant"), 1.0f);
	glUniform1f(glGetUniformLocation(this->Program, "spotLight.linear"), 0.09);
	glUniform1f(glGetUniformLocation(this->Program, "spotLight.quadratic"), 0.032);
	glUniform1f(glGetUniformLocation(this->Program, "spotLight.cutOff"), glm::cos(glm::radians(12.5f)));
	glUniform1f(glGetUniformLocation(this->Program, "spotLight.outerCutOff"), glm::cos(glm::radians(15.0f)));

}
void Shader::setDefaultMaterial()
{
	// Set properties
	glUniform3f(glGetUniformLocation(this->Program, "material.ambint"), defaultMaterial[0].r, defaultMaterial[0].g, defaultMaterial[0].b);
	glUniform3f(glGetUniformLocation(this->Program, "material.diffuse"), defaultMaterial[1].r, defaultMaterial[1].g, defaultMaterial[1].b);
	glUniform3f(glGetUniformLocation(this->Program, "material.specular"), defaultMaterial[2].r, defaultMaterial[2].g, defaultMaterial[2].b);
	glUniform1f(glGetUniformLocation(this->Program, "material.shininess"), 32.0f);
}
void Shader::setMaterial(glm::vec3 color)
{
	glUniform3f(glGetUniformLocation(this->Program, "material.ambint"), color.r, color.g, color.b);
	glUniform3f(glGetUniformLocation(this->Program, "material.diffuse"), color.r, color.g, color.b);
	glUniform3f(glGetUniformLocation(this->Program, "material.specular"), color.r, color.g, color.b);
	glUniform1f(glGetUniformLocation(this->Program, "material.shininess"), 32.0f);
}
void Shader::setShader(glm::mat4 projection, glm::mat4 view, glm::vec3 cameraPos, glm::vec3 cameraFront)
{
	glUniformMatrix4fv(glGetUniformLocation(this->Program, "view"), 1, GL_FALSE, glm::value_ptr(view));
	glUniformMatrix4fv(glGetUniformLocation(this->Program, "projection"), 1, GL_FALSE, glm::value_ptr(projection));

	setSimpleShader(cameraPos, cameraFront);

	setDefaultMaterial();
}
void Shader::setTexture(GLint textureID)
{
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, textureID);
	glUniform1i(glGetUniformLocation(this->Program, "material.texture_diffuse"), 0);
}
void Shader::setDefaultTexture()
{
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, this->defaultTextureID);
	glUniform1i(glGetUniformLocation(this->Program, "material.texture_diffuse"), 0);
}
