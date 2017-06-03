#ifndef POINT_LIGHT_H
#define POINT_LIGHT_H

#include "Light.h"

class PointLight : public Light
{
public:
	glm::vec3 position;
	PointLight();
	PointLight(glm::vec3 direction, glm::vec3 color, glm::vec3 position);
	~PointLight();
};

#endif