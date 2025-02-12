/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrauer <kbrauer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 13:37:38 by kbrauer           #+#    #+#             */
/*   Updated: 2025/02/12 17:14:29 by kbrauer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() {
	std::cout << "Default constructor called" << std::endl;
	this->setRawBits(0);
}
Fixed::Fixed(Fixed& original){
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

int Fixed::getRawBits( void ) const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->_n;
}

void Fixed::setRawBits( int const raw ) {
	this->_n = raw;
}
