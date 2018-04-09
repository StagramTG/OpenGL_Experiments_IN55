#pragma once

#include <glm/vec2.hpp>

namespace mjt
{
	namespace gui
	{
		struct Glyph
		{
			glm::vec2 texPosition;
			glm::vec2 size;
			glm::vec2 bearing;
			unsigned int advance;
		};
	}
}