#pragma once

namespace myengine
{
	/// @brief Used to keep track of delta time - time between drawing of frames
	struct Environment
	{
		/// @brief gets the time since the last frame was drawn
		/// @return Returns deltaTime as a float
		float getDeltaTime();

	private:
		float deltaTime; ///< float to store the difference in time between frames being drawn
	};
}