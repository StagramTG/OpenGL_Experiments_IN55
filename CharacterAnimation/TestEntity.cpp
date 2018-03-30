#include "TestEntity.h"

TestEntity::TestEntity(): mjt::Entity()
{
}

TestEntity::~TestEntity()
{
}

void TestEntity::update()
{
	setRotationY(m_rotY + 0.01f);
}

void TestEntity::render()
{
}
