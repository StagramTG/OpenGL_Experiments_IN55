#include "AmbiantLight.h"

mjt::AmbiantLight::AmbiantLight(AmbiantLightData data):
	m_data(data)
{
}

mjt::AmbiantLight::~AmbiantLight()
{
}

GLfloat mjt::AmbiantLight::getIntensity()
{
	return m_data.intensity;
}

glm::vec3 mjt::AmbiantLight::getColor()
{
	return m_data.color;
}

void mjt::AmbiantLight::setIntensity(GLfloat intensity)
{
	m_data.intensity = intensity;
}

void mjt::AmbiantLight::setColor(glm::vec3 color)
{
	m_data.color = color;
}
