#include "Scene.h"

namespace mjt
{
	Scene::Scene()
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

	void Scene::render()
	{
		m_rootNode->render();
	}
}
