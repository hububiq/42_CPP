#ifndef ORTHODOX_H
# define ORTHODOX_H
# include <iostream>
# include <string>

class Fixed
{
	private:
		int					fixedPointNb;
		static const int	fractionBits = 8;
	public:
		Fixed();					//regular constructor
		Fixed(const Fixed& other);	//copy constructor
		Fixed& operator=(const Fixed& other); 
		~Fixed();
		int 	getRawBits() const;
		void 	setRawBits(int const raw);

};

# endif