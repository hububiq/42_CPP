#include "BitcoinExchange.hpp"


// void calculate(std::multimap<std::string, double> priceMap, std::multimap<std::string, double> inFile)
// {
// 	return ;
// }

bool checkLine(std::string line, size_t& indexIn, std::string& valueStr)
{
	double value = std::atof(valueStr.c_str());
	try
	{
		if (indexIn == std::string::npos)
		{
			std::cout << "Error: bad input => " << line << std::endl;
			return 1;
		}
		else if (value < 0)
		{
			throw std::invalid_argument("Error: not a positive number.");
			return 1;
		}
		else if (value > 1000)
		{
			throw std::invalid_argument("Error: too large a number.");
			return 1;
		}
	}
	catch (std::invalid_argument& e) { std::cout << e.what() << std::endl;};
	return 0;
}

std::multimap<std::string, double> processInFile(std::string name)
{
	std::string line;
	std::multimap<std::string, double> inFileMap;
	std::ifstream inFile(name.c_str());
	if (!inFile.is_open())
		return std::cerr << "Couldn't open input file" << std::endl, inFileMap;
	while (getline(inFile, line))
	{
		size_t index = line.find("|");
		std::string date = line.substr(0, index - 1);
		std::string valueStr = line.substr(index + 1);
		if (checkLine(line, index, valueStr))
			continue;
		double value = std::atof(valueStr.c_str()); //atof ignoring leading and trailing white char
		inFileMap.insert(std::make_pair(date, value));
	}
	return inFileMap;
}

std::multimap<std::string, double> processDb(std::ifstream& Db)
{
	std::string line;
	std::multimap<std::string, double> Map;

	while (std::getline(Db, line))
	{
		size_t index = line.find(",");
		std::string date = line.substr(0, index);
		double price = std::atof(line.substr(index + 1).c_str());
		Map.insert(std::make_pair(date, price));
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
	std::multimap<std::string, double> priceMap = processDb(DbFile);
	std::multimap<std::string, double> inFile = processInFile(argv[1]);
	// calculate(priceMap, inFile);m
	// for (std::multimap<std::string, double>::const_iterator it = inFile.begin(); it != inFile.end(); it++)
		// std::cout << it->first << " " << it->second << std::endl;

	// program uzyje input.txt->second aby przemnozyc wartosc z danej daty z data.csv->second
	// i wyswietlic na standard output.

	//lowerbound funkcja mapy.

	/* function to pass Map to calculation and input.txt */
	// std::ifstream file(name.c_str());  //ofstream construction with std::string converted to char *
	/* for printing function
	if (index == std::string::npos)
		{
			std::cout << "Bad input" << std::endl;
			continue;
		}*/
	return 0;
}