#include "Light.h"


Light::Light()
{
}

Light::Light(glm::vec3 direction, glm::vec3 color) :
	direction(direction), color(color) {}


Light::~Light()
{
}
