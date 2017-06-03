#include "Plane.h"



Plane::Plane()
{
	position = glm::vec3(0);
	color = glm::vec3(0);
	normal = glm::vec3(0);
}

Plane::
Plane(glm::vec3 position_plane, glm::vec3 normal_plane, glm::vec3 color_plane) {
	position = position_plane;
	color = color_plane;
	normal = normal_plane;
}

bool
Plane::intersection(Ray ray, float& t) {
	float vd = glm::dot(normal, ray.direction);
	if (vd >= 0) return false;
	double v0 = -(dot(normal, ray.origin) + glm::length(position));
	t = v0 / vd;
	if (t < 0) return false;
	return true;
}


Plane::~Plane()
{
}
