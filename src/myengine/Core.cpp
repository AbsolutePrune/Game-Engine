#include "Core.h"
#include "Entity.h"

namespace myengine 
{

	std::shared_ptr<Core> Core::initialize()
	{
		std::shared_ptr<Core> rtn = std::make_shared<Core>();

		return rtn;
	}

	void Core::start() {
		m_running = true;

		while (m_running) {
			for (std::list<std::shared_ptr<Entity> >::iterator it = m_entities.begin();
				it != m_entities.end();
				it++)
			{
				(*it)->tick();
			}
		}
	}

	void Core::stop() {
		m_running = false;
	}

	std::shared_ptr<Entity> Core::addEntity() {
		std::shared_ptr<Entity> rtn = std::make_shared<Entity>();

		m_entities.push_back(rtn);

		return rtn;
	}
}