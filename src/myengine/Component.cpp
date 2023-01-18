#include "Component.h"
#include "Entity.h"
#include "Core.h"

namespace myengine
{
	void Component::onTick() {}
	void Component::onDisplay(){}

	void Component::tick()
	{
		onTick();
	}

	void Component::display()
	{
		onDisplay();
	}

	void Component::kill()
	{
		m_alive = false;
	}

	std::shared_ptr<Entity> Component::getEntity()
	{
		return m_entity.lock();
	}

	std::shared_ptr<Core> Component::getCore()
	{
		return getEntity()->getCore();
	}

	std::shared_ptr<Environment> Component::getEnvironment()
	{
		std::shared_ptr<Core> core = getCore();
		std::shared_ptr<Environment> environment = core->getEnvironment();
		return environment;
	}

	float Component::getDeltaTime()
	{
		std::shared_ptr<Core> core = getCore();
		std::shared_ptr<Environment> environment = core->getEnvironment();
		return environment->getDeltaTime();
	}

	std::shared_ptr<Keyboard> Component::getKeyboard()
	{
		std::shared_ptr<Core> core = getCore();
		std::shared_ptr<Keyboard> keyboard = core->getKeyBoard();
		return keyboard;
	}
}