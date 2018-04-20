#include <glm/gtc/type_ptr.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "Cube.h"
#include "vertexOp.h"



Cube::Cube(glm::vec3 initialPostion, glm::vec3 v0, float mass, float length, float width, float height)
:AABBox(initialPostion.x, initialPostion.x + length, initialPostion.y, initialPostion.y + width, initialPostion.z, initialPostion.z + height),
serialNumber(Cube::cubeNum++)
{
	if (length <= 0.0)		length = 1.0;
	if (width <= 0.0)		width = 1.0;
	if (height <= 0.0)		height = 1.0;
	this->length = length;
	this->width = width;
	this->height = height;

	this->geoCenter.x = length / 2.0;
	this->geoCenter.y = width / 2.0;
	this->geoCenter.z = height / 2.0;

	this->position = initialPostion;

	this->v0 = v0;
	
	this->mass = mass;

	this->collision = false;
}
void Cube::render(Shader shader, GLuint VAO)
{
	shader.Use();

	glBindVertexArray(VAO);

	this->modelMatrix = glm::mat4();
	this->modelMatrix = glm::translate(this->modelMatrix, this->geoCenter);
	this->modelMatrix = glm::translate(this->modelMatrix, this->position);
	this->modelMatrix = glm::scale(this->modelMatrix, glm::vec3(length, width, height));
	glUniformMatrix4fv(glGetUniformLocation(shader.Program, "model"), 1, GL_FALSE, glm::value_ptr(this->modelMatrix));
	glDrawArrays(GL_TRIANGLES, 0, 36);

	glBindVertexArray(0);
}
void Cube::colliding()
{
	this->collision = true;
}
bool Cube::isCollision()
{
	return this->collision;
}
void Cube::initialize()
{
	this->collision = false;
}
GeneralCube::GeneralCube()
:VAO(generateCubeVAO())
{

}