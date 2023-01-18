#pragma once
#include "Component.h"
#include <rend/rend.h>
#include <vector>

namespace myengine
{
	/// @brief BoxCollider Component that checks if collisions are occuring
	struct BoxCollider : Component
	{
		/// @brief redefinition of virtual onTick from Component
		void onTick();

		/// @brief Sets the size of the box collider
		/// @param size The new size
		void setSize(rend::vec3 size);

		/// @brief Sets the offset of the box collider - useful if the collider shouldnt be in the centre of the object
		/// @param offset The amount to offset the box collider
		void setOffset(rend::vec3 offset);

		/// @brief Checks whether this collider is colliding with the _other collider
		/// @param _other The collider to test 
		/// @return Returns true if colliding otherwise false
		bool colliding(const std::shared_ptr<BoxCollider> _other);



	private:
		rend::vec3 m_size; ///< box colliders size
		rend::vec3 m_offset; ///< box colliders offset
	};
}