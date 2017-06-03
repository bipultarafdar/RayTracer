#ifndef OBJECT_H
#define OBJECT_H

#include <glm/glm.hpp>
#include "Ray.h"


class Object
{
public:
	glm::vec3 position;
	glm::vec3 color;
	glm::vec3 normal;

	Object();
	Object(glm::vec3 position, glm::vec3 color);
	virtual bool intersection(Ray ray, float& t);
	virtual glm::vec3 calcNormal(glm::vec3 poi);
	~Object();
};

#endif // !OBJECT_H

