#include "BVolume.h"


BSphere::BSphere(float radius, glm::vec3 center)
{
	this->radius = radius;
	this->center = center;
}
void BSphere::setBScenter(glm::vec3 newCenter)
{
	this->center = newCenter;
}
float BSphere::getRadius()
{
	return this->radius;
}
glm::vec3 BSphere::getCenter()
{
	return this->center;
}
bool BSphere::collisionTest(AABBox aabb)
{
	//run AABB collision test!
	/*
	float xMin = this->center.x - this->radius;
	float xMax = this->center.x + this->radius;
	float yMin = this->center.y - this->radius;
	float yMax = this->center.y + this->radius;
	float zMin = this->center.z - this->radius;
	float zMax = this->center.z + this->radius;*/

	float xMin = getAABB_posMin().x;
	float xMax = getAABB_posMax().x;
	float yMin = getAABB_posMin().y;
	float yMax = getAABB_posMax().y;
	float zMin = getAABB_posMin().z;
	float zMax = getAABB_posMax().z;

	if (
		( (aabb.xMin < xMin && xMin < aabb.xMax) && (aabb.yMin < yMin && yMin < aabb.yMax) && (aabb.zMin < zMin && zMin < aabb.zMax) ) ||
		( (aabb.xMin < xMax && xMax < aabb.xMax) && (aabb.yMin < yMax && yMax < aabb.yMax) && (aabb.zMin < zMax && zMax < aabb.zMax) ) )
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool BSphere::collisionTest(BSphere bs)
{
	//distance^2 = (Acenter - Bcenter) dot (Acenter - Bcenter)
	float distance2 = glm::dot(this->center - bs.getCenter(), this->center - bs.getCenter());
	float radiusSum = this->radius + bs.getRadius();
	if (distance2 <= radiusSum * radiusSum)
		return true;
	else return false;
}
glm::vec3 BSphere::getAABB_posMin()
{
	float xMin = this->center.x - this->radius;
	float yMin = this->center.y - this->radius;
	float zMin = this->center.z - this->radius;

	return glm::vec3(xMin, yMin, zMin);
}
glm::vec3 BSphere::getAABB_posMax()
{
	float xMax = this->center.x + this->radius;
	float yMax = this->center.y + this->radius;
	float zMax = this->center.z + this->radius;

	return glm::vec3(xMax, yMax, zMax);
}
