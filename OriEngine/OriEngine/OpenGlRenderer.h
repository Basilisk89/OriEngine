#ifndef OPENGLRENDERER_H
#define OPENGLRENDERER_H
#include "AbstractRenderer.h"
#include "ShaderManager.h"
#include "GLTexture.h"
namespace OriEngine {
	class OpenGlRenderer : public AbstractRenderer {
	public:
		enum PrimativeType {};
		OpenGlRenderer();
		~OpenGlRenderer();
		virtual void init();
		virtual void versionInfo();
		virtual void drawPrimative();
		int winHeight;
		int winWidth;
		GLuint TextureID;
		GLuint vao, vbo;
		GLTexture texture;
	};
	class OpenGLRendererBuilder :public AbstractRenderer {
	public:
		virtual AbstractRenderer* createRenderer();
	};
}
#endif

