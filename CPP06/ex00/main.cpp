/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevin <kevin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 14:14:34 by kbrauer           #+#    #+#             */
/*   Updated: 2025/03/14 15:33:31 by kevin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>

int main(int argc, char** argv) {
	
	if (argc != 2)
		return(std::cout << "Only 1 argument allowed" << std::endl, 1);
	try
	{
		ScalarConverter::convert(argv[1]);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
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