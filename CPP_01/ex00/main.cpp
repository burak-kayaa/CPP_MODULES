#include "Zombie.hpp"

int	main()
{
	Zombie	zombie("way");
	Zombie	*ptr;

	ptr = zombie.newZombie("burak");
	ptr->announce();
	zombie.announce();
	zombie.randomChump("kaya");
	delete	ptr;
}