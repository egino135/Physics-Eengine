#pragma once

#include <GL\glew.h>
#include <GL\glu.h>
#include <GL\gl.h>
#include <glm/glm.hpp>

#include "BVolume.h"
#include "Shader.h"

#define MAX_CUBE_NUM 100

class Cube:public AABBox
{
public:
	static unsigned int cubeNum;
	const unsigned int serialNumber;	//serialNumber < MAX_CUBE_NUM
	Cube(glm::vec3 initialPostion, glm::vec3 v0 = glm::vec3(0.01), float mass = 1.0, float length = 1.0, float width = 1.0, float height = 1.0);
	void render(Shader shader, GLuint VAO);
	void colliding();
	bool isCollision();
	void initialize();
private:
	bool collision;
	float length, width, height;
	glm::vec3 geoCenter;
	glm::vec3 position;
	glm::mat4 modelMatrix;
	//define some newton varible
	//define in motion space;
	glm::vec3 force;//is vector
	//initial is not zero,because P = mv, if P == 0, is not Elastic collision 
	glm::vec3 v0;	//is vector		//m/s	
	float mass;		//kg
};
class GeneralCube
{
public:
	GeneralCube();
	const GLuint VAO;
};
