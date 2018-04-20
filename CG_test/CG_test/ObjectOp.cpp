#include "ObjectOp.h"

#include <glm/gtx/projection.hpp>

/*local*/
glm::vec3 myProject(glm::vec3 U, glm::vec3 V)
{
	//vector U project to vector V
	//Uv = ( (U dot V) / (V dot V) ) * V
	glm::vec3 Uv;
	Uv = (glm::dot(U, V) / glm::dot(V, V)) * V;
	return Uv;
}
glm::vec3 calculateTorque(Ball b1, Ball b2)
{
	glm::vec3 torque;	//define in world space;
						//torque = r cross F;

	//project(b2.center - b1.center, b1.force) = (b2.center - b1.center) + r 
	glm::vec3 b1b2 = b2.getCenter() - b1.getCenter();
	glm::vec3 projection = glm::proj(b1b2, b1.getForce());
	glm::vec3 r = projection - b1b2;
	torque = glm::cross(r, b1.getForce());

	torque = b1.getWorld2Motion() * glm::vec4(torque, 0.0);	//convert to motion space

	return torque;	//return b2 torque(define in motion space)
}
/**/
void ballCollideFloor(Ball& ball, float FloorNumber, float friction)
{
	glm::vec3 v = ball.getV0();
	glm::vec3 reflectV;
	if (FloorNumber < 0)
		return;
	else if (FloorNumber < 2)
	{
		reflectV = v * glm::vec3(1.0, 1.0, -1.0);
	}
	else if(FloorNumber < 4)
	{
		reflectV = v * glm::vec3(1.0, -1.0, 1.0);
	}
	else if(FloorNumber < 6)
	{
		reflectV = v * glm::vec3(-1.0, 1.0, 1.0);
	}
	ball.setV0(reflectV * friction);
	//printf("%f\n", reflectV.y);
}
void ballCollideBall(Ball& ball_1, Ball& ball_2, float friction)
{
	glm::vec3 twoBallVector = ball_1.getCenter() - ball_2.getCenter();

	glm::vec3 ball_1_Project = glm::proj(ball_1.getV0(), twoBallVector);
	glm::vec3 ball_1_Vector = ball_1.getV0() - ball_1_Project;
	//ball.v0 = ball_1_Project + ball_1_Vector
	glm::vec3 ball_2_Project = glm::proj(ball_2.getV0(), -twoBallVector);
	glm::vec3 ball_2_Vector = ball_2.getV0() - ball_2_Project;

	//https://zh.wikipedia.org/wiki/%E7%A2%B0%E6%92%9E
	//according to m1v1 + m2v2 = m1v1' + m2v2';
	//and 1/2*m*v1*v1 + 1/2*m*v2*v2 = 1/2*m*v1'*v1' + 1/2*m*v2'*v2'
	//v1' = ((m1 - m2)*v1 + 2*m2v2) / m1+m2
	//v2' = ((m2 - m1)*v2 + 2*m1v1) / m1+m2

	//ball_1_Project is v1
	//ball_2_Project is v2

	glm::vec3 v1 = ball_1_Project;
	float m1 = ball_1.getMass();
	glm::vec3 v2 = ball_2_Project;
	float m2 = ball_2.getMass();

	ball_1_Project = ((m1 - m2)*v1 + (2.0f * m2 * v2)) / (m1 + m2);
	ball_2_Project = ((m2 - m1)*v2 + (2.0f * m1 * v1)) / (m1 + m2);

	ball_1.setV0(ball_1_Project + ball_1_Vector * friction);
	ball_2.setV0(ball_2_Project + ball_2_Vector * friction);
}
void ballCollideBall_rotate(Ball& b1, Ball& b2)
{
	glm::vec3 b1Torque = calculateTorque(b2, b1);	//define in world space
	glm::vec3 b2Torque = calculateTorque(b1, b2);

	glm::vec3 b1angularAlpha_motion = b1.getInverseInertia_motion()*
		(b1Torque - glm::cross(b1.getAngularV0_motion(), b1.getInertia_motion() * b1.getAngularV0_motion()));

	b1angularAlpha_motion = glm::radians(b1angularAlpha_motion);
	b1.setAngularAlpha_motion(b1angularAlpha_motion);

	glm::vec3 b2angularAlpha_motion = b2.getInverseInertia_motion()*
		(b2Torque - glm::cross(b2.getAngularV0_motion(), b2.getInertia_motion() * b2.getAngularV0_motion()));

	b2angularAlpha_motion = glm::radians(b2angularAlpha_motion);
	b2.setAngularAlpha_motion(b2angularAlpha_motion);
	
}