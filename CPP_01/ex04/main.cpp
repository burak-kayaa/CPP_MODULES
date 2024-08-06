#include "./depend.hpp"

int main(int argc, char const *argv[])
{
	if (argc != 4)
		return (-1);
	std::ofstream ofile;
	std::ifstream ifile;
	std::string file(argv[1]);
	char buffer[BUFFER_SIZE + 1] = {};
	std::string total;
	size_t  pos;
	size_t  pos1;
	size_t  lenfind;

	lenfind = strlen(argv[2]);
	pos = 0;
	pos1 = 0;
	ifile.open(file, std::ios::in);
	ofile.open(file + ".replace", std::ios::out);

	ifile.read(buffer, BUFFER_SIZE);
	while (ifile.gcount() == BUFFER_SIZE)
	{
		total.append(buffer);
		ifile.read(buffer, BUFFER_SIZE);
	}
	total.append(std::string(buffer).substr(0, ifile.gcount()));
	pos = total.find(argv[2], pos);
	while (pos != std::string::npos)
	{
		ofile << total.substr(pos1, pos - pos1) << argv[3];
		pos += lenfind;
		pos1 = pos;
		pos = total.find(argv[2], pos);
	}
	ofile << total.substr(pos1);
	ifile.close();
	ofile.close();
	return (0);
}
