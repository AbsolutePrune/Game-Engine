#include "Keyboard.h"
#include <iostream>

namespace myengine
{
	void Keyboard::keyDown(int keyCode)
	{
		bool isDupe = false;

		//std::cout << keyCode << std::endl;

		if (keyCodes.size() > 0)
		{

			for (size_t i = 0; i < keyCodes.size(); i++)
			{
				if (keyCode == keyCodes.at(i))
				{
					isDupe = true;
				}

			}
		}
		else
		{
			keyCodes.push_back(keyCode);
			return;
		}

		if (!isDupe)
		{
			keyCodes.push_back(keyCode);
		}
		
	}


	void Keyboard::keyUp(int keyCode)
	{
		for (std::vector<int>::iterator it = keyCodes.begin();
			it != keyCodes.end();
			)
		{
			if ((*it) == keyCode)
			{
				it = keyCodes.erase(it);
			}
			else
			{
				++it;
			}
		}
	}

	bool Keyboard::getKeyDown(int keyCode)
	{
		for (std::vector<int>::iterator it = keyCodes.begin();
			it != keyCodes.end();
			it++)
		{
			if ((*it) == keyCode)
			{
				return true;
			}
		}
		return false;
	}

	bool Keyboard::getKeyUp(int keyCode)
	{
		for (std::vector<int>::iterator it = keyCodes.begin();
			it != keyCodes.end();
			it++)
		{
			if ((*it) == keyCode)
			{
				return true;
			}
		}
		return false;
	}

	void Keyboard::printKey(SDL_KeyboardEvent *key)
	{
		if (key->type == SDL_KEYUP)
		{
			std::cout << "up" << std::endl;
		}
		else
		{
			std::cout << "down" << std::endl;
		}
	}
}