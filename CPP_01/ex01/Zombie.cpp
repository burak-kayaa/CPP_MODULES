#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
	this->name = name;
	std::cout << this->name << " created." << std::endl;
}

Zombie::Zombie(void)
{
	std::cout << this->name << " created." << std::endl;
}

Zombie::~Zombie(void)
{
	std::cout << this->name << " destroyed" << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << this->name << ":  BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::getName(std::string name)
{
	this->name = name;
}

Zombie	*Zombie::zombieHorde(int N, std::string name)
{
	Zombie	*horde = new Zombie[N];

	for (int i = 0; i < N; i++)
		horde[i].getName(name);
	return (horde);
}