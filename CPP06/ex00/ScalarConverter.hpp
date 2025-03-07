/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevin <kevin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 13:55:46 by kbrauer           #+#    #+#             */
/*   Updated: 2025/03/07 20:52:21 by kevin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARVONCERTER_HPP

#include <string>
#include <iostream>
#include <iomanip>

class ScalarConverter {
private:
	ScalarConverter();
	ScalarConverter(ScalarConverter& original);
	ScalarConverter& operator=(const ScalarConverter& S);
	~ScalarConverter();
public:
	static void convert(std::string number);
	class NoInteger : public std::exception {
		const char* what() const noexcept override {
			return "Cant convert to Int!";
		}
	};
	class InvalidInput : public std::exception {
		const char* what() const noexcept override {
			return "Invalid Input!";
		}
	};
	
};

#endif

/*
./convert 0
char: Non displayable
int: 0
float: 0.0f
double: 0.0

./convert nan
char: impossible
int: impossible
float: nanf
double: nan

./convert 42.0f
char: '*'
int: 42
float: 42.0f
double: 42.0
*/