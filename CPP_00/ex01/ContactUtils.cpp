#include "Contact.hpp"

std::string	Contact::getFirstName()
{
	return (this->firstName);
}

std::string	Contact::getLastName()
{
	return (this->lastName);
}

std::string	Contact::getNickName()
{
	return (this->nickName);
}

std::string	Contact::getPhoneNumber()
{
	return (this->phoneNumber);
}

std::string	Contact::getDarkSecret()
{
	return (this->darkSecret);
}

void	Contact::putIds()
{
	std::cout << "First Name: " << this->firstName << std::endl;
	std::cout << "Last Name: " << this->lastName << std::endl;
	std::cout << "Nick Name: " << this->nickName << std::endl;
	std::cout << "Phone Number: " << this->phoneNumber << std::endl;
	std::cout << "Dark Secret: " << this->darkSecret << std::endl;
}

std::string	ft_get_spaces(std::string str)
{
	std::string	new_str;
	int			space_len;

	space_len = 10 - str.length();
	while (space_len > 0)
	{
		new_str.append(" ");
		space_len--;
	}
	new_str.append(str);
	return (new_str);
}

std::string	ft_get_max_len(std::string str)
{
	if (str.length() > 10)
	{
		str.resize(10);
		str[9] = '.';
		return (str);
	}
	else
		return (ft_get_spaces(str));
}

void	Contact::putSearch(int i)
{
	std::cout << "|";
	std::cout << "         ";
	std::cout << i;
	std::cout << "|";
	std::cout << ft_get_max_len(this->firstName) + "|";
	std::cout << ft_get_max_len(this->lastName) + "|";
	std::cout << ft_get_max_len(this->nickName) + "|" << std::endl;
}