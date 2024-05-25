#include "Fixed.hpp"
#include <iostream>

const int	Fixed::valueF = 8;

//default constructor
Fixed::Fixed() : value(0){
	std::cout <<"Default constructor called" <<std::endl;
	//this->value = 0;
}

//copy constructor
Fixed::Fixed(const Fixed& copy){
	
	std::cout <<"Copy contructor called" <<std::endl;
	*this = copy;
}

//copy assignment operator overload
Fixed& Fixed::operator=(const Fixed& copy){
	
	std::cout <<"Copy assignment operator called" <<std::endl;
	if (this != &copy)
		this->value = copy.getRawBits();
	return	*this;
}

//destructor
Fixed::~Fixed(){
	
	std::cout <<"Destructor called" <<std::endl;
}

int	Fixed::getRawBits( void ) const{

	std::cout <<"getRawBits member function called" <<std::endl;
	return this->value;
}

void	Fixed::setRawBits( int const raw ){

	this->value = raw;
}
