#ifndef CARL_H
#define CARL_H

# include "iostream"

class Harl
{
	private:
		void debug(void)
		{
			std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
		}
		void info(void)
		{
			std::cout << "I cannot believe adding extra bacon costs more money. You didnt putenough bacon in my burger! If you did, I wouldnt be asking for more!" << std::endl;
		}
		void warning(void)
		{
			std::cout << "I think I deserve to have some extra bacon for free. Ive been coming for years whereas you started working here since last month." << std::endl;
		}
		void error(void)
		{
			std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
		}
	public:
		Harl();
		~Harl();
		void complain(std::string level);
};
#endif
