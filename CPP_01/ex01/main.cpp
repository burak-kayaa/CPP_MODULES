#include "Zombie.hpp"

int	main()
{
	Zombie	zombie("kaya");
	Zombie	*horde;

	horde = zombie.zombieHorde(3, "burak");
	for (int i = 0; i < 3; i++)
		horde[i].announce();
	delete [] horde;
}
