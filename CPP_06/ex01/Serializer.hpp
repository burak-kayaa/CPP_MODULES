#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <string>
#include <stdint.h>
#include "Data.hpp"

class Serializer
{
	public:
		// Constructor - Destructor - Copy
		Serializer();
		Serializer(const Serializer &src);
		~Serializer();
		Serializer &operator=(const Serializer &src);
		// Getter - Setter
		static uintptr_t	serialize(Data *ptr);
		static Data			*deserialize(uintptr_t raw); 
};

#endif