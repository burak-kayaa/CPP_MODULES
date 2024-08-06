#include "Serializer.hpp"

int	main()
{
	Data	*data = new Data("Hello", 42, 42.42f);
	uintptr_t	raw = Serializer::serialize(data);
	Data		*data2 = Serializer::deserialize(raw);

	std::cout << "Data 1:" << std::endl;
	std::cout << "Str: " << data->getStr() << std::endl;
	std::cout << "Int: " << data->getInt() << std::endl;
	std::cout << "Float: " << data->getFloat() << std::endl;
	std::cout << "Data 2:" << std::endl;
	std::cout << "Str: " << data2->getStr() << std::endl;
	std::cout << "Int: " << data2->getInt() << std::endl;
	std::cout << "Float: " << data2->getFloat() << std::endl;
	delete data;
	return 0;
}