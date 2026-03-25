#ifndef BITCOIN_EXCHANGE_HPP
# define BITCOIN_EXCHANGE_HPP
# include <set>
# include <iostream>
# include <string>
# include <fstream>
# include <map>
# include <cstdlib>
# include <stdexcept>
# include <algorithm>
class BitcoinExchange
{
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator=(const BitcoinExchange& other);
		~BitcoinExchange();
};

#endif