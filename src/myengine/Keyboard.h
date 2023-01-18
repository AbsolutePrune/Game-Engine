#pragma once
#include <vector>
//maybe a double
#include "SDL2/SDL.h"

namespace myengine
{
	/// @brief Stores which keys are being pressed
	struct Keyboard
	{
		/// @brief adds a pressed keys keycode into an array
		/// @param keyCode the pressed key
		void keyDown(int keyCode);

		/// @brief removes a key from the array when it is no longer held
		/// @param keyCode the key to be removed from the array
		void keyUp(int keyCode);

		/// @brief checks if the key passed in is being held down
		/// @param keyCode the key to check
		/// @return returns true if the key is held down otherwise false
		bool getKeyDown(int keyCode);

		/// @brief checks if the key passed in is up
		/// @param keyCode the key to check
		/// @return return true of the key is up otherwise false
		bool getKeyUp(int keyCode);

		// used to print the key being pressed
		void printKey(SDL_KeyboardEvent *key);

	private:

		std::vector<int> keyCodes; ///< vector of keyCodes of keys being held down - can only hold 6 or 7 at max due to keyboard limitations
	};
}