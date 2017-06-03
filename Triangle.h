#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Object.h"

class Triangle : public Object
{
public:
	glm::vec3 a, b, c;

	Triangle();
	Triangle(glm::vec3 a, glm::vec3 b, glm::vec3 c, glm::vec3 color);
	~Triangle();
	bool intersection(Ray ray, float& t);
	virtual glm::vec3 calcNormal(glm::vec3 poi);
};

#endif
