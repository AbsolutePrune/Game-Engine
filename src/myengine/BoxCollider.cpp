#include "BoxCollider.h"
#include "Entity.h"
#include "Transform.h"

namespace myengine
{

	void BoxCollider::onTick()
	{

	}

	void BoxCollider::setSize(rend::vec3 size)
	{
		m_size = size;
	}

	void BoxCollider::setOffset(rend::vec3 offset)
	{
		m_offset = offset;
	}

	// shared pointer could be wrong
	bool BoxCollider::colliding(const std::shared_ptr<BoxCollider> _other)
	{
		rend::vec3 a = getEntity()->getTransform()->getPosition();
		rend::vec3 as = m_size / 2.0f;
		rend::vec3 b = _other->getEntity()->getTransform()->getPosition();
		rend::vec3 bs = _other->m_size / 2.0f;

		if (a.x > b.x) // a right of b
		{
			if (a.x - as.x > b.x + bs.x) // left edge of a greater than right edge of b (not colliding)
			{
				return false;
			}
		}
		else
		{
			if (b.x - bs.x > a.x + as.x)
			{
				return false;
			}
		}
		if (a.z > b.z) // a front of b
		{
			if (a.z - as.z > b.z + bs.z) // back edge of a greater than front edge of b (not colliding)
			{
				return false;
			}
		}
		else
		{
			if (b.z - bs.z > a.z + as.z)
			{
				return false;
			}
		}
		if (a.y > b.y) // a above b
		{
			if (a.y - as.y > b.y + bs.y) // bottom edge of a greater than top edge of b (not colliding)
			{
				return false;
			}
		}
		else
		{
			if (b.y - bs.y > a.y + as.y)
			{
				return false;
			}
		}
		return true;
	}

	/*bool BoxCollider::isColliding(rend::vec3 position, rend::vec3 size)
	{
		return;
	}

	rend::vec3 BoxCollider::getCollisionResponse(rend::vec3 position, rend::vec3 size)
	{
		return;
	}*/
}