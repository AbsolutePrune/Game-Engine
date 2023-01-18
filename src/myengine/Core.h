#include <memory>
#include <list>
#include <SDL2/SDL.h>
#include <rend/rend.h>
#include <AL/al.h>
#include <AL/alc.h>
#include "Environment.h"
#include "Keyboard.h"


#define INITIAL_HEIGHT 480
#define INITIAL_WIDTH 640

namespace myengine
{
	struct Entity;
	struct ResourceList;
	struct Renderer;
	
	/// @brief Core Creates the window, checks for keyboard inputs and calls tick on all entities in m_entities
	struct Core
	{
		/// @brief Creates Core and initialises SDL, OpenGL, OpenAL and creates a window. Also creates Keyboard, Environment and ResourceList objects.
		/// @return Returns a pointer to Core
		static std::shared_ptr<Core> initialize();



		/// @brief Sets m_running to true then loops while it is true
		void start();

		/// @brief Sets m_running to false so the engine stops at the start of the next loop
		void stop();

		/// @brief Used to access the resource list
		/// @return Returns a pointer to the resource list
		std::shared_ptr<ResourceList> getResourceList();

		/// @brief Used to access the environment class
		/// @return A pointer to the environment class
		std::shared_ptr<Environment> getEnvironment();

		/// @brief Used as a shortcut to access delta time
		/// @return Returns the time since the last frame
		float getDeltaTime();

		/// @brief Used to access the Keyboard class
		/// @return Returns a pointer to Keyboard class
		std::shared_ptr<Keyboard> getKeyBoard();

		/// @brief Creates a new entity and pushes it to m_entities list
		/// @return Returns the created entity
		std::shared_ptr<Entity> addEntity();

		/// @brief Finds all entities with the specified component and pushes the components into the _out parameter vector
		/// @tparam T
		/// @param _out The list of components of the correct type found
		template <typename T>
		void find(std::vector<std::shared_ptr<T> >& _out)
		{

			for (std::list<std::shared_ptr<Entity> >::iterator itEntity = m_entities.begin();
				itEntity != m_entities.end();
				itEntity++)
			{
				for (std::list<std::shared_ptr<Component> >::iterator itComp = (*itEntity)->m_components.begin();
					itComp != (*itEntity)->m_components.end();
					itComp++)
				{
					// checks if the current component can be cast to the specified component
					std::shared_ptr<T> t = std::dynamic_pointer_cast<T>(*itComp);
					// if it can then it is added to the _out vector which can be accessed in the calling class
					if (t)
					{
						_out.push_back(t);
					}
				}
			}
		}

	private:

		bool m_running; ///< bool used to tell if the program should be running

			
		std::weak_ptr<Core> m_self;	///< a weak pointer from core to itself

		std::list<std::shared_ptr<Entity> > m_entities; ///< an array of entities to tick and display
		std::shared_ptr<ResourceList> m_rList; ///< shared pointer to ResourceList
		std::weak_ptr<Environment> m_environment; ///< weak pointer to Environment
		std::shared_ptr<Keyboard> m_keyboard; ///< shared pointer to Keyboard


		SDL_Window* m_window; ///< SDL_Window
		SDL_GLContext m_context; ///< SDL_GLContext

		ALCdevice* m_device = alcOpenDevice(NULL); ///< ALCdevice
		ALCcontext* m_audioContext = alcCreateContext(m_device, NULL); ///< ALC context

	};
}
