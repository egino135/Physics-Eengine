#include <glm/gtc/type_ptr.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/quaternion.hpp>
#include <glm/gtc/quaternion.hpp>

#include "Ball.h"
#include "vertexOp.h"



Ball::Ball(glm::vec3 initialPostion, glm::vec3 v0, glm::vec3 color, float mass, float radius)
:BSphere(radius, initialPostion+radius),
serialNumber(Ball::ballNum++)
{
	if (radius < 0.15)
		radius = 0.15;
	else if (radius > 0.225)
		radius = 0.225;
	this->radius = radius;
	this->modelMatrix = glm::mat4();
	this->rotationMatrix = glm::mat4();

	this->geoCenter.x = radius;
	this->geoCenter.y = radius;
	this->geoCenter.z = radius;

	this->position = initialPostion;

	this->v0 = v0;

	this->mass = mass;

	this->collision = false;

	this->displace = glm::vec3(0.0);
	
	this->force = glm::vec3(0.0);	//resultant force

	this->color = color;

	this->inertia_motion = glm::mat3(0);
	this->inertia_motion[0][0] = (2.0 / 5.0) * mass * radius * radius;	//Ixx
	this->inertia_motion[1][1] = (2.0 / 5.0) * mass * radius * radius;	//Iyy
	this->inertia_motion[2][2] = (2.0 / 5.0) * mass * radius * radius;	//Izz

	this->force_motion;
	//this->v0_motion;
	this->angularV0_motion = glm::vec3(0.0);

	this->dragCoefficient = BALL_DRAG;
	//this->torque_motion = glm::vec3(0.0);
}
void Ball::render(Shader shader, GeneralBall gBall)
{
	shader.Use();

	shader.setMaterial(this->color);
	shader.setTexture(gBall.getTextureID());

	glBindVertexArray(gBall.VAO);

	this->modelMatrix = glm::mat4();
	//this->modelMatrix = glm::translate(this->modelMatrix, this->geoCenter);
	//this->modelMatrix = glm::translate(this->modelMatrix, this->position);
	this->modelMatrix *= getWorld2Motion();
	this->modelMatrix = glm::scale(this->modelMatrix, glm::vec3(this->radius, this->radius, this->radius));
	glUniformMatrix4fv(glGetUniformLocation(shader.Program, "model"), 1, GL_FALSE, glm::value_ptr(this->modelMatrix));
	glDrawElements(GL_TRIANGLES,getBallIndexSize(), GL_UNSIGNED_INT, 0);

	glBindVertexArray(0);

	shader.setDefaultTexture();
	shader.setDefaultMaterial();

	return;
}
void Ball::setPosition(glm::vec3 newPosition)
{
	this->position = newPosition;
	//setBScenter(this->position + this->radius);
	setBScenter(getCenter());
	return;
}
void Ball::movePosition(glm::vec3 moveVector)
{
	//if (isCollision())
	//	return;
	glm::vec4 newPosition = glm::vec4(getCenter(), 1.0) + glm::vec4(moveVector, 0.0);	//move center
	//center convert to left bottom cornor, mean motion space convert to body space
	newPosition = glm::inverse(getBody2Motion()) * newPosition;
	setPosition(newPosition);
	return;
}
//calculate new position
void Ball::move(float time)	//time is delta t
{
	//rotation move

	//omega = omega + alpha * t
	this->angularV0_motion = this->angularV0_motion + this->angularAlpha_motion * time;
	//calculate drag force(mass is same, calculate accelerate)
	this->angularAlpha_motion -= this->angularAlpha_motion * glm::abs(this->angularV0_motion) * this->dragCoefficient;
	//degree = omega * t
	glm::vec3 rotateDegree = this->angularV0_motion * time;	//of course, define in motion space

	rotatePositon(rotateDegree);

	//linear move
	//F = ma, a = F/m
	glm::vec3 a = this->force / this->mass;
	//calculate drag force(mass is same, calculate accelerate)
	a -= a * glm::abs(this->v0) * this->dragCoefficient;
	//S = v0*t + 1/2*a*t*t
	glm::vec3 S;
	S = this->v0 * time + a*time*time*0.5f;
	this->displace = S;

	//v = v0 + a*t;
	this->v0 = this->v0 + a * time;

	//drag

	movePosition(S);
	//printf("%f, %f, %f\n", v0.x, v0.y, v0.z);

}
void Ball::unMove()
{
	movePosition(-this->displace);
}
glm::vec3 Ball::getCenter()
{
	glm::vec4 pos(0.0, 0.0, 0.0, 1.0);
	pos = getWorld2Motion() * pos;
	return pos;
	//return this->position + this->geoCenter;
}
float Ball::getMass()
{
	return this->mass;
}
void Ball::setColor(glm::vec3 color)
{
	this->color = color;
}
glm::vec3 Ball::getColor()
{
	return this->color;
}
void Ball::addForce(glm::vec3 f)
{
	setForce(f + this->force);
}
void Ball::addAcceleration(glm::vec3 a)
{
	//F = ma
	glm::vec3 f = this->mass * a;
	addForce(f);
}
glm::vec3 Ball::getForce()
{
	return this->force;
}
void Ball::setV0(glm::vec3 v)
{
	this->v0 = v;
}
glm::vec3 Ball::getV0()
{
	return this->v0;
}
void Ball::setForce(glm::vec3 force)
{
	this->force = force;
}
void Ball::colliding()
{
	this->collision = true;
}
bool Ball::isCollision()
{
	return this->collision;
}
void Ball::initialize()
{
	this->collision = false;
	this->force = glm::vec3(0.0);
}
glm::mat4 Ball::getWorld2Motion()
{
	glm::mat4 w2m = glm::mat4();
	
	/*w2m = glm::translate(w2m, this->geoCenter);	//body to motion
	w2m *= this->rotationMatrix;
	w2m = glm::translate(w2m, this->position);	//world to body
	*/
	w2m *= getBody2Motion();
	w2m *= getWorld2Body();

	return w2m;
}
glm::mat3 Ball::getInertia_motion()
{
	return this->inertia_motion;
}
glm::mat3 Ball::getInverseInertia_motion()
{
	return glm::inverse(this->inertia_motion);
}
glm::vec3 Ball::getAngularV0_motion()
{
	return this->angularV0_motion;
}
void Ball::setAngularAlpha_motion(glm::vec3 angularAlpha_motion)
{
	this->angularAlpha_motion = angularAlpha_motion;
}
void Ball::renderAABB(Shader shader, GLuint cubeVAO)
{
	shader.Use();

	shader.setMaterial(glm::vec3(0.0, 1.0, 0.0));

	glBindVertexArray(cubeVAO);

	glm::mat4 matrix = glm::mat4();
	matrix = glm::translate(matrix, (getAABB_posMin() + getAABB_posMax()) / 2.0f);
	matrix *= this->rotationMatrix;
	matrix = glm::scale(matrix, glm::vec3(this->radius*2.0, this->radius*2.0, this->radius*2.0));
	glUniformMatrix4fv(glGetUniformLocation(shader.Program, "model"), 1, GL_FALSE, glm::value_ptr(matrix));
	glDrawArrays(GL_LINE_STRIP, 0, 36);

	glBindVertexArray(0);

	shader.setDefaultMaterial();

	return;
}
void Ball::rotatePositon(glm::vec3 rotateDegree)
{
	glm::vec4 nowCenter = glm::vec4(getCenter(), 1.0);	//center cant change after rotated, now center == new center

	//use Euler angles, because angles is close to zero, R1R2 ~ R2R1
	//use Y-Z-X => RxRzRy * vector
	//calculate new rotation matrix
	//從中心來看的旋轉(rotatation from motion space)等價於從左下角來看的旋轉(rotation from body space)
	//意即中心旋轉A度，則表示左下角與中心相對關係旋轉A度
	//旋轉時中心不會移動!
	this->rotationMatrix = glm::rotate(this->rotationMatrix,
		(float)(glm::radians(rotateDegree.x)), glm::vec3(1.0, 0.0, 0.0));
	this->rotationMatrix = glm::rotate(this->rotationMatrix,
		(float)(glm::radians(rotateDegree.z)), glm::vec3(0.0, 0.0, 1.0));
	this->rotationMatrix = glm::rotate(this->rotationMatrix,
		(float)(glm::radians(rotateDegree.y)), glm::vec3(0.0, 1.0, 0.0));

	glm::mat4 newPositionMatrix;	//from now center convert to new position(that is ball left bottom cornor pos)
									//newPositionMatrix = inverse(body to motion)
									//newPositionMatrix = inverse(T * R)
									//newPositionMatrix = inverse(R)*inverse(T)
	//newPositionMatrix = glm::inverse(this->rotationMatrix);
	//newPositionMatrix = glm::translate(newPositionMatrix, this->geoCenter * -1.0f);
	
	newPositionMatrix = glm::inverse(getBody2Motion());

	setPosition(newPositionMatrix * nowCenter);

	return;
}
glm::mat4 Ball::getWorld2Body()
{
	glm::mat4 w2b = glm::mat4();

	w2b = glm::translate(w2b, this->position);	//world to body

	return w2b;
}
glm::mat4 Ball::getBody2Motion()
{
	glm::mat4 b2m = glm::mat4();

	b2m = glm::translate(b2m, this->geoCenter);	//body to motion
	b2m *= this->rotationMatrix;

	return b2m;
}

GeneralBall::GeneralBall(const char* texturePath)
:VAO(generateBallVAO())
{
	this->textureID = loadTexture(texturePath);
}
GLint GeneralBall::getTextureID()
{
	return this->textureID;
}