#ifndef FIXED_HPP
# define FIXED_HPP

class	Fixed{

	private:
		int	value;
		static const int	valueF;
		
	
	public:
	
		//default constructor
		Fixed();
		//copy constructor
		Fixed(const Fixed& copy);
		//copy assignment operator overload
		Fixed& operator=(const Fixed&);
		//destructor
		~Fixed();
		
		int	getRawBits( void ) const;
		void	setRawBits( int const raw );

};

#endif
