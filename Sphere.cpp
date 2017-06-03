#include "Sphere.h"



Sphere::Sphere()
{
	position = glm::vec3(0);
	color = glm::vec3(0);
	radius = 0;
}

Sphere
::Sphere(glm::vec3 center, glm::vec3 color_sphere, float radius_sphere){
	position = center;
	color = color_sphere;
	radius = radius_sphere;
}


bool
Sphere
::intersection(Ray ray, float& t) {
	glm::vec3 r = position - ray.origin;
	float tca = dot(r, ray.direction);
	if (tca < 0) {
		return false;
	}
	else {
		double c = dot(r, r) - radius*radius;
		double dist = tca * tca -  c;
		if (dist < 0) {
			return false;
		}
		else {
			dist = sqrt(dist);
			double t0 = tca + dist;
			double t1 = tca - dist;
			t = (t0 < t1) ? t0 : t1;
			return true;
		}
	}
}

glm::vec3 
Sphere::calcNormal(glm::vec3 poi) {
	return glm::normalize(poi - position);
}

Sphere::~Sphere()
{
}
