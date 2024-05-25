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
		//comparison
		bool	operator>(const Fixed& value);
		bool	operator<(const Fixed& value);
		bool	operator>=(const Fixed& value);
		bool	operator<=(const Fixed& value);
		bool	operator==(const Fixed& value);
		bool	operator!=(const Fixed& value);
		//arithmetic
		float	operator+(const Fixed&);
		float	operator-(const Fixed&);
		float	operator*(const Fixed&);
		float	operator/(const Fixed&);
		Fixed&	operator++();
		Fixed	operator++(int);
		Fixed&	operator--();
		Fixed	operator--(int);
		
		//min max
		static Fixed&	min(Fixed& a, Fixed& b);
		static const Fixed&	min(const Fixed& a, const Fixed& b);
		static Fixed&	max(Fixed& a, Fixed& b);
		static const Fixed&	max(const Fixed& a, const Fixed& b);
};

std::ostream&	operator<<(std::ostream &out, const Fixed& value);

#endif
