/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrauer <kbrauer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 17:30:53 by kbrauer           #+#    #+#             */
/*   Updated: 2025/01/11 18:38:14 by kbrauer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int main() {
std::string var = "HI THIS IS BRAIN";
std::string *stringPTR = &var;
std::string &stringREF = var;

std::cout << &var << std::endl;
std::cout << stringPTR << std::endl;
std::cout << &stringREF << std::endl;

std::cout << var << std::endl;
std::cout << *stringPTR << std::endl;
std::cout << stringREF << std::endl;

}

// Write a program that contains:
// • A string variable initialized to "HI THIS IS BRAIN".
// • stringPTR: A pointer to the string.
// • stringREF: A reference to the string.
// Your program has to print:
// • The memory address of the string variable.
// • The memory address held by stringPTR.
// • The memory address held by stringREF.
// And then:
// • The value of the string variable.
// • The value pointed to by stringPTR.
// • The value pointed to by stringREF.