#include "Entity.h"
#include "Component.h"
#include <iostream>
#include <exception>

namespace myengine
{
	void Entity::tick() 
	{
		try
		{
			if (m_alive)
			{
				for (std::list<std::shared_ptr<Component> >::iterator it = m_components.begin();
					it != m_components.end();
					it++)
				{
					if ((*it)->m_alive)
					{
						(*it)->tick();
					}
				}

				for (std::list<std::shared_ptr<Component> >::iterator it = m_components.begin();
					it != m_components.end();
					//it++
					)
				{
					if (!(*it)->m_alive)
					{
						it = m_components.erase(it);
						std::cout << "erased component in tick" << std::endl;
					}
					else {

						++it;
					}
				}
			}
		}
		catch (std::exception& e)
		{
			kill();
		}
	}

	void Entity::display() 
	{
		if (m_alive)
		{

			for (std::list<std::shared_ptr<Component> >::iterator it = m_components.begin();
				it != m_components.end();
				it++)
			{
				if ((*it)->m_alive)
				{
					(*it)->display();
				}
			}
		}
	}

	void Entity::kill()
	{
		if (!m_alive)
		{
			return;
		}
		

		for (std::list<std::shared_ptr<Component> >::iterator it = m_components.begin();
			it != m_components.end();
			it++
			)
		{
			(*it)->kill();
			/*std::list<std::shared_ptr<Component> >::iterator pos = m_components.erase(it);
			it = pos;*/
		}

		m_alive = false;
	}

	void Entity::erase()
	{
		for (std::list<std::shared_ptr<Component> >::iterator it = m_components.begin();
			it != m_components.end();
			//it++
			)
		{
			//(*it)->kill();
			std::list<std::shared_ptr<Component> >::iterator pos = m_components.erase(it);
			std::cout << "erased component" << std::endl;
			it = pos;
		}
	}

	
	std::shared_ptr<Core> Entity::getCore()
	{
		return m_core.lock();
	}

	std::shared_ptr<Transform> Entity::getTransform()
	{
		return m_transform.lock();
	}
}