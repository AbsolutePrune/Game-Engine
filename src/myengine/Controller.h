#pragma once
#include "Component.h"
#include "Entity.h"


namespace myengine
{
	/// @brief Component using keyboard inputs to change the position of the Entity
	struct Controller : Component
	{
		/// @brief Redefinition of virtual onTick from Component called every frame
		void onTick();

		/// @brief Checks the array of keys being held down for specific movement keys and sets shift values based on what is being held down 
		void checkMoveKeys();

		/// @brief Moves the entity by adding the shift values to the entities current position
		void move();

		/// @brief Sets the shift values back to zero to stop them increasing each frame they are held causing massive acceleration
		void clearShift();

	private:

		float xShift = 0.0f; ///< value to be added to the x position of the entity
		float yShift = 0.0f; ///< value to be added to the y position of the entity
		float zShift = 0.0f; ///< value to be added to the z position of the entity

		float shiftAmount = 0.1f; ///< value to alter the shift values by
	};

}