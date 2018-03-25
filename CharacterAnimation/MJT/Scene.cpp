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

	void Scene::render()
	{
		m_rootNode->render();
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
