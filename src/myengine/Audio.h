#include "Resource.h"


namespace myengine
{
	/// @brief Audio resource
	struct Audio : Resource
	{

	private:
		/// @brief redefinition of virtual onLoad from Resource
		void onLoad();


	};
}