#include "RigidBody.h"
#include "Entity.h"
#include "Transform.h"
#include "Core.h"
#include <iostream>
#include "BoxCollider.h"

namespace myengine

{	
	void RigidBody::onTick()
	{
		getCore()->find<BoxCollider>(m_colliders);

		if (isColliding())
		{
			getEntity()->getTransform()->setPosition(
				getCollisionResponse(getEntity()->getTransform()->getPosition(), getEntity()->getTransform()->getSize())
			);
		}

		m_colliders.clear();
	}

	bool RigidBody::isColliding()
	{
		
		for (std::vector<std::shared_ptr<BoxCollider> >::iterator it = m_colliders.begin();
			it != m_colliders.end();
			it++)
		{
			if (getEntity() != (*it)->getEntity())
			{
				
				if (getEntity()->getComponent<BoxCollider>()->colliding(*it))
				{
					return true;
				}
			}
		}
		return false;
	}


	/// <summary>
	/// Kludge collision response. Bug - each collision takes another loop until it goes through the object
	/// </summary>
	/// <param name="position"></param>
	/// <param name="size"></param>
	/// <returns>
	/// Entity position
	/// </returns>
	rend::vec3 RigidBody::getCollisionResponse(rend::vec3 position, rend::vec3 size)
	{
		float amount = 0.1f;
		float step = 0.01f;
		int loops = 0;

		while (isColliding())
		{
			if (!isColliding()) break;
			getEntity()->getTransform()->setPosition(rend::vec3(position.x += amount, position.y, position.z));
			if (!isColliding()) break;
			getEntity()->getTransform()->setPosition(rend::vec3(position.x -= amount, position.y, position.z));
			getEntity()->getTransform()->setPosition(rend::vec3(position.x -= amount, position.y, position.z));
			if (!isColliding()) break;
			getEntity()->getTransform()->setPosition(rend::vec3(position.x += amount, position.y, position.z));
			getEntity()->getTransform()->setPosition(rend::vec3(position.x, position.y, position.z += amount));
			if (!isColliding()) break;
			getEntity()->getTransform()->setPosition(rend::vec3(position.x, position.y, position.z -= amount));
			getEntity()->getTransform()->setPosition(rend::vec3(position.x, position.y, position.z -= amount));
			if (!isColliding()) break;
			getEntity()->getTransform()->setPosition(rend::vec3(position.x, position.y, position.z += amount));
			getEntity()->getTransform()->setPosition(rend::vec3(position.x, position.y += amount, position.z));
			if (!isColliding()) break;
			getEntity()->getTransform()->setPosition(rend::vec3(position.x, position.y -= amount, position.z));
			getEntity()->getTransform()->setPosition(rend::vec3(position.x, position.y -= amount, position.z));
			if (!isColliding()) break;
			getEntity()->getTransform()->setPosition(rend::vec3(position.x, position.y += amount, position.z));
			amount += step;
			++loops;
		}
		return position;
	}
}
