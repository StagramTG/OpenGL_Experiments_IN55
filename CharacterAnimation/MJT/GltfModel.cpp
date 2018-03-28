#include "GltfModel.h"

#include <iostream>

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

		std::cout << "POSITION : " << mesh.primitives[0].attributes["POSITION"] << std::endl;
		std::cout << "TEX : " << mesh.primitives[0].attributes["TEXCOORD_0"] << std::endl;
		std::cout << "NORMAL : " << mesh.primitives[0].attributes["NORMAL"] << std::endl;
		std::cout << "INDICES : " << mesh.primitives[0].indices << std::endl;

		/*Setup VAO with model data*/
		vao = new VertexArrayObject();
		vao->bind();

		vao->enableAttribArray(0);

		vbo = new VertexBufferObject();
		vbo->bind();
		
		GLfloat v_data[1];
	}

	GltfModel::~GltfModel()
	{
		delete vbo;
		//delete uvs;
		//delete normal;
		//delete indices;

		delete vao;
	}

	void GltfModel::render()
	{
	}
}
