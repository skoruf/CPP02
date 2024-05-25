#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class	Fixed{

	private:
		int	value;
		static const int	valueF;
		
	
	public:
	
		//default constructor
		Fixed();
		Fixed(const int value);
		Fixed(const float value);
		//copy constructor
		Fixed(const Fixed& copy);
		//copy assignment operator overload
		Fixed& operator=(const Fixed&);
		//destructor
		~Fixed();
		int	getRawBits( void ) const;
		void	setRawBits( int const raw );
		float	toFloat( void ) const;
		int	toInt( void ) const;
};

std::ostream&	operator<<(std::ostream &out, const Fixed& value);

#endif
