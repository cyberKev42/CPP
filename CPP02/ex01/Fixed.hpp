/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevin <kevin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 16:50:57 by kbrauer           #+#    #+#             */
/*   Updated: 2025/01/18 20:12:43 by kevin            ###   ########.fr       */
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
	Fixed& operator=(const Fixed& N);
	~Fixed();
	float toFloat( void ) const;
	int toInt( void ) const;
	int getRawBits( void ) const;
	void setRawBits( int const raw );
};

std::ostream& operator<<(std::ostream& os, const Fixed& f);

#endif
