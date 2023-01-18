#include "TriangleRenderer.h"
#include "Entity.h"
#include "Transform.h"
#include "Texture.h"
#include "Model.h"

namespace myengine
{

	TriangleRenderer::TriangleRenderer():
		m_shader("../data/shaders/basic.vert", "../data/shaders/basic.frag")
	{
		
		m_mesh.loadTriangle();
		//m_mesh.load("../data/models/curuthers/curuthers.obj");
	}

	void TriangleRenderer::onDisplay()
	{
		rend::Renderer r(640, 480);

		r.shader(&m_shader);

		r.mesh(&m_mesh);
		r.texture(m_texture->internalTexture().get());

		r.projection(rend::perspective(rend::radians(45.0f), 1.0f, 0.1f, 100.0f));
		r.model(getEntity()->getTransform()->getModel());
		r.backfaceCull(true);
		r.depthTest(true);

		r.render();
	}

	void TriangleRenderer::setTexture(std::shared_ptr<Texture> _tex)
	{
		m_texture = _tex;
	}

	void TriangleRenderer::setModel(std::shared_ptr<Model> _model)
	{
		m_model = _model;
		m_mesh.load(m_model->getPath().c_str());
	}
}