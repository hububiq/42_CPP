#include "BitcoinExchange.hpp"

// ToFix: still printing out of range values - adjust CONTINUE LINE 52.
// zero printed first, why?
// add formatting to output 

void calculate(std::string& valueStr, std::multimap<std::string, double>& priceMap, std::string& date, double& value)
{
    value = std::atof(valueStr.c_str()); 												//atof ignoring leading and trailing white char
	std::multimap<std::string, double>::const_iterator it = priceMap.lower_bound(date); //lower_bound because there might not be exact date
	if (it != priceMap.end())  															//if iterator is valid
		std::cout << it->second * value << std::endl;
	return ;
}

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

std::multimap<std::string, double> processInFile(std::string name, std::multimap<std::string, double>& priceMap)
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
		double value = 0;
		calculate(valueStr, priceMap, date, value);
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
	std::multimap<std::string, double> inFile = processInFile(argv[1], priceMap);
	// for (std::multimap<std::string, double>::const_iterator it = inFile.begin(); it != inFile.end(); it++)
		// std::cout << it->first << " " << it->second << std::endl;
	return 0;
}