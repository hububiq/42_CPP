#ifndef BITCOIN_EXCHANGE_HPP
# define BITCOIN_EXCHANGE_HPP
# include <set> //container of my choice
# include <iostream>
# include <string>
# include <fstream>
# include <map>
# include <cstdlib>
class BitcoinExchange
{
	private:
		// data?
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator=(const BitcoinExchange& other);
		~BitcoinExchange();
		//other member func
};

#endif