#pragma once

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <glm/glm.hpp>
#include <GL/glew.h>

glm::vec3 pointLightPositions[];

GLint loadTexture(const char * imagepath);

class Shader
{
public:
	GLuint Program;
	// Constructor generates the shader on the fly
	Shader(const GLchar* vertexPath, const GLchar* fragmentPath);
	// Uses the current shader
	void Use();
	void setShader(glm::mat4 projection, glm::mat4 view, glm::vec3 cameraPos, glm::vec3 cameraFront);
	void setSimpleShader(glm::vec3 cameraPos, glm::vec3 cameraFront);
	void setDefaultMaterial();
	void setMaterial(glm::vec3 color);
	void setTexture(GLint textureID);
	void setDefaultTexture();
private:
	GLint defaultTextureID;
};


