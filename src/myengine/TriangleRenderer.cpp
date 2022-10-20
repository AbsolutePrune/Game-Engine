#include "TriangleRenderer.h"

namespace myengine
{
	TriangleRenderer::TriangleRenderer():
		m_shader("data/shaders/basic.vert", "data/shaders/basic.frag")
	{
		m_mesh.loadQuad();
	}

	void TriangleRenderer::onDisplay()
	{
		rend::Renderer r(640, 480);

		r.shader(&m_shader);
		r.mesh(&m_mesh);

		r.render();
	}
}