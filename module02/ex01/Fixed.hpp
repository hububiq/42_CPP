#ifndef FIXED_H
# define FIXED_H
# include <iostream>
# include <string>
# include <cmath>

class Fixed
{
	private:
		int					fixedPointNb;
		static const int	fractionalBits = 8;
	public:
		Fixed(const int value);
		Fixed(const float value);
		Fixed(const Fixed& other);
		Fixed& operator=(const Fixed& other);
		Fixed();
		~Fixed();
		int getRawbits() const;
		float toFloat() const;
		int toInt() const;
};

std::ostream& operator<<(std::ostream& out, const Fixed& src);

#endif