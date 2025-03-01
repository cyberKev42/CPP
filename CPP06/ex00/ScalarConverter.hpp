/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrauer <kbrauer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 13:55:46 by kbrauer           #+#    #+#             */
/*   Updated: 2025/03/01 15:55:54 by kbrauer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARVONCERTER_HPP

#include <string>
#include <iostream>

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