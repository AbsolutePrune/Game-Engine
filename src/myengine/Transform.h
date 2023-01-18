#pragma once
#include "Component.h"
#include <rend/rend.h>

namespace myengine
{
	/// @brief Component providing position information of the Entity.
	struct Transform : Component
	{
		/// @brief constructor - sets scale to (1,1,1)
		Transform();

		/// @brief Generate the model matrix based on the position, rotation and scale.
		/// @return Returns the generated model matrix
		rend::mat4 getModel();

		/// @brief Gets position
		/// @return Returns entity position
		rend::vec3 getPosition();

		/// @brief Gets rotation
		/// @return Returns entity rotation
		rend::vec3 getRotation();

		/// @brief Gets scale
		/// @return Returns entity scale
		rend::vec3 getSize();

		/// @brief Set position
		/// @param _position The new position
		void setPosition(const rend::vec3& _position);

		/// @brief Set Rotation
		/// @param _rotation The new rotation
		void setRotation(const rend::vec3& _rotation);

	private:
		rend::vec3 m_position; ///< X, Y, Z location of entity
		rend::vec3 m_rotation; ///< Rotation of entity in euler angles
		rend::vec3 m_scale;	   ///< Scale of entity

	};
}