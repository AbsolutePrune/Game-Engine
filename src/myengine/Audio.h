#include "Resource.h"
#include <rend/rend.h>

namespace myengine
{
	struct Audio : Resource
	{
		void onCreate(int _width, int _height);

	private:

		void onLoad();

	};
}