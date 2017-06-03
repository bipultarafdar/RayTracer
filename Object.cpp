#include "Object.h"



Object::Object()
{
	position = glm::vec3(0);
	color = glm::vec3(0);
}

Object
::Object(glm::vec3 position, glm::vec3 color) : position(position), color(color) {}

bool
Object::intersection(Ray ray, float& t) {
	return false;
}

glm::vec3
Object::calcNormal(glm::vec3 poi) {
	return normalize(normal);
}

Object::~Object()
{
}
