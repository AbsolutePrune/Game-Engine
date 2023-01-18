#include "Component.h"
#include <rend/rend.h>

namespace myengine
{

	struct Texture;
	struct Model;

	/// @brief TriangleRenderer Component used to draw objects
	struct TriangleRenderer : Component
	{
		/// @brief Sets frag and vert shaders as well as a placeholder m_mesh which gets overwritten
		TriangleRenderer();

		/// @brief Sets the objects texture
		/// @param _tex The texture to set
		void setTexture(std::shared_ptr<Texture> _tex);

		/// @brief Sets the objects mesh/model
		/// @param _model The model to set 
		void setModel(std::shared_ptr<Model> _model);

	private:
		rend::Mesh m_mesh; ///< A rend::Mesh
		rend::Shader m_shader; ///< a rend::Shader
		std::shared_ptr<Texture> m_texture; ///< A shared pointer to myengine::Texture
		std::shared_ptr<Model> m_model; ///< A shared pointer to myengine::Model


		/// @brief redefinition of virtual onDisplay from Component
		void onDisplay();
		
		
	};
}