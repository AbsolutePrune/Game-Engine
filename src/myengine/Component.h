#ifndef MYENGINE_COMPONENT_H
#define MYENGINE_COMPONENT_H
#include <memory>
#include "Environment.h"
#include "Keyboard.h"

namespace myengine {

	struct Entity;
	struct Core;
	
	/// @brief Parent struct for components
	struct Component
	{
		/// @brief Sets a components m_alive to false so it is removed next tick
		void kill();

		/// @brief Used to call the entity that owns this component
		/// @return Returns a shared pointer to its entity
		std::shared_ptr<Entity> getEntity();

		/// @brief Used to call Core to navigate the hierarchy
		/// @return Returns a shared pointer to Core
		std::shared_ptr<Core> getCore();

		/// @brief Used to call Environment
		/// @return Returns a shared pointer to Environment
		std::shared_ptr<Environment> getEnvironment();

		/// @brief Gets the time taken between frames
		/// @return Returns a float which is the number of seconds since the last frame - usually 0.16 seconds
		float getDeltaTime();

		/// @brief Used to call keyboard
		/// @return Returns a shared pointer to keyboard
		std::shared_ptr<Keyboard> getKeyboard();

	private:
		/// @brief allows entity to call tick and display
		friend struct Entity;

		std::weak_ptr<Entity> m_entity; ///< weak pointer that gets set to the entity that owns the component upon its creation

		/// @brief Virtual function that is defined/redefined in child classes
		virtual void onTick();
		/// @brief Virtual function that is defined/redefined in child classes
		virtual void onDisplay();

		/// @brief calls onTick
		void tick();
		/// @brief calls onDisplay
		void display();

		bool m_alive = false;  ///< boolean to determine whether the component should be ticked or removed
	};
}

#endif // !MYENGINE_COMPONENT