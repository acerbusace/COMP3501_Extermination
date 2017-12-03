#ifndef TANK_CONTROL_H_
#define TANK_CONTROL_H_

#include <string>
#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#define GLM_FORCE_RADIANS
#include <glm/gtc/quaternion.hpp>
#include <vector>

#include "resource.h"
#include "scene_node.h"
#include "tank.h"
#include "camera.h"
#include "laser.h"

namespace game {

    class TankControl {

        public:
            // Create asteroid from given resources
			TankControl(ResourceManager*);
			void init();

            // Destructor
            ~TankControl();

            // Update geometry configuration
            void update(double, glm::vec3 player_pos);
			// Update geometry configuration
			void draw(Camera*);
            
        private:
			ResourceManager *resman_;

			std::vector<Tank*> tanks_;
			std::vector<Laser*> lasers_;

			Tank *createTankInstance(glm::vec3);
			void shoot(Tank*, glm::vec3);
			void move(Tank*, glm::vec3);

			bool test;
    };

} // namespace game

#endif