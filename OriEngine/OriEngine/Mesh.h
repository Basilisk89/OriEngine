#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>

// GL Includes
#include "OpenGlRenderer.h"// Contains all the necessery OpenGL includes
#include "VMath.h"
#include "Shader.h"	

namespace OriEngine {
	struct Vertex {
		// Position
		Vec3 Position;
		// Normal
		Vec4 Normal;
		// TexCoords
		Vec2 TexCoords;
		//Colour
		Vec4 Colour;
	};
	class Mesh {
	public:
		/*  Mesh Data  */
		std::vector<Vertex> vertices;
		std::vector<GLuint> indices;
		

		/*  Functions  */
		// Constructor
		Mesh(std::vector<Vertex> vertices, std::vector<GLuint> indices);
		
		~Mesh();
		// Render the mesh
		void loadMesh(std::vector<Vertex> _vertices, std::vector<GLuint> _indices);
		void Draw();
		

	private:
		/*  Render data  */
		GLuint VAO, VBO, EBO;

		/*  Functions    */
		// Initializes all the buffer objects/arrays
		void setupMesh();
	
	};
}