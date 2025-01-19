/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevin <kevin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 17:03:50 by kevin             #+#    #+#             */
/*   Updated: 2025/01/19 20:01:05 by kevin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>
#include <cmath>

class Fixed{
private:
	int 				_n;
	static const int 	_f = 8;
public:
	Fixed();
	Fixed(const int int_n);
	Fixed(const float float_n);
	Fixed(const Fixed& original);
	~Fixed();
	Fixed& operator=(const Fixed& N);
    bool operator>(const Fixed& N);
    bool operator<(const Fixed& N);
    bool operator>=(const Fixed& N);
    bool operator<=(const Fixed& N);
    bool operator==(const Fixed& N);
    bool operator!=(const Fixed& N);
    Fixed operator+(const Fixed& N);
    Fixed operator-(const Fixed& N);
    Fixed operator*(const Fixed& N);
    Fixed operator/(const Fixed& N);
    Fixed& operator++();
    Fixed operator++(int);
    Fixed& operator--();
    Fixed operator--(int);
	float toFloat( void ) const;
	int toInt( void ) const;
	int getRawBits( void ) const;
	void setRawBits( int const raw );
    static Fixed& min(Fixed& F1, Fixed& F2);
    static const Fixed& min(const Fixed& F1, const Fixed& F2);
    static Fixed& max(Fixed& F1, Fixed& F2);
    static const Fixed& max(const Fixed& F1, const Fixed& F2);    
};

std::ostream& operator<<(std::ostream& os, const Fixed& f);

#endif
