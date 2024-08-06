#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"
#include "Brain.hpp"

class WrongCat : public WrongAnimal
{
	private:
		Brain	*brain;
	public:
		WrongCat();
		WrongCat(std::string type);
		WrongCat(const WrongCat &wrongcat);
		WrongCat	&operator=(const WrongCat &wrongcat);
		virtual		~WrongCat();
		void		makeSound() const;
		void		setIdea(std::string idea, int index);
		void		getIdea(int index) const;
};

#endif