#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <string>

class Brain
{
	protected:
		std::string	ideas[100];
	public:
		Brain();
		Brain(const Brain &copy);
		Brain &operator=(const Brain &copy);
		~Brain();
		void	setIdea(std::string idea, int index);
		std::string	getIdea(int index) const;
};

#endif