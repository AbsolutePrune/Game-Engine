#include "Core.h"
#include "Entity.h"
#include <stdexcept>


namespace myengine 
{

	std::shared_ptr<Core> Core::initialize()
	{
		std::shared_ptr<Core> rtn = std::make_shared<Core>();

		rtn->m_self = rtn;
		rtn->m_running = false;


		if (SDL_Init(SDL_INIT_VIDEO) < 0)
		{
			throw std::runtime_error("failed to initialise SDL");
		}

		if (!(rtn->m_window = SDL_CreateWindow("SDL2 Platform",
			SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
			INITIAL_WIDTH, INITIAL_HEIGHT, SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL)))
		{
			SDL_Quit();
			throw std::runtime_error("failed to create window");
		}

		if (!(rtn->m_context = SDL_GL_CreateContext(rtn->m_window)))
		{
			SDL_DestroyWindow(rtn->m_window);
			SDL_Quit();
			throw std::runtime_error("Failed to create opengl context");
		}

		return rtn;
	}

	void Core::start() {

		m_running = true;

		std::chrono::steady_clock::time_point lastTime = std::chrono::high_resolution_clock::now();


		while (m_running) {

			std::chrono::steady_clock::time_point currentTime = std::chrono::high_resolution_clock::now();
			std::chrono::milliseconds diff = std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - lastTime);
			lastTime = currentTime;

			for (std::list<std::shared_ptr<Entity> >::iterator it = m_entities.begin();
				it != m_entities.end();
				it++)
			{
				(*it)->tick();
			}

			float dt = diff.count() / 1000.0f;
			std::cout << "Delta time: " << dt << std::endl;

			rend::Renderer r(640, 480);
			// need to specify color i think
			r.clear();

			for (std::list<std::shared_ptr<Entity> >::iterator it = m_entities.begin();
				it != m_entities.end();
				it++)
			{
				(*it)->display();
			}


			SDL_GL_SwapWindow(m_window);
		}


	}

	void Core::stop() {
		m_running = false;
	}

	std::shared_ptr<Entity> Core::addEntity() {
		std::shared_ptr<Entity> rtn = std::make_shared<Entity>();

		m_entities.push_back(rtn);

		return rtn;
	}
}