#include "BitcoinExchange.hpp"

void calculate(std::string& valueStr, std::multimap<std::string, double>& priceMap, std::string& date, double& value)
{
    value = std::atof(valueStr.c_str()); 												//atof ignoring leading and trailing white char
	std::multimap<std::string, double>::const_iterator it = priceMap.upper_bound(date); //lower_bound because there might not be exact date
	if (it != priceMap.begin())
	{
		it--;
		std::cout << date << " =>" << valueStr << " = " << it->second * value << std::endl;
	}
	else
	{
		std::cout << "There is no such or earlier date" << std::endl;
		return ;
	}
	return ;
}

bool checkDate(std::string& date, std::string line)
{
	try {
		int size = date.size();
		if (date == "date")
			return true;
		if (size != 10)
			throw std::invalid_argument("Error: bad input => ");
		else if (date[4] != '-' && date[7] != '-' && date != "date")
			throw std::invalid_argument("Error: bad input => ");
		size_t year_index = date.find("-");
		int year = std::atoi((date.substr(0, year_index)).c_str());
		if (year < 2009 || year > 2022)
			throw std::invalid_argument("Error: bad input => ");
		std::string monthStr = date.substr(year_index + 1, 2);
		int month = atoi(monthStr.c_str());
		if (month < 1 || month > 12)
			throw std::invalid_argument("Error: bad input => ");
		std::string dayStr = date.substr(year_index + 4, 2);
		int day = atoi(dayStr.c_str());
		int OneMonths[7] = {1, 3, 5, 7, 8, 10, 12};
		int* it = std::find(OneMonths, OneMonths + 7, month);
		if (it == OneMonths + 7)							//outside array - month is not in array
		{
			if (month == 2 && day > 28 && ((year % 400 != 0 && year % 100 == 0) || year % 4 != 0 ))
				throw std::invalid_argument("Error: bad input => ");
			else if (monthStr == "02" && day > 28)
				throw std::invalid_argument("Error: bad input => ");
			else if (day > 30)
				throw std::invalid_argument("Error: bad input => ");
		}
		else if (day > 31 || day < 1)
			throw std::invalid_argument("Error: bad input => ");
	}
	catch (std::invalid_argument& e) {std::cout << "Error: bad input => " << line << std::endl; return true;}
	return false;
}

bool checkLine(std::string& valueStr)
{
	double value = std::atof(valueStr.c_str());
	try
	{
		if (value < 0)
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
		if (line.empty())
			continue;
		size_t index = line.find("|");
		if (index == std::string::npos)
		{
			std::cout << "Error: bad input => " << line << std::endl; continue;
		}
		std::string date = line.substr(0, index - 1);
		std::string valueStr = line.substr(index + 1);
		if (checkLine(valueStr))
			continue;
		if (checkDate(date, line))
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
	return 0;
}