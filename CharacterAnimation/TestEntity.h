#pragma once

#include "MJT/Entity.h"
#include "MJT/ColoredModel.h"

class TestEntity: public mjt::Entity
{
private:
	mjt::ColoredModel* model;

public:
	TestEntity();
	~TestEntity();

	void update() override;
	void render() override;
};
