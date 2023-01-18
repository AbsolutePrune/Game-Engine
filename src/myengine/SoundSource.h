#include "Component.h"
#include "Resource.h"
#include <string>
#include <vector>
#include <memory>
#include <string>
#include <AL/al.h>

namespace myengine
{
	struct Audio;

	/// @brief Component that plays sound
	struct SoundSource : Component
	{
		/// @brief Constructor (empty)
		SoundSource();

		/// @brief redfinition of Virtual onTick from Component parent - gets the sounds current state and listeners position
		///	if the audio is done playing calls kill to remove itself from the components list
		void onTick();

		/// @brief Used to set and play the audio the soundsource should play
		/// @param  
		void setAudio(std::shared_ptr<Resource>);
		
		/// @brief Used to load the audio to play using its file path
		/// @param  path to file
		/// @param  buffer data
		/// @param  audio format
		/// @param  audio frequency
		void load_ogg(const std::string&, std::vector<unsigned char>&, ALenum&, ALsizei&);

	private:
		ALuint m_sourceId; ///< Id of the source
	};
}