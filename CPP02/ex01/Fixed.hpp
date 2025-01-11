/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrauer <kbrauer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 16:50:57 by kbrauer           #+#    #+#             */
/*   Updated: 2025/01/11 18:34:53 by kbrauer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>

class Fixed{
private:
	int 				_n;
	static const int 	_f = 8;
public:
	Fixed();
	Fixed(const int);					// Default constructor
	Fixed(const float);					// Copy constructor
	Fixed& operator=(const Fixed& N);	// Copy assignment operator
	~Fixed();							// Destructor
	float toFloat( void ) const;
	int toInt( void ) const;
	
	int getRawBits( void ) const;
	void setRawBits( int const raw );
};


#endif

// Add the following public constructors and public member functions to your class:
// • A constructor that takes a constant integer as a parameter.
// It converts it to the corresponding fixed-point value. The fractional bits value is
// initialized to 8 like in exercise 00.
// • A constructor that takes a constant floating-point number as a parameter.
// It converts it to the corresponding fixed-point value. The fractional bits value is
// initialized to 8 like in exercise 00.
// • A member function float toFloat( void ) const;
// that converts the fixed-point value to a floating-point value.
// • A member function int toInt( void ) const;
// that converts the fixed-point value to an integer value.
// And add the following function to the Fixed class files:
// • An overload of the insertion («) operator that inserts a floating-point representation
// of the fixed-point number into the output stream object passed as parameter.