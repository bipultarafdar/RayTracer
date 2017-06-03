#include "Triangle.h"



Triangle::Triangle()
{
	a = glm::vec3(0);
	b = glm::vec3(0);
	c = glm::vec3(0);
}

Triangle::
Triangle(glm::vec3 a_tri, glm::vec3 b_tri, glm::vec3 c_tri, glm::vec3 color_tri) {
	a = a_tri;
	b = b_tri;
	c = c_tri;
	color = color_tri;
}

bool
Triangle::
intersection(Ray ray, float& t) {
	glm::vec3 e1 = b - a;
	glm::vec3 e2 = c - a;
	float denom = glm::dot(e1, glm::cross(ray.direction, e2));
	float u = glm::dot((ray.origin - a), glm::cross(ray.direction, e2)) / denom;
	float v = glm::dot(ray.direction, (glm::cross(ray.origin - a, e1)) / denom);

	if (u < 0 || u > 1) {
		return false;
	}
	else if (v < 0 || u + v > 1) {
		return false;
	}
	else {
		float t0 = glm::dot(e2, glm::cross(ray.origin - a, e1)) / glm::dot(e1, glm::cross(ray.direction, e2));
		t = t0;
		return true;
	}

}

glm::vec3 
Triangle::calcNormal(glm::vec3 poi) {
	return glm::normalize(glm::cross(b - a, c - a));
}


Triangle::~Triangle()
{
}
