/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevin <kevin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 16:51:55 by kbrauer           #+#    #+#             */
/*   Updated: 2025/01/18 20:12:09 by kevin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() {
    std::cout << "Default constructor called" << std::endl;
	this->setRawBits(0);
}
Fixed::Fixed(const int int_n) {
	std::cout << "Int constructor called" << std::endl;
    this->_n = int_n * (int)(pow(2, this->_f));
}
Fixed::Fixed(const float float_n) {
	std::cout << "Float constructor called" << std::endl;
    this->_n = roundf(float_n * (pow(2, this->_f)));
}
Fixed::Fixed(const Fixed& original) {
    std::cout << "Copy constructor called" << std::endl;
	this->_n = original.getRawBits();
}
Fixed& Fixed::operator=(const Fixed& N){
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &N){
		_n = N.getRawBits();
	}
	return *this;
}
Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

float Fixed::toFloat( void ) const {
	
    return (_n / pow(2, this->_f));
}

int Fixed::toInt( void ) const {
    return (_n / pow(2, this->_f));
}

int Fixed::getRawBits( void ) const {
	return this->_n;
}

void Fixed::setRawBits( int const raw ) {
	this->_n = raw;
}

std::ostream& operator<<(std::ostream& os, const Fixed& f) {
    os << f.toFloat();
    return os;
}