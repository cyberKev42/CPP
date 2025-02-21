/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrauer <kbrauer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 12:37:19 by kbrauer           #+#    #+#             */
/*   Updated: 2025/02/21 18:26:32 by kbrauer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() {

	Bureaucrat noName;
	Bureaucrat Larry("Larry", 3);
	Bureaucrat Larry_copy(Larry);
	Bureaucrat Michael("Michael", 150);

	std::cout << noName << std::endl;
	std::cout << Larry << std::endl;
	std::cout << Larry_copy << std::endl;
	std::cout << Michael << std::endl;

	std::cout << std::endl;
	
	noName = Michael;
	std::cout << noName << std::endl << std::endl;

	// Constructor exception
	std::cout << "Constructor exception" << std::endl;
	try
	{
		Bureaucrat Hank("Hank", 0);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	// Increment exception
	std::cout << std::endl << "Increment exception" << std::endl;
	try
	{
		Larry.incrementGrade(3);
		std::cout << Larry << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	// Decrement exception
	std::cout << std::endl << "Decrement exception" << std::endl;
	try
	{
		Michael.decrementGrade(1);
		std::cout << Michael << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl;

	return 0;
}
