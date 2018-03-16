#pragma once

#include <vector>
#include "BufferObject.h"

namespace mjt
{
	class VertexBufferObject: public BufferObject
	{
	private:

	public:
		VertexBufferObject();
		~VertexBufferObject();

		void setData(std::vector<GLfloat> data);
	};
}
