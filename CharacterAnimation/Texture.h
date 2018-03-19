#pragma once

namespace mjt
{
	class Texture
	{
	private:

	public:
		Texture(const char* file);
		~Texture();

		void bind();
		void unbind();
	};
}