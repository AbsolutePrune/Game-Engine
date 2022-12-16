#include <memory>
#include "Resource.h"
#include <vector>


namespace myengine
{
	struct Core;

	struct ResourceList
	{
		template <typename T>
		std::shared_ptr<T> load(const std::string& _path)
		{
			std::shared_ptr<T> rtn = std::make_shared<T>();
			rtn->m_resources = m_self;
			rtn->m_path = _path;

			m_resources.push_back(rtn);

			rtn->load();

			return rtn;
		};

	private:
		std::weak_ptr<ResourceList> m_self;
		std::vector<std::shared_ptr<Resource> > m_resources;
		std::weak_ptr<Core> m_core;
	};
}