#include <iostream>
#include <myengine/myengine.h>

using namespace myengine;

/// @brief Player component mainly to mark an entity as a target for the enemy class
struct Player : Component
{
	Player() :
		m_angle(0)	{ }
		
	/// @brief Redefinition of virtual onTick from Component
	void onTick()
	{
		//As player doesnt do much used it as an exception tester
		if (getKeyboard()->getKeyDown(98))
		{
			// if B is pressed then throw an exception which is handled using a try catch in Entity.cpp
			std::cout << "entity errored" << std::endl;
			throw std::runtime_error("fake exception");
		}
	}

private:
	float m_angle;
};


/// @brief Enemy component - chases the last entity with player component
struct Enemy : Component
{
	Enemy() :
		m_angle(0) { }

	void onTick()
	{
		// finds all entities with player component
		getCore()->find<Player>(target);

		// if it found one
		if (target.size() > 0)
		{
			// get the target entities position
			rend::vec3 targetPos = target.front()->getEntity()->getTransform()->getPosition();
			// get own entities position
			rend::vec3 selfPos = getEntity()->getTransform()->getPosition();

			//find the difference
			diff = targetPos - selfPos;
			//calculate the vector to go from current position to target position
			dir = diff / sqrt((diff.x * diff.x) + (diff.y * diff.y) + (diff.z * diff.z));
			speed = 3.0f * getDeltaTime();

			// Move the enemy along the direction vector using speed to define how far it moves per frame
			getEntity()->getTransform()->setPosition(selfPos + (speed * dir));
		}
		// stops it adding targets to the array infinitely and also means if the player is removed that it isnt trying to chase a null pointer
		target.clear();
	}

private:
	float m_angle;
	float speed; ///< how quickly the enemy moves
	rend::vec3 diff; ///< an empty vec3 that gets set to the distance between the enemy and player position
	rend::vec3 dir; ///< an empty vec3 that gets set to the direction the enemy needs to travel to reach the player
	std::vector<std::shared_ptr<Player> >target; ///< an empty vector that gets assigned a list of every player component (should only be one)
};


/// @brief Main function operates the game
/// @param argc arguement count
/// @param argv arguement vector
/// @return int
int main(int argc, char* argv[])
{

std::cout << "hello world" << std::endl;

std::shared_ptr<Core> core = Core::initialize();


std::shared_ptr<Entity> player = core->addEntity();
player->addComponent<Player>();
std::shared_ptr<TriangleRenderer> renderer = player->addComponent<TriangleRenderer>();
std::shared_ptr<Texture> playerTex = player->getCore()->getResourceList()->load<Texture>("../data/models/curuthers/Whiskers_diffuse.png");
std::shared_ptr<Model> playerModel = player->getCore()->getResourceList()->load<Model>("../data/models/curuthers/curuthers.obj");
renderer->setTexture(playerTex);
renderer->setModel(playerModel);
std::shared_ptr<BoxCollider> pbc = player->addComponent<BoxCollider>();
std::shared_ptr<Controller> controller = player->addComponent<Controller>();
pbc->setSize(rend::vec3(1, 1, 1));
player->addComponent<RigidBody>();
player->getTransform()->setPosition(rend::vec3(-1, 2, -15));


std::shared_ptr<Entity> enemy = core->addEntity();
enemy->addComponent<Enemy>();
std::shared_ptr<TriangleRenderer> rendererEnemy = enemy->addComponent<TriangleRenderer>();
rendererEnemy->setTexture(playerTex);
rendererEnemy->setModel(playerModel);
std::shared_ptr<BoxCollider> ebc = enemy->addComponent<BoxCollider>();
ebc->setSize(rend::vec3(1, 1, 1));
enemy->addComponent<RigidBody>();
enemy->getTransform()->setPosition(rend::vec3(-5, 5, -15));

core->start();


return 0;

}