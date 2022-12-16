#ifndef MYENGINE_RESOURCE_H
#define MYENGINE_RESOURCE_H
#include <string>
#include <memory>



namespace myengine

{
	struct ResourceList;

	struct Resource
	{
		virtual void onLoad();

		virtual void onCreate();

		std::string getPath() const;

	private:
		
		void load();
		
		std::string m_path;

		std::weak_ptr<ResourceList> m_resources;
	};
}

#endif