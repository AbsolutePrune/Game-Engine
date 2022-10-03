#include <iostream>
#include <myengine/myengine.h>

using namespace myengine;

int main()
{

std::cout << "hello world" << std::endl;

std::shared_ptr<Core> core = Core::initialize();

//core.run();

return 0;

}