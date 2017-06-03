#include "PointLight.h"



PointLight::PointLight()
{
	direction = glm::vec3(0, 0, 1);
	position = glm::vec3(0);
	color = glm::vec3(0);
}

PointLight::PointLight(glm::vec3 direction, glm::vec3 color, glm::vec3 position) :
	Light(direction, color), position(position) {};


PointLight::~PointLight()
{
}
