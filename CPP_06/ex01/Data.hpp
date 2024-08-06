#ifndef DATA_HPP
#define DATA_HPP

#include <iostream>
#include <string>

class Data
{
	public:
		// Constructor - Destructor - Copy
		Data();
		Data(std::string str, int i, float f);
		Data(const Data &src);
		~Data();
		Data &operator=(const Data &src);
		// Getter - Setter
		std::string	getStr() const;
		void		setStr(std::string str);
		int			getInt() const;
		void		setInt(int i);
		float		getFloat() const;
		void		setFloat(float f);
		// Method
	private:
		std::string	_str;
		int			_int;
		float		_float;
};

#endif