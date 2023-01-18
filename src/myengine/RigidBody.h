#pragma once
#include "Component.h"
#include "rend/rend.h"
#include <vector>


namespace myengine
{

	struct BoxCollider;

	/// @brief Physics component that uses the data from box collider to provide collision responses
	struct RigidBody : Component
	{
		/// @brief redefinition of virtual onTick from Component
		void onTick();

		/// @brief While isColliding is true moves the entity slightly in every direction and checks if it is still colliding
		/// if it has tried moving in every direction then it increases the amount by which it moves the object and loops again until 
		/// it is no longer colliding
		/// @param position The objects position before the collision response
		/// @param size The objects size
		/// @return The objects new position where it is no longer colliding
		rend::vec3 getCollisionResponse(rend::vec3 position, rend::vec3 size);

		/// @brief loops through the list of entities with box colliders to check if they are colliding
		/// @return boolean true if they are colliding and false otherwise
		bool isColliding();

	private:
		
		std::vector<std::shared_ptr<BoxCollider> > m_colliders; ///< a vector of every box collider in the scene
	};
}