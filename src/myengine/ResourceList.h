#include <memory>
#include "Resource.h"
#include <vector>


namespace myengine
{
	struct Core;

	/// @brief An array of all the resources that have been loaded
	struct ResourceList
	{
		/// @brief loads the specified file by its path
		/// @tparam T The type of resource to be loaded
		/// @param _path The file path of the resource
		/// @return A shared pointer to the loaded resource
		template <typename T>
		std::shared_ptr<T> load(const std::string& _path)
		{
			// checks if the resource has been loaded already
			for (std::vector<std::shared_ptr<Resource> >::iterator it = m_resources.begin();
				it != m_resources.end();
				it++)
			{
				if ((*it)->getPath() == _path)
				{
					// if resource is already been loaded return the resource rather than load it again
					return std::dynamic_pointer_cast<T>(*it);
				}
			}

			// if the resource hasnt been loaded yet
			std::shared_ptr<T> rtn = std::make_shared<T>();
			// give it a reference to the resource list
			rtn->m_resources = m_self;
			// set its path as the given path (_path)
			rtn->m_path = _path;

			// push it into the array of resources so if it is called again it can be found there rather than loaded
			m_resources.push_back(rtn);

			// calls load on the resource
			rtn->load();

			// returns the resource
			return rtn;
		};

	private:
		std::weak_ptr<ResourceList> m_self; ///< weak pointer to itself - used to give reference to created resources
		std::vector<std::shared_ptr<Resource> > m_resources; ///< a vector of the loaded resources
		std::weak_ptr<Core> m_core; ///< weak pointer to core
	};
}