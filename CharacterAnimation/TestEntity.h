#pragma once

#include "Entity.h"
#include "ColoredModel.h"

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
