#pragma once

#include "SceneNode.h"

namespace mjt
{
	class Scene
	{
	protected:
		SceneNode * m_rootNode;
		const char* m_name;

	public:
		Scene(const char* name);
		~Scene();

		virtual void init() = 0;
		virtual void update();
		virtual void render(ShaderProgram* shader, Camera* camera);

		virtual void move_camera(sf::Keyboard::Key input);
		virtual void move_camera(int x, int y);

		const char* getName();

		/*Node managment methods*/
		void addNode(SceneNode* node);
	};
}
