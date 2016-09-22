#include "OpenGlRenderer.h"
#include <glut-3.7.6\include\GL\glut.h>
using namespace OriEngine;

OpenGlRenderer::OpenGlRenderer(){
	
}
OpenGlRenderer::~OpenGlRenderer(){
}
void OpenGlRenderer::drawPrimative() {
	float verts[] = { 0.0, 0.5, 0.0, -0.5, -0.5, 0, 0.5, -0.5, 0.0 };	// default CCW winding

		GLuint vao, vbo;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	
		glBufferData(GL_ARRAY_BUFFER, 3 * sizeof(float), verts, GL_STATIC_DRAW);
	
		glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	
		glDrawArrays(GL_TRIANGLES, 0, 3);

}
void OpenGlRenderer::init() {
	glewExperimental = true;
	
	DebugLogger::getInstance().log(DebugLogger::INFO, "AbstractEngine", "getInstance", __FILE__, __LINE__, "Engine Started");

	
	versionInfo();
}
void OpenGlRenderer::versionInfo() {
	/// You can (and probably need) to get some info regarding versions and manufacturer
	const GLubyte *version = glGetString(GL_VERSION);
	/// You can also get the version as ints
	GLint major, minor;
	glGetIntegerv(GL_MAJOR_VERSION, &major);
	glGetIntegerv(GL_MINOR_VERSION, &minor);
	const GLubyte *vendor = glGetString(GL_VENDOR);
	const GLubyte *renderer = glGetString(GL_RENDERER);
	const GLubyte *glslVersion = glGetString(GL_SHADING_LANGUAGE_VERSION);

	printf("GL Version - %s\n", version);
	printf("GL Version - %d.%d\n", major, minor);
	printf("Graphics card vendor - %s\n", vendor);
	printf("Graphics card name - %s\n", renderer);
	printf("GLSL Version - %s\n", glslVersion);
}