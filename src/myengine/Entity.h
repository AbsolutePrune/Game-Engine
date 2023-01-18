#pragma once
#include <list>
#include <memory>

namespace myengine
{
	struct Component;
	struct Core;
	struct Transform;

	/// @brief Base gameobject to attach components to
	struct Entity
	{
		/// @brief Creates a component of type T and pushes it into this entities list of components
		/// @tparam T The component type to return
		/// @return Returns a shared pointer of type T
		template <typename T>
		std::shared_ptr<T> addComponent()
		{
			std::shared_ptr<T> rtn = std::make_shared<T>();

			rtn->m_alive = true;
			rtn->m_entity = m_self;
			m_components.push_back(rtn);

			return rtn;
		}

		/// @brief Checks m_components for a component of type T
		/// @tparam T The component type to get and return
		/// @return A shared pointer of type T
		template <typename T>
		std::shared_ptr<T> getComponent()
		{
			for (std::list<std::shared_ptr<Component> >::iterator it = m_components.begin();
				it != m_components.end();
				it++)
			{
				std::shared_ptr<T> rtn = std::dynamic_pointer_cast<T>(*it);
				if (rtn)
				{
					return rtn;
				}
			}
			throw std::runtime_error("cannot find specified component");
		}

		/// @brief Sets m_alive to false which will cause the entity and its components to be removed from the scene on the next tick
		void kill();

		/// @brief Removes all components from an entity
		void erase();

		/// @brief Used to navigate the hierarchy
		/// @return Returns a shared pointer to Core
		std::shared_ptr<Core> getCore();

		/// @brief Gets the position of the entity
		/// @return Returns a shared pointer to the entities Transform component
		std::shared_ptr<Transform> getTransform();

		private:
		/// @brief allows Core to call tick and display
		friend struct Core;

		/// @brief Calls tick on the entities components if their m_alive is true, else removes the component.
		/// If a component throws an exception it will catch it and remove the entity rather than crash
		void tick();
		/// @brief Calls display on the entities list of components
		void display();

		std::list<std::shared_ptr<Component> > m_components; ///< A list of components this entity has
		std::weak_ptr<Transform> m_transform; ///< A pointer to this entities transform component
		bool m_alive; ///< a boolean used to determine whether to tick an entity or remove it
		std::weak_ptr<Core> m_core; ///< Weak pointer to core 
		std::weak_ptr<Entity> m_self; ///< Weak pointer to itself

	};

}