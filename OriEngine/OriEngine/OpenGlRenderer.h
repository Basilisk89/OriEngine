#ifndef OPENGLRENDERER_H
#define OPENGLRENDERER_H
#include "AbstractRenderer.h"
namespace OriEngine {
	class OpenGlRenderer : public AbstractRenderer {
	public:
		enum PrimativeType {};
		OpenGlRenderer();
		~OpenGlRenderer();
		virtual void init();
		virtual void versionInfo();
		virtual void drawPrimative();
	};
}
#endif

