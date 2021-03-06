#ifndef SCENE_GRAPH_H_
#define SCENE_GRAPH_H_

#include <string>
#include <vector>
#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "scene_node.h"
#include "resource.h"
#include "camera.h"
#include "player.h"

namespace game {

    // Class that manages all the objects in a scene
    class SceneGraph {

        private:
            // Background color
            glm::vec3 background_color_;

            // Scene nodes to render
            std::vector<SceneNode *> node_;

			Player *player_;

        public:
            typedef std::vector<SceneNode *>::const_iterator const_iterator;

            SceneGraph(void);
            ~SceneGraph();

            // Background color
            void SetBackgroundColor(glm::vec3 color);
            glm::vec3 GetBackgroundColor(void) const;
            
            // Create a scene node from two resources
            SceneNode *CreateNode(std::string node_name, Resource *geometry, Resource *material, Resource *texture = NULL);
            // Add an already-created node
            void AddNode(SceneNode *node);
			void AddParticle(SceneNode* node);
			void AddPlayer(Player *player);
            // Find a scene node with a specific name
            SceneNode *GetNode(std::string node_name) const;
			Player *GetPlayer() const;
            // Get node const iterator
            std::vector<SceneNode *>::const_iterator begin() const;
            std::vector<SceneNode *>::const_iterator end() const;

            // Draw the entire scene
            void Draw(Camera *camera, glm::vec3);

            // Update entire scene
            void Update(double delta_time);
			void SetMaterial(Resource*);

    }; // class SceneGraph

} // namespace game

#endif // SCENE_GRAPH_H_
