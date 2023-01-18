#include "Core.h"
#include "Entity.h"
#include "ResourceList.h"
#include "Environment.h"
#include <stdexcept>
#include <rend/rend.h>
#include <chrono>
#include <iostream>
#include "Transform.h"


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

		if (!(rtn->m_device))
		{
			throw std::runtime_error("Failed to open audio device");
		}

		if (!(rtn->m_audioContext))
		{
			alcCloseDevice(rtn->m_device);
			throw std::runtime_error("Failed to create audio context");
		}

		if (!alcMakeContextCurrent(rtn->m_audioContext))
		{
			alcDestroyContext(rtn->m_audioContext);
			alcCloseDevice(rtn->m_device);
			throw std::runtime_error("Failed to make context current");
		}

		alListener3f(AL_POSITION, 0.0f, 0.0f, 0.0f);

		rtn->m_keyboard = std::make_shared<Keyboard>();
		rtn->m_rList = std::make_shared<ResourceList>();
		rtn->m_environment = std::make_shared<Environment>();

		return rtn;
	}

	void Core::start() {

		m_running = true;

		SDL_Event event = { 0 };

		while (m_running) {
			while (SDL_PollEvent(&event))
			{
				if (event.type == SDL_QUIT)
				{
					m_running = false;
				}
				else
				{
					switch (event.type)
					{
					case SDL_KEYUP:
						getKeyBoard()->keyUp(event.key.keysym.sym);
						break;
					case SDL_KEYDOWN:
						getKeyBoard()->keyDown(event.key.keysym.sym);
						break;
					
					default:
						break;
					}
				}
			}

			rend::Renderer r(640, 480);
			r.clear();

			for (std::list<std::shared_ptr<Entity> >::iterator it = m_entities.begin();
				it != m_entities.end();
				it++)
			{
				(*it)->tick();
			}	

			for (std::list<std::shared_ptr<Entity> >::iterator it = m_entities.begin();
				it != m_entities.end();
				it++)
			{
				(*it)->display();
			}

			for (std::list<std::shared_ptr<Entity> >::iterator it = m_entities.begin();
				it != m_entities.end();
				//it++
				)
			{
				if (!(*it)->m_alive)
				{

					(*it)->erase();


					std::list<std::shared_ptr<Entity> >::iterator pos = m_entities.erase(it);
					std::cout << "erased entity" << std::endl;
					if (pos != m_entities.end())
					{
						pos++;
					}
					it = pos;
				}
				else
				{
					it++;
				}
			}

			SDL_GL_SwapWindow(m_window);
		}


	}

	void Core::stop() {
		m_running = false;
	}

	std::shared_ptr<ResourceList> Core::getResourceList()
	{
		return m_rList;
	}

	std::shared_ptr<Environment> Core::getEnvironment()
	{
		std::shared_ptr<Environment> environment = m_environment.lock();
		return environment;
	}

	float Core::getDeltaTime()
	{
		std::shared_ptr<Environment> environment = m_environment.lock();
		return environment->getDeltaTime();
	}

	std::shared_ptr<Keyboard> Core::getKeyBoard()
	{
		return m_keyboard;
	}

	std::shared_ptr<Entity> Core::addEntity() {
		std::shared_ptr<Entity> rtn = std::make_shared<Entity>();

		rtn->m_core = m_self;
		rtn->m_self = rtn;
		rtn->m_transform = rtn->addComponent<Transform>();
		rtn->m_alive = true;

		m_entities.push_back(rtn);

		return rtn;
	}
}