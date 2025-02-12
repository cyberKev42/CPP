/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrauer <kbrauer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 13:37:41 by kbrauer           #+#    #+#             */
/*   Updated: 2025/02/12 17:14:31 by kbrauer          ###   ########.fr       */
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
	Fixed();							// Default constructor
	Fixed(Fixed& original);				// Copy constructor
	Fixed& operator=(const Fixed& N);	// Copy assignment operator
	~Fixed();							// Destructor
	int getRawBits( void ) const;
	void setRawBits( int const raw );
};

#endif
