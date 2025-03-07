/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevin <kevin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 13:55:44 by kbrauer           #+#    #+#             */
/*   Updated: 2025/03/07 22:17:36 by kevin            ###   ########.fr       */
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
	std::string dezimal = "";
	if ((str.length() > 1 && ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z')))
		|| (str.length() == 1 && !((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z')
		|| (str[i] >= '0' && str[i] <= '9'))))
	{
		std::cout 	<< "1: " << str << std::endl;
		throw InvalidInput();
	}
	if (str[i] == '+' || str[i] == '-')
		sign = 1;
	while (str[i + sign]) {
		if (floaty)
			throw InvalidInput();
		if (i == 0 && str.length() > 1 && (str[i + sign] < '0' || str[i + sign] > '9'))
		{
			std::cout 	<< "2: " << str << std::endl;	
			throw InvalidInput();
		}
		if (((((str[i + sign] >= 'a' && str[i + sign] <= 'z') && str[i + sign] != 'f') && str[i + sign] != '.'
				&& (str[i + sign] < '0' || str[i + sign] > '9')) || (str[i + sign] == '.' && comma)
				|| (str[i + sign] >= 'A' && str[i + sign] <= 'Z')) && str.length() > 1 )
		{
			std::cout 	<< "3: " << str << std::endl;
			throw InvalidInput();
		}
		if (str[i + sign] == 'f')
			floaty = true;
		if (comma && (str[i + sign] <= '9' && str[i + sign] >= '1'))
			dezimal = "";
		if (str[i + sign] == '.') {
			comma = true;
			dezimal = ".0";
		}
		i++;
	}
	
	
	float 	number_f;
	int		number_i;
	char	number_c;
	double	number_d;
	if (floaty) { 					// string is a float
		if (!comma)
			dezimal = ".0";
		number_f = stof(str);
		number_i = number_f;
		number_c = number_f;
		number_d = number_f;
	}
	else if (comma) { 				// string is a double
		number_d = atof(str.c_str());
		number_f = static_cast<float>(number_d);
		number_i = static_cast<int>(number_d);
		number_c = static_cast<int>(number_d);

		std::cout 	<< number_d << " number_d" << std::endl;
		// NOT enough decimal points, should hold up to 15
	}
	else if ((str[0] >= 'A' && str[0] <= 'Z') || (str[0] >= 'a' && str[0] <= 'z')) { 	// string is a char
		dezimal = ".0";
		number_c = str[0];
		number_i = number_c;
		number_f = number_c;
		number_d = number_c;
	}
	else {							// string is an int
		
		number_i = stoi(str);
		number_c = number_i;
		number_f = number_i;
		number_d = number_i;
	}
	int len;
	if (str.length() > 17)
		len = 17;
	else
		len = str.length() - 2 - sign;
	std::cout 	<< len << std::endl;
	if (number_i < 32 || number_i > 126)
		std::cout 	<< "char: Non displayable" << std::endl;
	else
		std::cout 	<< "char: '" << number_c << "'" << std::endl;
	std::cout	<< "int: " << number_i << std::endl
				<< "float: " << std::setprecision(len) << number_f << dezimal << "f" << std::endl
				<< "double: " << std::setprecision(len) << number_d << dezimal << std::endl;




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