#pragma once

#include "Model.h"
#include "VertexArrayObject.h"
#include "VertexBufferObject.h"
#include "IndicesBufferObject.h"

#include "GLTF2/gltf2Loader.h"

namespace mjt 
{
	class GltfModel: public Model
	{
	private:
		gltf2::Asset asset;

		VertexArrayObject* vao;
		VertexBufferObject* vbo;
		VertexBufferObject* normal;
		VertexBufferObject* uvs;
		IndicesBufferObject* indices;

	public:
		GltfModel(const char* file);
		~GltfModel();

		void render(ShaderProgram* shader, Camera* camera) override;
	};
}
