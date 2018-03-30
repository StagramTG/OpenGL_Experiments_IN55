#pragma once

#include "MJT/Entity.h"

class TestEntity: public mjt::Entity
{
private:

public:
	TestEntity();
	~TestEntity();

	void update() override;
	void render() override;
};
