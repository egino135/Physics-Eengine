#pragma once

#include <GL\glew.h>
#include <GL\glu.h>
#include <GL\gl.h>
#include <glm/glm.hpp>

#include "BVolume.h"
#include "Shader.h"

#define MAX_BALL_NUM 100
#define BALL_DRAG 0.047

class GeneralBall
{
public:
	GeneralBall(const char* texturePath);
	const GLuint VAO;
	GLint getTextureID();
private:
	GLint textureID;
};


class Ball:public BSphere
{
public:
	static unsigned int ballNum;
	const unsigned int serialNumber;
	Ball(glm::vec3 initialPostion, glm::vec3 v0 = glm::vec3(0.01), 
		glm::vec3 color = glm::vec3(0.5), 
		float mass = 1.0, float radius = 0.2);
	void render(Shader shader, GeneralBall gBall);
	void renderAABB(Shader shader, GLuint cubeVAO);
	void movePosition(glm::vec3 moveVector);

	void addForce(glm::vec3 f);
	glm::vec3 getForce();

	void setV0(glm::vec3 v);
	glm::vec3 getV0();

	void addAcceleration(glm::vec3 a);

	void move(float time);
	void unMove();	//undo move last time

	glm::vec3 getCenter();
	float getMass();

	void setColor(glm::vec3 color);
	glm::vec3 getColor();

	glm::mat4 getWorld2Motion();
	glm::mat4 getWorld2Body();
	glm::mat4 getBody2Motion();

	glm::mat3 getInertia_motion();
	glm::mat3 getInverseInertia_motion();

	glm::vec3 getAngularV0_motion();


	void setAngularAlpha_motion(glm::vec3 angularAlpha_motion);

	void colliding();
	bool isCollision();
	void initialize();

	void rotatePositon(glm::vec3 rotateDegree);	//calculate rotate matrix, and set new position
	
private:
	bool collision;
	bool stillness;
	float radius;
	glm::vec3 geoCenter;	//define in body space, convert to motion space
	glm::vec3 position;		//define in world space, convert to body space(left bottom cornor)
	glm::mat4 rotationMatrix;	//define in body space, rotate ball in body space, then render it
	glm::mat4 modelMatrix;
	void setPosition(glm::vec3 Avector);
	void setForce(glm::vec3 force);
	

	//define some newton varible
	//define in world space(global);
	glm::vec3 displace;
	glm::vec3 force;//is vector
	glm::vec3 v0;	//is vector		//m/s
	float mass;		//kg
	//angle.x/y/z is angle vector between x/y/z axis angle
	//define in motion space
	//rotation center is geoCenter
	//glm::vec3 angle;

	//define some rotation variable
	//define in motion space
	glm::mat3 inertia_motion;		//moment of inertia;
	glm::vec3 force_motion;
	glm::vec3 v0_motion;
	glm::vec3 angularV0_motion;		//Angular velocity
	glm::vec3 angularAlpha_motion;	//Angular acceleration
	//glm::vec3 torque_motion;		//moment of force
	
	glm::vec3 world2body;		//world space to body space have some rotate	
	glm::vec3 bodyd2motion;		//body space to motion space have some rotate

	//
	

	float dragCoefficient;
	glm::vec3 color;
};

