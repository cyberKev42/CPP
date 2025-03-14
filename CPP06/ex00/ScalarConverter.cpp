/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevin <kevin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 13:55:44 by kbrauer           #+#    #+#             */
/*   Updated: 2025/03/14 18:20:46 by kevin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(ScalarConverter& original) {}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& S) {
	return *this;
}
ScalarConverter::~ScalarConverter() {}

static void typeChar(char c, std::string dezimal) {
	char	number_c = c;
	int		number_i = number_c;
	float	number_f = number_c;
	double	number_d = number_c;

	std::cout 	<< "char: '" 	<< number_c 			<< "'" 	<< std::endl
				<< "int: " 		<< number_i 					<< std::endl
				<< "float: " 	<< number_f << dezimal 	<< "f" 	<< std::endl
				<< "double: " 	<< number_d << dezimal 			<< std::endl;
}

static void typeInt(std::string str, std::string dezimal) {
	
	int		number_i;
	char	number_c;
	float	number_f;
	double	number_d;
	number_i = atoi(str.c_str());
	number_c = number_i;
	number_f = static_cast<float>(number_i);
	number_d = static_cast<double>(number_i);
	if (number_i < 32 || number_i > 126)
		std::cout 	<< "char: Non displayable" << std::endl;
	else
		std::cout 	<< "char: '" << number_c << "'" << std::endl;
	std::cout	<< "int: " 		<< number_i 					<< std::endl
				<< "float: " 	<< std::setprecision(10) << number_f << dezimal 	<< "f" 	<< std::endl
				<< "double: " 	<< std::setprecision(10) << number_d << dezimal 			<< std::endl;
}

static void typeFloat(std::string str, std::string dezimal) {
	float	number_f = atof(str.c_str());
	int		number_i = static_cast<int>(number_f);
	char	number_c = static_cast<char>(number_f);
	double	number_d = static_cast<double>(number_f);
	std::string tmp = str.erase(str.length());
	std::string infinity_sign = "";
	if (number_i < 32 || number_i > 126 || number_d != floor(number_d))
		std::cout 	<< "char: Non displayable" << std::endl;
	else
		std::cout 	<< "char: '" << number_c << "'" << std::endl;
	if (number_f == -std::numeric_limits<float>::infinity()
		|| number_f == std::numeric_limits<float>::infinity()
		|| number_f != number_f
		|| (static_cast<double>(atof(tmp.c_str())) < INT_MIN || static_cast<double>(atof(tmp.c_str())) > INT_MAX))
		std::cout	<< "int: Impossible" 					<< std::endl;
	else
		std::cout	<< "int: " 		<< number_i 					<< std::endl;
	if (number_f == std::numeric_limits<float>::infinity())
		infinity_sign = "+";
	std::cout << number_i << std::endl << std::fixed << std::setprecision(38) << number_f << std::endl;
	if (number_i < number_f)
		std::cout << "wtf" << std::endl;
	if (number_i == number_f)
		std::cout	<< "float: " 	<< std::fixed << std::setprecision(1) << infinity_sign << number_f 	<< "f" 	<< std::endl;
	else
		std::cout	<< "float: " 	<< std::fixed << std::setprecision(7) << infinity_sign << number_f 	<< "f" 	<< std::endl;
	if (number_i == number_d)
		std::cout	<< "double: " 	<< std::setprecision(1) << infinity_sign << number_d 			<< std::endl;
	else
		std::cout	<< "double: " 	<< std::setprecision(15) << infinity_sign << number_d 			<< std::endl;
}

static void typeDouble(std::string str, std::string dezimal) {
	double	number_d = atof(str.c_str());
	int		number_i = static_cast<int>(number_d);
	char	number_c = static_cast<char>(number_d);
	float	number_f = static_cast<float>(number_d);
	std::string infinity_sign = "";
	if (number_i < 32 || number_i > 126 || number_d != floor(number_d))
		std::cout 	<< "char: Non displayable" << std::endl;
	else if (str == "nan" || str == "-inf" || str == "+inf")
		std::cout 	<< "char: Impossible" << std::endl;
	else
		std::cout 	<< "char: '" << number_c << "'" << std::endl;
	if (number_d == -std::numeric_limits<double>::infinity()		// check for negativ infinity -inf
		|| number_d == std::numeric_limits<double>::infinity()		// check for positiv infinity +inf
		|| number_d != number_d					// check for nan, comparing nan to nan is always false
		|| (number_d < INT_MIN || number_d > INT_MAX))
		std::cout	<< "int: Impossible" 					<< std::endl;
	else
		std::cout	<< "int: " 		<< number_i 					<< std::endl;
	if (number_d == std::numeric_limits<double>::infinity())
		infinity_sign = "+";
	if (number_i == number_f)
		std::cout	<< "float: " 	<< std::fixed << std::setprecision(1) << infinity_sign << number_f 	<< "f" 	<< std::endl;
	else
		std::cout	<< "float: " 	<< std::fixed << std::setprecision(7) << infinity_sign << number_f 	<< "f" 	<< std::endl;
	if (number_i == number_d)
		std::cout	<< "double: " 	<< std::setprecision(1) << infinity_sign << number_d 			<< std::endl;
	else
		std::cout	<< "double: " 	<< std::setprecision(15) << infinity_sign << number_d 			<< std::endl;
}

static void typePseudo(std::string str) {
	if (str == "nan" || str == "-inf" || str == "+inf")
		typeDouble(str, "");
	else
		typeFloat(str, "");
}

void ScalarConverter::convert(std::string str) {
	int		sign = 0;
	int		i = 0;
	bool	comma = false;
	bool	floaty = false;
	std::string dezimal = "";
	if (str == "-inf" || str == "+inf" || str == "-inff" || str == "+inff" || str == "nan" || str == "nanf") {
		typePseudo(str);
		return;
	}
	if ((str.length() > 1 && ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z')))
		|| (str.length() == 1 && !((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z')
		|| (str[i] >= '0' && str[i] <= '9'))))
		throw InvalidInput();
	if (str[i] == '+' || str[i] == '-')
		sign = 1;
	while (str[i + sign]) {
		if (floaty)
			throw InvalidInput();
		if (i == 0 && str.length() > 1 && (str[i + sign] < '0' || str[i + sign] > '9'))
			throw InvalidInput();
		if (((((str[i + sign] >= 'a' && str[i + sign] <= 'z') && str[i + sign] != 'f') && str[i + sign] != '.'
				&& (str[i + sign] < '0' || str[i + sign] > '9')) || (str[i + sign] == '.' && comma)
				|| (str[i + sign] >= 'A' && str[i + sign] <= 'Z')) && str.length() > 1 )
			throw InvalidInput();
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
	if (floaty && !comma)
		throw InvalidInput();
	
	if (floaty) { 					// string is a float
		typeFloat(str, dezimal);
		return;
	}
	else if (comma) { 				// string is a double
		typeDouble(str, dezimal);
		return;
	}
	else if ((str[0] >= 'A' && str[0] <= 'Z') || (str[0] >= 'a' && str[0] <= 'z')) { 	// string is a char
		dezimal = ".0";
		typeChar(str[0], dezimal);
		return;
	}
	else {							// string is an int
		long long number_check = atol(str.c_str());
		if (number_check < INT_MIN || number_check > INT_MAX)
			throw InvalidInput();
		dezimal = ".0";
		typeInt(str, dezimal);
		return;
	}
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