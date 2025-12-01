#ifndef FIXED_H
# define FIXED_H
# include <iostream>
# include <string>
# include <cmath>

class Fixed
{
	private:
		int					fixedPointNb;
		const static int	fractionalBits = 8;
	public:
		Fixed(const int value);
		Fixed(const float value);
		//copy constr
		//copy assignment overload
		Fixed();
		~Fixed();
		float toFloat() const;
		int toInt() const;
};

#endif