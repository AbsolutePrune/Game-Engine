#pragma once
#include "Resource.h"
#include <rend/rend.h>
#include <memory>

namespace myengine
{
	/// @brief Texture resource 
	struct Texture : Resource
	{
		/// @brief Used to give a rend::Texture to triangle renderer
		/// @return 
		std::shared_ptr<rend::Texture> internalTexture();

	private:

		/// @brief redefinition of virtual onLoad from resource
		void onLoad();

		std::shared_ptr<rend::Texture> m_texture; ///< Shared pointer to a rend::Texture
	};
}