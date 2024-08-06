#include "Character.hpp"

Character::Character() : _name("default")
{
	for (int i = 0; i < 4; i++)
		_materias[i] = NULL;
}

Character::Character(std::string const &name) : _name(name)
{
	for (int i = 0; i < 4; i++)
		_materias[i] = NULL;
}

Character::Character(Character const &src)
{
	*this = src;
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		if (_materias[i])
			delete _materias[i];
	}
}

Character	&Character::operator=(Character const &src)
{
	if (!this->_name.empty())
	{
		for (int i = 0; i < 4; i++)
		{
			if (this->_materias[i])
				delete this->_materias[i];
		}
	}
	else
	{
		for (int i = 0; i < 4; i++)
			this->_materias[i] = NULL;
	}
	if (this != &src)
	{
		for (int i = 0; i < 4; i++)
		{
			if (src._materias[i])
				this->_materias[i] = src._materias[i]->clone();
		}
	}
	this->_name = src._name;
	return (*this);
}

std::string const &Character::getName() const
{
	return (_name);
}

void Character::equip(AMateria* m)
{
	if (!m)
		return;
	for (int i = 0; i < 4; i++)
	{
		if (!_materias[i])
		{
			_materias[i] = m;
			break;
		}
	}
}

void Character::unequip(int idx)
{
	AMateria *tmp;

	tmp = NULL;
	if (idx >= 0 && idx < 4)
	{
		tmp = _materias[idx];
		if (tmp)
			std::cout << "unequip " << tmp->getType() << std::endl;
		_materias[idx] = NULL;
	}
}

void Character::use(int idx, ICharacter &target)
{
	if (idx >= 0 && idx < 4 && _materias[idx] != NULL)
		_materias[idx]->use(target);
}