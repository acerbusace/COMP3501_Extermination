#ifndef MISSILE_H_
#define MISSILE_H_

#include <string>
#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#define GLM_FORCE_RADIANS
#include <glm/gtc/quaternion.hpp>

#include "resource.h"
#include "scene_node.h"

namespace game {

    // Abstraction of a missile
    class Missile : public SceneNode {

        public:
            // Create missile from given resources
            Missile(std::string name, Resource *geometry, Resource *material, Resource *texture = 0);

            // Destructor
            ~Missile();
            
            void Update(double);
			bool done();

			void SetSpeed(float);
			void SetInitPos(glm::vec3);
			void setPoints(glm::vec3 forward, glm::vec3 up);
			std::vector<glm::vec3> GetMissilePoints();
            
        private:
			glm::mat4 getTransf();
			glm::vec3 init_pos_;
			glm::vec3 point1_;
			glm::vec3 point2_;
			glm::vec3 point3_;
			glm::vec3 point4_;
			glm::vec3 Bt;
			glm::vec3 prevBt;
			float t;
			float speed_;
    };

} // namespace game

#endif
