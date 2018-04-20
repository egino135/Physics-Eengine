//	#include <opencv2\opencv.hpp>
#include <glm/glm.hpp>
#include <cmath>

#include "MAO_Vertex.h"
#include "vertexOp.h"

GLuint generateCubeVAO()
{
	GLuint VBO, VAO;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);

	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(cubeVertices), cubeVertices, GL_STATIC_DRAW);

	// Position attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);

	//texel
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(6 * sizeof(GLfloat)));
	glEnableVertexAttribArray(2);

	glBindVertexArray(0); // Unbind VAO

	return VAO;
}
GLuint generateBallVAO()
{
	GLuint ballVAO;
	glGenVertexArrays(1, &ballVAO);
	GLuint ballVertexVBO, ballNormalVBO, ballTextureVBO;
	glGenBuffers(1, &ballVertexVBO);
	glGenBuffers(1, &ballNormalVBO);
	glGenBuffers(1, &ballTextureVBO);
	GLuint EBO;
	glGenBuffers(1, &EBO);

	glBindVertexArray(ballVAO);

	glBindBuffer(GL_ARRAY_BUFFER, ballVertexVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(ballVertex), ballVertex, GL_STATIC_DRAW);
	// Position attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(ballIndex), ballIndex, GL_STATIC_DRAW);

	glBindBuffer(GL_ARRAY_BUFFER, ballNormalVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(ballVertex), ballVertex, GL_STATIC_DRAW);
	// Position attribute
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(1);

	glBindBuffer(GL_ARRAY_BUFFER, ballTextureVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(ballTextureCoordinate), ballTextureCoordinate, GL_STATIC_DRAW);
	// Position attribute
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(2);

	glBindVertexArray(0); // Unbind VAO

	return ballVAO;
}
unsigned int getBallIndexSize()
{
	return sizeof(ballIndex) / sizeof(unsigned int);
}