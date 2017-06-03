#include <fstream>
#include <iostream>
#include <algorithm>
#include <glm/glm.hpp>
#include "Ray.h"
#include "Object.h"
#include "Sphere.h"
#include "Plane.h"
#include "Triangle.h"
#include <vector>
#include "Light.h"
#include "PointLight.h"
#include "DirectionalLight.h"

int height = 1000;
int width = 1000;

void main() {

	std::vector<Object*> objectList;
	objectList.push_back(new Triangle(glm::vec3(0, 3, -5), glm::vec3(-1.9, 1.2, -5), glm::vec3(1.9, 1.2, -5), glm::vec3(0.8, 0.0, 1.0)));
	objectList.push_back(new Sphere(glm::vec3(-5.5, 0, -15), glm::vec3(0.8, 0.8, 0.8), 3));
	objectList.push_back(new Sphere(glm::vec3(5, -1, -15), glm::vec3(0.9, 0.76, 0.46), 2));
	objectList.push_back(new Sphere(glm::vec3(0,0,-20), glm::vec3(1.0, 0.32, 0.36), 4));
	objectList.push_back(new Sphere(glm::vec3(5, 0, -25), glm::vec3(0.65, 0.77, 0.97), 3));
	objectList.push_back(new Plane(glm::vec3(0, -4, 0), glm::vec3(0, 1 , 0), glm::vec3(0.6, 0.2, 0.2)));

	std::vector<Light> lightList;
	//lightList.push_back(PointLight(glm::vec3(0, 0, 1), glm::vec3(1, 1, 1), glm::vec3(0, 0, 0)));
	lightList.push_back(DirectionalLight());

	//Directional Light
	glm::vec3 lightDir = glm::vec3(8, 1, 10);

	glm::vec3 **image = new glm::vec3*[width];
	for (int i = 0; i < width; i++) {
		image[i] = new glm::vec3[height];
	}

	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			float pixNormX = (i + 0.5) / width;
			float pixNormY = (j + 0.5) / height;
			float imageAspectRatio = width / height;
			float pixRemapX = (2 * pixNormX - 1) * imageAspectRatio;
			float pixRemapY = (1 - 2 * pixNormY);
			float pixCameraX = pixRemapX * glm::tan(glm::radians(90.0) / 2);
			float pixCameraY = pixRemapY * glm::tan(glm::radians(90.0) / 2);
			glm::vec3 PcameraSpace = glm::vec3(pixCameraX, pixCameraY, -1);
			glm::vec3 rayOrigin = glm::vec3(0, 0, 0);
			glm::vec3 rayDirection = PcameraSpace - rayOrigin;
			rayDirection = glm::normalize(rayDirection);
			Ray ray(rayOrigin, rayDirection);

			float t;
			float minT = INFINITY;

			image[i][j] = glm::vec3(1);

			for (int k = 0; k < objectList.size(); k++) {

				if (objectList[k]->intersection(ray, t)) {

					if (t < minT) {

						minT = t;

						glm::vec3 poi = ray.origin + t * ray.direction;
						int shininess;
						glm::vec3 diffuseColor = glm::vec3(1);
						glm::vec3 specularColor = glm::vec3(1);
						glm::vec3 ambientColor = glm::vec3(1);
						glm::vec3 normal = objectList[k]->calcNormal(poi);


						//Diffuse
						float diffuse = 1.0 * glm::dot(normal, glm::normalize(lightDir));
						diffuse = diffuse < 0 ? 0 : diffuse;

						//Ambient
						float ambient = 0.1;

						//specular
						glm::vec3 reflectDir = (2 * (glm::dot(normal, glm::normalize(lightDir))) * normal) - glm::normalize(lightDir);
						float specularConst = glm::max(0.0f, glm::dot(glm::normalize(reflectDir), glm::normalize(-ray.direction)));
						float specular = 1.0 * pow(specularConst, 32);

						float t0;
						int shadowObj = -1;

						for (int l = 0; l < objectList.size() && k!=l; ++l) {
							if (objectList[l]->intersection(Ray(poi + 1e-4f *normal, lightDir), t0)) {
								if (t0 < minT) {
									minT = t0;
									shadowObj = k;
								}
							}
						}
						if (shadowObj != -1) {
							image[i][j] = objectList[k]->color * (ambient);
						}
						else {
							image[i][j] = objectList[k]->color * (diffuse + ambient + specular);
						}
					}
				}
			}
		}
	}

	std::ofstream ofs("./untitled.ppm", std::ios::out | std::ios::binary);
	ofs << "P6\n" << width << ' ' << height << ' ' << "\n255\n";
	for (unsigned y = 0; y < height; y++) {
		for (unsigned x = 0; x < width; x++) {
			ofs << (unsigned char)(std::min((float)1, std::max((float)0,(float)image[x][y].x)) * 255) <<
				(unsigned char)(std::min((float)1, std::max((float)0, (float)image[x][y].y)) * 255) <<
				(unsigned char)(std::min((float)1, std::max((float)0, (float)image[x][y].z)) * 255);
		}
	}
	ofs.close();

}