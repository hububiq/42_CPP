#include "BitcoinExchange.hpp"

std::map<std::string, double> processDb(std::ifstream& Db)
{
	std::string line;
	std::map<std::string, double> Map;

	while (std::getline(Db, line))
	{
		size_t index = line.find(",");
		std::string date = line.substr(0, index);
		double price = std::atof(line.substr(index + 1).c_str());
		Map[date] = price;
	}
	return Map;
}

int main(int argc, char **argv)
{
	(void)argv;
	if (argc != 2)
		return std::cerr << "Arguments needed" << std::endl, -1;
	std::ifstream DbFile("data.csv");
	if (!DbFile.is_open())
		return std::cerr << "Couldn't open such file" << std::endl, -1;
	std::map<std::string, double> priceMap = processDb(DbFile);
	// for (std::map<std::string, double>::const_iterator it = priceMap.begin(); it != priceMap.end(); it++)
		// std::cout << it->first << " " << it->second << std::endl;

	/* function to pass Map to calculation and input.txt */
	// std::ifstream file(name.c_str());  //ofstream construction with std::string converted to char *
	return 0;
}