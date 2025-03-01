/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrauer <kbrauer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 13:55:44 by kbrauer           #+#    #+#             */
/*   Updated: 2025/03/01 18:04:34 by kbrauer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(ScalarConverter& original) {}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& S) {
	return *this;
}
ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convert(std::string str) {
	std::cout << "Convert " << str << " to:" << std::endl;
	int		sign = 0;
	int		i = 0;
	bool	comma = false;
	bool	floaty = false;
	if (str.length() > 1 && ((str[i] > 'A' && str[i] < 'Z') || (str[i] > 'a' && str[i] < 'z')))
	{
		std::cout 	<< "1" << str << std::endl;
		throw InvalidInput();
	}
	if (str[i] == '+' || str[i] == '-')
		sign = 1;
	while (str[i + sign]) {
		if (i == 0 && str.length() > 1 && (str[i + sign] < '0' || str[i + sign] > '9'))
		{
			std::cout 	<< "2" << str << std::endl;	
			throw InvalidInput();
		}
		if (((((str[i + sign] > 'a' && str[i + sign] < 'z') && str[i + sign] != 'f') && str[i + sign] != '.'
				&& (str[i + sign] < '0' || str[i + sign] > '9')) || (str[i] == '.' && comma) || (str[i] == 'f' && floaty)
				|| (str[i] > 'A' && str[i] < 'Z')) && str.length() > 1)
		{
			std::cout 	<< "3" << str << std::endl;
			throw InvalidInput();
		}
		if (str[i] == '.')
			comma = true;
		if (str[i] == 'f')
			floaty = true;
		i++;
	}
	
	

	if (floaty) {
		float number = stof(str);
		std::cout 	<< "char: " << "Non displayable" << std::endl     // CONVERT number to CHAR
					// << "int: " << (int)str[0] << std::endl    CONVERT number to INT
					<< "float: " << number << "f" << std::endl
					// << "double: " << (double)str[0] << ".0" << std::endl;    CONVERT number to DOUBLE
		
	}
	else if
		(comma)
		double number = stod(str);
	else
		int number = stoi(str);


/*


	
	if (str.length() == 1 && (str[i + sign] < '0' || str[i + sign] > '9')) {
	}
	else if (floaty) {
		std::cout 	<< "char: " << '0' + stoi(str) << std::endl
					<< "int: " << stoi(str.substr(0, str.length() - 1)) << std::endl
					<< "float: " << str << std::endl
					<< "double: " << stod(str.substr(0, str.length() - 1)) << std::endl;
	}
	else if (comma) {
		
	}
	
	
	
*/


	std::cout << "---Correct Input---" << std::endl;
}

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