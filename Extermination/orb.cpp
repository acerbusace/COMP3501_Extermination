#include <stdexcept>
#define GLM_FORCE_RADIANS
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <iostream>

#include "orb.h"
#include "laser.h"
//#include "misc.h"

namespace game {

	//extern ResourceManager resman;

Orb::Orb(std::string name, Resource *geometry, Resource *material, Resource *texture) : SceneNode(name, geometry, material, texture) {
	fire_error_ = 25.0;
	laser_speed_ = 5.0;
	fire_speed_ = 10.0;
}


Orb::~Orb(){
}

void Orb::Update(double delta_time){
	fire_cooldown_ -= delta_time;
}

float Orb::fireError() {
	return fire_error_*((float) rand()/RAND_MAX) - fire_error_ / 2.0;
}

float Orb::getLaserSpeed() {
	return laser_speed_;
}

float Orb::getFireSpeed() {
	return fire_speed_;
}

bool Orb::shoot() {
	if (fire_cooldown_ < 0) {
		fireCoolDown();
		return true;
	}
	return false;
}

void Orb::setLaserSpeed(float speed) {
	laser_speed_ = speed;
}

void Orb::setFireSpeed(float speed) {
	fire_speed_ = speed;
}

void Orb::setFireError(float error) {
	fire_error_ = error;
}

void Orb::fireCoolDown() {
	fire_cooldown_ = fire_speed_;
}
            
} // namespace game
