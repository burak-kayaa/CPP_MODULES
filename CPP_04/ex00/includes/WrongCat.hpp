#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public:
		WrongCat();
		WrongCat(std::string type);
		WrongCat(const WrongCat &wrongcat);
		WrongCat	&operator=(const WrongCat &wrongcat);
		virtual		~WrongCat();
		void		makeSound() const;
};

#endif