#include "BVolume.h"

AABBox::AABBox(float xMin, float xMax, float yMin, float yMax, float zMin, float zMax)
{
	this->xMax = xMax;
	this->xMin = xMin;
	this->yMax = yMax;
	this->yMin = yMin;
	this->zMax = zMax;
	this->zMin = zMin;
}