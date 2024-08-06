#include "Contact.hpp"

void	Contact::setFirstName(std::string firsName)
{
	this->firstName = firsName;
}

void	Contact::setLastName(std::string lastName)
{
	this->lastName = lastName;
}

void	Contact::setNickName(std::string nickName)
{
	this->nickName = nickName;
}

void	Contact::setPhoneNumber(std::string phoneNumber)
{
	this->phoneNumber = phoneNumber;
}

void	Contact::setDarkSecret(std::string darkSecret)
{
	this->darkSecret = darkSecret;
}

void Contact::getIds()
{
    std::cout << "Enter first name: ";
	getline(std::cin, this->firstName);
	if (this->firstName.empty())
	{
		std::cout << "First name cannot be empty" << std::endl;
		std::cin.clear();
		return ;
	}
    std::cout << "Enter last name: ";
	getline(std::cin, this->lastName);
	if (this->lastName.empty())
	{
		std::cout << "Last name cannot be empty" << std::endl;
		std::cin.clear();
		return ;
	}
    std::cout << "Enter nickname: ";
	getline(std::cin, this->nickName);
	if (this->nickName.empty())
	{
		std::cout << "Nick name cannot be empty" << std::endl;
		std::cin.clear();
		return ;
	}
    std::cout << "Enter phone number: ";
	getline(std::cin, this->phoneNumber);
	if (this->phoneNumber.empty())
	{
		std::cout << "Phone number cannot be empty" << std::endl;
		std::cin.clear();
		return ;
	}
    std::cout << "Enter dark secret: ";
	getline(std::cin, this->darkSecret);
	if (this->darkSecret.empty())
	{
		std::cout << "Dark secret cannot be empty" << std::endl;
		std::cin.clear();
		return ;
	}
	std::cin.clear();
}
