#include "BitcoinExchange.hpp"

void calculate(std::string& valueStr, std::multimap<std::string, double>& priceMap, std::string& date, double& value)
{
    value = std::atof(valueStr.c_str()); 												//atof ignoring leading and trailing white char
	std::multimap<std::string, double>::const_iterator it = priceMap.upper_bound(date); //lower_bound because there might not be exact date
	if (it != priceMap.begin())
		it--;
	else
	{
		std::cout << "There is no such or earlier date" << std::endl;
		return ;
	}
	if (it->first != date && it != priceMap.end())  															//if iterator is valid
		std::cout << date << " =>" << valueStr << " = " << it->second * value << std::endl;
	return ;
}

bool checkDate(std::string& date)
{
	int size = date.size();
	if (size != 10 && date != "date")/*|| size != 4*/
	{
		std::cout << "Error: Bad date formattt" << std::endl; 
		return true;
	}
	else if (date[4] != '-' && date[7] != '-' && date != "date")
	{
		std::cout << date[4] << std::endl;
		std::cout << "Error: Bad date format" << std::endl;
		return true;
	}
	return false;
}

bool checkLine(std::string line, size_t& indexIn, std::string& valueStr)
{
	double value = std::atof(valueStr.c_str());
	if (line.empty())
		return true;
	try
	{
		if (indexIn == std::string::npos)
		{
			std::cout << "Error: bad input => " << line << std::endl;
			return true;
		}
		else if (value < 0)
			throw std::invalid_argument("Error: not a positive number.");
		else if (value > 1000)
			throw std::invalid_argument("Error: too large a number.");
	}
	catch (std::invalid_argument& e) { std::cout << e.what() << std::endl; return true;};
	return false;
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
		if (checkDate(date))
			continue;
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
	if (argc != 2)
		return std::cerr << "Error: could not open a file" << std::endl, -1;
	std::ifstream DbFile("data.csv");
	if (!DbFile.is_open())
		return std::cerr << "Couldn't open such file" << std::endl, -1;
	std::multimap<std::string, double> priceMap = processDb(DbFile);
	std::multimap<std::string, double> inFile = processInFile(argv[1], priceMap);
	// for (std::multimap<std::string, double>::const_iterator it = inFile.begin(); it != inFile.end(); it++)
		// std::cout << it->first << " " << it->second << std::endl;
	return 0;
}