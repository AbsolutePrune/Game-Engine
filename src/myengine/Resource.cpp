#include "Resource.h"

namespace myengine
{
	void Resource::onLoad()
	{

	}

	/*void Resource::onCreate()
	{

	}*/

	std::string Resource::getPath() const
	{
		return m_path;
	}

	void Resource::load()
	{
		onLoad();
	}
}