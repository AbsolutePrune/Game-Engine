#ifndef MYENGINE_RESOURCE_H
#define MYENGINE_RESOURCE_H
#include <string>
#include <memory>
#include <vector>


namespace myengine

{
	struct ResourceList;

	/// @brief Parent struct for other resource types
	struct Resource
	{
		/// @brief virtual function to be redefined by child resources
		virtual void onLoad();

		// unused onCreate function - would be a virtual function to be redefined by child structs
		//virtual void onCreate();

		/// @brief Gets resources path
		/// @return Returns resources path
		std::string getPath() const;

	private:
		/// @brief allows ResourceList to call the resource load
		friend struct ResourceList;

		/// @brief calls onLoad
		void load();
		
		std::string m_path; ///< string that holds the resources path

		std::weak_ptr<ResourceList> m_resources; ///< weak pointer to ResourceList
	};
}

#endif