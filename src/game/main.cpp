#include <iostream>
#include <myengine/myengine.h>

using namespace myengine;

struct Player : Component
{
	Player():
		m_count(0)	{ }

	void onTick() {
		++m_count;
		//std::cout << "ticking" << std::endl;

		if (m_count > 20)
		{
			//getEntity kill
			//getEntity getCore stop
			//getCore stop
		}
	}

private:
	int m_count;
};

int main(int argc, char* argv[])
{

std::cout << "hello world" << std::endl;

std::shared_ptr<Core> core = Core::initialize();

std::shared_ptr<Entity> e = core->addEntity();

std::shared_ptr<SoundSource> ss = e->addComponent<SoundSource>();
std::shared_ptr<Audio> clip = core->getResourceList()->load<Audio>("../dixie_horn.ogg");
ss->setAudio(clip);

e->addComponent<Player>();
e->addComponent<TriangleRenderer>();
//e->addComponent<SoundSource>();

//std::shared_ptr<TriangleRenderer> tr = e->addComponent<TriangleRenderer>();
//std::shared_ptr<Texture> tex = core->getResources()->load<Texture>("textures/cat");
//tr->setTexture(tex);
//
//
//std::shared_ptr<SoundSource> ss = e->addComponent<SoundSource>();


core->start();

return 0;

}