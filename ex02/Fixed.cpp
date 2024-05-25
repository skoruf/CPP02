#include "Fixed.hpp"
#include <iostream>
#include <cmath>

const int	Fixed::valueF = 8;

//default constructor
Fixed::Fixed(){
	std::cout <<"Default constructor called" <<std::endl;
	this->value = 0;
}

Fixed::Fixed(const int value){
	//std::cout <<"Default constructor called" <<std::endl;
	this->value = value <<this->valueF;
}

Fixed::Fixed(const float value){
	//std::cout <<"Default constructor called" <<std::endl;
	this->value = roundf(value * (1 << this->valueF));
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

float	Fixed::toFloat( void ) const{

	return (float)this->value / (1 << this->valueF);
}

int	Fixed::toInt( void ) const{

	return this->value >> this->valueF;
}

std::ostream&	operator<<(std::ostream &out, const Fixed& value){

	out << value.toFloat();
	return out;
}
//comparison
bool	Fixed::operator>(const Fixed& value){
	if (this->value > value.value)
		return true;
	return false;
}

bool	Fixed::operator<(const Fixed& value){
	if (this->value < value.value)
		return true;
	return false;
}

bool	Fixed::operator>=(const Fixed& value){
	if (this->value >= value.value)
		return true;
	return false;
}

bool	Fixed::operator<=(const Fixed& value){
	
	return this->value <= value.value;
}

bool	Fixed::operator==(const Fixed& value){
	if (this->value == value.value)
		return true;
	return false;
}

bool	Fixed::operator!=(const Fixed& value){
	if (this->value != value.value)
		return true;
	return false;
}
//arithmetic
float	Fixed::operator+(const Fixed& value){

	return this->toFloat() + value.toFloat();
}

float	Fixed::operator-(const Fixed& value){

	return this->toFloat() - value.toFloat();
}

float	Fixed::operator*(const Fixed& value){

	return this->toFloat() * value.toFloat();
}

float	Fixed::operator/(const Fixed& value){

	return this->toFloat() / value.toFloat();
}

Fixed&	Fixed::operator++(){
	this->value++;
	return *this;
}

Fixed	Fixed::operator++(int){
	Fixed old = *this;
	operator++();
	return old;
}

Fixed&	Fixed::operator--(){
	this->value--;
	return *this;
}

Fixed	Fixed::operator--(int){
	Fixed old = *this;
	operator--();
	return old;
}

//min max
Fixed&	Fixed::min(Fixed& a, Fixed& b){
	
	return a < b ? a:b;
}

const Fixed&	Fixed::min(const Fixed& a, const Fixed& b){
	
	return a.value < b.value ? a:b;
}

Fixed&	Fixed::max(Fixed& a, Fixed& b){
	
	return a > b ? a:b;
}

const Fixed&	Fixed::max(const Fixed& a, const Fixed& b){
	
	return a.value > b.value ? a:b;
}
