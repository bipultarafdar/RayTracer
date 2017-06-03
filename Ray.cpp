#include "Ray.h"



Ray::Ray(glm::vec3 origin, glm::vec3 direction) : origin(origin), direction(glm::normalize(direction))
{
}


Ray::~Ray()
{
}
