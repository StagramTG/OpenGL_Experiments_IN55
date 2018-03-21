#pragma once

#include <vector>
#include "BufferObject.h"

namespace mjt
{
	class IndicesBufferObject: public BufferObject
	{
	private:

	public:
		IndicesBufferObject();
		~IndicesBufferObject();

		void setData(std::vector<GLuint> data);
	};
}
