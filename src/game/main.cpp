#include <iostream>
#include <myengine/myengine.h>

using namespace myengine;

struct Player : Component
{
	void onTick() {
		std::cout << "ticking" << std::endl;
	}
};

int main()
{

std::cout << "hello world" << std::endl;

std::shared_ptr<Core> core = Core::initialize();

std::shared_ptr<Entity> e = core->addEntity();

e->addComponent<Player>();

core->start();

return 0;

}