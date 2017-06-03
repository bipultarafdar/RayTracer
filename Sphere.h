#ifndef SPHERE_H
#define SPHERE_H

#include <glm/glm.hpp>
#include "Ray.h"
#include "Object.h"


class Sphere : public Object
{
public:
	float radius;

	Sphere();
	Sphere(glm::vec3 center, glm::vec3 color, float radius);
	bool intersection(Ray ray, float& t);
	glm::vec3 calcNormal(glm::vec3 poi);
	~Sphere();
};

#endif // !SPHERE_H

