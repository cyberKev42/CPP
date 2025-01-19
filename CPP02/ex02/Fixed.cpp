/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevin <kevin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 17:03:35 by kevin             #+#    #+#             */
/*   Updated: 2025/01/19 20:04:08 by kevin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() {
	this->setRawBits(0);
}
Fixed::Fixed(const int int_n) {
    this->_n = int_n * (int)(pow(2, this->_f));
}
Fixed::Fixed(const float float_n) {
    this->_n = roundf(float_n * (pow(2, this->_f)));
}
Fixed::Fixed(const Fixed& original) {
	this->_n = original.getRawBits();
}
Fixed::~Fixed() {
}

Fixed& Fixed::operator=(const Fixed& N) {
	if (this != &N){
		_n = N.getRawBits();
	}
	return *this;
}

bool Fixed::operator>(const Fixed& N) {
    return this->_n > N._n;
}

bool Fixed::operator<(const Fixed& N) {
    return this->_n < N._n;
}

bool Fixed::operator>=(const Fixed& N) {
    return this->_n >= N._n;
}

bool Fixed::operator<=(const Fixed& N) {
    return this->_n <= N._n;
}

bool Fixed::operator==(const Fixed& N) {
    return this->_n == N._n;
}

bool Fixed::operator!=(const Fixed& N) {
    return this->_n != N._n;
}

Fixed Fixed::operator+(const Fixed& N) {
    Fixed tmp;
    tmp._n = this->_n + N._n;
    return tmp;
}

Fixed Fixed::operator-(const Fixed& N) {
    Fixed tmp;
    tmp._n = this->_n - N._n;
    return tmp;
}

Fixed Fixed::operator*(const Fixed& N) {
    Fixed tmp;
    tmp._n = (this->_n * N._n) / pow(2, this->_f);
    return tmp;
}

Fixed Fixed::operator/(const Fixed& N) {
    Fixed tmp;
    tmp._n = (this->_n / N._n) / pow(2, this->_f);
    return tmp;
}

Fixed& Fixed::operator++() {
    this->_n++;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed tmp = *this;
    this->_n++;
    return tmp;
}

Fixed& Fixed::operator--() {
    this->_n--;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed tmp = *this;
    this->_n--;
    return tmp;
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

Fixed& Fixed::min(Fixed &F1, Fixed &F2) {
    if (F1.getRawBits() < F2.getRawBits())
        return F1;
    else
        return F2;
}

const Fixed& Fixed::min(const Fixed &F1, const Fixed &F2) {
    if (F1.getRawBits() < F2.getRawBits())
        return F1;
    else
        return F2;
}

Fixed& Fixed::max(Fixed &F1, Fixed &F2) {
    if (F1.getRawBits() > F2.getRawBits())
        return F1;
    else
        return F2;
}

const Fixed& Fixed::max(const Fixed &F1, const Fixed &F2) {
    if (F1.getRawBits() > F2.getRawBits())
        return F1;
    else
        return F2;
}

std::ostream& operator<<(std::ostream& os, const Fixed& f) {
    os << f.toFloat();
    return os;
}
