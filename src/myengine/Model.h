#pragma once
#include "Resource.h"
#include <rend/rend.h>
#include <memory>

namespace myengine
{
	/// @brief Model/mesh resource 
	struct Model : Resource
	{

	private:

		/// @brief redefinition of Resource virtual onLoad
		void onLoad();

		std::shared_ptr<rend::Model> m_model; ///< shared pointer to a rend::Model
	};
}