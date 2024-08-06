#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "iostream"
#include "Contact.hpp"

class PhoneBook
{
	private:
		int		idx;
		Contact	contact[8];
	public:
		PhoneBook(void);
		~PhoneBook(void);
		void	add(void);
		void	search(void);
};

#endif