#include <memory>
#include <list>
#include <SDL2/SDL.h>
//#include <chrono>
//#include <iostream>
//#include <rend/rend.h>
#include <AL/al.h>
#include <AL/alc.h>



#define INITIAL_HEIGHT 640
#define INITIAL_WIDTH 480

namespace myengine
{
	struct Entity;
	struct ResourceList;
	
	struct Core
	{
		/**
		* initialise core
		* 
		* \return core
		*/
		static std::shared_ptr<Core> initialize();

		/**
		*  Start the engine
		*/
		void start();

		/**
		*  Stop the engine
		*/
		void stop();

		std::shared_ptr<ResourceList> getResourceList();

		/**
		*  adds an entity and pushes it to m_entities
		* 
		*  \return the entity it pushed
		*/
		std::shared_ptr<Entity> addEntity();

	private:
		bool m_running;									///< bool used to tell if the program should be running

		;	///< an array of entities to tick and display
		std::weak_ptr<Core>  m_self;					///< a weak pointer from core to itself
		std::list<std::shared_ptr<Entity> > m_entities;
		SDL_Window* m_window;							///< SDL_Window
		SDL_GLContext m_context;						///< SDL_GLContext

		ALCdevice* m_device = alcOpenDevice(NULL);
		ALCcontext* m_audioContext = alcCreateContext(m_device, NULL);

	};
}