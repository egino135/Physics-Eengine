#pragma once

#include <glm/glm.hpp>


//Bounding Volume 
class BSphere;
class AABBox;

//Bounding Sphere (BS).
class BSphere
{
public:
	BSphere(float radius, glm::vec3 center);
	bool collisionTest(AABBox aabb);
	bool collisionTest(BSphere bs);
	void setBScenter(glm::vec3 newCenter);
	float getRadius();
	glm::vec3 getCenter();
	glm::vec3 getAABB_posMin();
	glm::vec3 getAABB_posMax();
private:
	float radius;
	glm::vec3 center;	//define in world space
};

//Axis Aligned Bounding Box (AABB)
class AABBox
{
public:
	AABBox(float xMax, float xMin, float yMax, float yMin, float zMax, float zMin);
	float xMax, xMin;
	float yMax, yMin;
	float zMax, zMin;
private:
};
