#pragma once

namespace mjt
{
	class Model
	{
	private:
		int m_verticesCount;

	public:
		Model() {}
		~Model() {}

		virtual void render() = 0;
	};
}
