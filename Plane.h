#ifndef PLANE_H
#define PLANE_H
#include "Object.h"

class Plane : public Object
{
public:
	Plane();
	Plane(glm::vec3 position, glm::vec3 normal, glm::vec3 color);
	~Plane();

	bool intersection(Ray ray, float& t);
};

#endif

