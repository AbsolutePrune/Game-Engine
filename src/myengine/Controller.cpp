#include "Controller.h"
#include "Transform.h"
#include "Keyboard.h"
#include <iostream>

namespace myengine
{

	void Controller::onTick()
	{
		checkMoveKeys();
		move();
		clearShift();
	}

	void Controller::checkMoveKeys()
	{
		// W key - up
		if (getKeyboard()->getKeyDown(119))
		{
			yShift += shiftAmount;
		}

		// A key - left
		if (getKeyboard()->getKeyDown(97))
		{
			xShift -= shiftAmount;
		}

		// D key - right
		if (getKeyboard()->getKeyDown(100))
		{
			xShift += shiftAmount;
		}

		// S key - down
		if (getKeyboard()->getKeyDown(115))
		{
			yShift -= shiftAmount;
		}

		// Q key - away from screen
		if (getKeyboard()->getKeyDown(113))
		{
			zShift -= shiftAmount;
		}

		// E key - towards screen
		if (getKeyboard()->getKeyDown(101))
		{
			zShift += shiftAmount;
		}

	}

	void Controller::move()
	{
		rend::vec3 pos = getEntity()->getTransform()->getPosition();
		getEntity()->getTransform()->setPosition(rend::vec3(pos.x += xShift, pos.y += yShift, pos.z += zShift));
	}


	void Controller::clearShift()
	{
		xShift = 0.0f;
		yShift = 0.0f;
		zShift = 0.0f;
	}
}