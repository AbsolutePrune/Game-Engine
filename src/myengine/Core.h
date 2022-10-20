#include <memory>
#include <list>
#include <SDL2/SDL.h>
#include <chrono>
#include <iostream>
#include <rend/rend.h>


#define INITIAL_HEIGHT 640
#define INITIAL_WIDTH 480

namespace myengine
{
	struct Entity;
	
	struct Core
	{
		static std::shared_ptr<Core> initialize();

		void start();
		void stop();
		std::shared_ptr<Entity> addEntity();

	private:
		bool m_running;
		std::list<std::shared_ptr<Entity> > m_entities;
		std::weak_ptr<Core>  m_self;
		SDL_Window* m_window;
		SDL_GLContext m_context;
	};
}