#include "GltfModel.h"

#include <iostream>
#include <string>

namespace mjt
{
	GltfModel::GltfModel(const char* file): Model(GL_TRIANGLES)
	{
		asset = gltf2::load(file);

		/*Get data*/
		gltf2::Node node = asset.nodes[1];
		gltf2::Mesh mesh = asset.meshes[node.mesh];

		gltf2::Accessor accessor_pos = asset.accessors[mesh.primitives[0].attributes["POSITION"]];
		gltf2::Accessor accessor_uvs = asset.accessors[mesh.primitives[0].attributes["TEXCOORD_0"]];
		gltf2::Accessor accessor_nor = asset.accessors[mesh.primitives[0].attributes["NORMAL"]];
		
		gltf2::Accessor accessor_ind = asset.accessors[mesh.primitives[0].indices];

		gltf2::BufferView bufferView = asset.bufferViews[accessor_ind.bufferView];
		gltf2::Buffer buffer = asset.buffers[bufferView.buffer];
	}

	GltfModel::~GltfModel()
	{
		//delete vbo;
		//delete uvs;
		//delete normal;
		//delete indices;

		//delete vao;
	}

	void GltfModel::render(ShaderProgram* shader, Camera* camera)
	{
	}
}
