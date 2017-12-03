#ifndef MISC_H_
#define MISC_H_

#include "laser.h"
#include "resource_manager.h"

namespace game {
<<<<<<< HEAD
	Resource *getResource(ResourceManager *resman, std::string name) {
		Resource *res = resman->GetResource(name);
		if (!res) {
			throw(std::string("Could not find resource \"") + name + std::string("\""));
		}
		return res;
	}

	Laser *createLaserInstance(ResourceManager *resman) {
		Resource *geom = getResource(resman, "LaserMesh");
		Resource *mat = getResource(resman, "ShinyTextureMaterial");
		Resource *tex = resman->GetResource("window");
=======
	Resource *getResource(ResourceManager *resman, std::string name);
>>>>>>> dev-v2

	Laser *createLaserInstance(ResourceManager *resman);
}

#endif