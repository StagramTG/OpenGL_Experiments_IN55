#include "Scene.h"

namespace mjt
{
	Scene::Scene(const char* name): m_name(name)
	{
		m_rootNode = new SceneNode();
	}

	Scene::~Scene()
	{
		delete m_rootNode;
	}

	void Scene::update()
	{
		m_rootNode->update();
	}

	void Scene::render(ShaderProgram* shader, Camera* camera)
	{
		m_rootNode->render(shader, camera);
	}

	void Scene::move_camera(sf::Keyboard::Key input)
	{
		m_rootNode->move_camera(input);
	}

	void Scene::move_camera(int x, int y)
	{
		m_rootNode->move_camera(x, y);
	}

	const char * Scene::getName()
	{
		return m_name;
	}

	void Scene::addNode(SceneNode* node)
	{
		m_rootNode->addChild(node);
	}
}
