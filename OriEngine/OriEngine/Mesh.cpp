#include "Mesh.h"


using namespace OriEngine;

Mesh::Mesh(std::vector<Vertex> vertices, std::vector<GLuint> indices)
{
	loadMesh(vertices, indices);
}

Mesh::~Mesh()
{
}

void Mesh::loadMesh(std::vector<Vertex> _vertices, std::vector<GLuint> _indices)
{
	vertices = _vertices;
	indices = _indices;
	for (int i = 0; i < vertices.size(); i++) {
	//	vertices.at(i).Position = VMath::normalize(vertices.at(i).Position);
	//	vertices.at(i).Normal = VMath::normalize(VMath::cross(vertices.at(i).Position - vertices.at(i +1).Position,vertices.at(i + 3).Position - vertices.at(i).Position) );
	}
	
	
	setupMesh();
}

void Mesh::Draw()
{
	// Draw mesh
	glBindVertexArray(VAO);
	glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
}

void Mesh::setupMesh()

{
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);

	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex),&vertices.at(0).Position[0], GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(GLuint),&indices[0], GL_STATIC_DRAW);

	// Vertex Positions
	glEnableVertexAttribArray(Shader::VERTEX_ATTRIB);
	glVertexAttribPointer(Shader::VERTEX_ATTRIB, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex),(GLvoid*)offsetof(Vertex,Position[0]));
	// Vertex Normals
	glEnableVertexAttribArray(Shader::NORMAL_ATTRIB);
	glVertexAttribPointer(Shader::NORMAL_ATTRIB, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex),(GLvoid*)offsetof(Vertex, Normal[0]));
	// Vertex Texture Coords


	glBindVertexArray(0);
}