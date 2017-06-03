#include "DirectionalLight.h"



DirectionalLight::DirectionalLight() :
	Light(glm::vec3(0, 0, 1), glm::vec3(1))
{
}

DirectionalLight::DirectionalLight(glm::vec3 direction, glm::vec3 color) : 
	Light(direction, color) {}


DirectionalLight::~DirectionalLight()
{
}
