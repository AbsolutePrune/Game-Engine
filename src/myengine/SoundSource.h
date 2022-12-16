#include "Component.h"
//#include "Audio.h"

#include <string>
#include <vector>
#include <memory>
#include <string>
#include <AL/al.h>

namespace myengine
{
	struct Audio;

	struct SoundSource : Component
	{
		SoundSource();

		void onTick();

		std::shared_ptr<Audio> setAudio(std::shared_ptr<Audio>);

		void load_ogg(const std::string&, std::vector<unsigned char>&, ALenum&, ALsizei&);

	private:
		
	};
}