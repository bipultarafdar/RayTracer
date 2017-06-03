#ifndef LIGHT_H
#define LIGHT_H

#include "glm\glm.hpp"

class Light 
{
public:
	glm::vec3 direction;
	glm::vec3 color;
	Light();
	Light(glm::vec3 direction, glm::vec3 color);
	~Light();
};
#endif
