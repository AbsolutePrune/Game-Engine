#include "Environment.h"
#include <chrono>
#include <iostream>

namespace myengine
{
	std::chrono::steady_clock::time_point lastTime = std::chrono::high_resolution_clock::now();

	float Environment::getDeltaTime()
	{

		std::chrono::steady_clock::time_point currentTime = std::chrono::high_resolution_clock::now();
		std::chrono::milliseconds diff = std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - lastTime);
		lastTime = currentTime;

		float dt = diff.count() / 1000.0f;
		//std::cout << "Delta time: " << dt << std::endl;

		return dt;
	}
}