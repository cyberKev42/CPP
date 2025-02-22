/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrauer <kbrauer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 12:37:19 by kbrauer           #+#    #+#             */
/*   Updated: 2025/02/22 16:17:27 by kbrauer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
	std::cout << std::endl;
	
	Bureaucrat 	Larry("Larry", 3);
	Bureaucrat 	Michael("Michael", 150);
	Form		F1("Form 1", 50, 55);
	Form		F2("Form 2", 2, 55);

	std::cout << Larry << std::endl;
	std::cout << Michael << std::endl;

	std::cout << std::endl;
	
	std::cout << F1 << std::endl;
	std::cout << F2 << std::endl << std::endl;
	
	try	{
		std::cout << "---Michael signes Form 1---" << std::endl;
		Michael.signForm(F1);
	}
	catch(const std::exception& e)	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << F1 << std::endl;
	
	try	{
		std::cout << "---Larry signes Form 1---" << std::endl;
		Larry.signForm(F1);
	}
	catch(const std::exception& e)	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << F1 << std::endl;

	try	{
		std::cout << "---Larry signes Form 1 again---" << std::endl;
		Larry.signForm(F1);
	}
	catch(const std::exception& e)	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << F1 << std::endl;

	try	{
		std::cout << "---Larry signes Form 2---" << std::endl;
		Larry.signForm(F2);
	}
	catch(const std::exception& e)	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << F2 << std::endl;

	std::cout << std::endl << std::endl;
	try	{
		std::cout << "---Constructor exception Bureaucrat---" << std::endl;
		Bureaucrat Hank("Hank", 0);
	}
	catch(const std::exception& e)	{
		std::cerr << e.what() << std::endl;
	}
	
	try	{
		std::cout << std::endl << "---Constructor exception Form---" << std::endl;
		Form F9("Form 9", 0, 50);
	}
	catch(const std::exception& e)	{
		std::cerr << e.what() << std::endl;
	}
	
	try	{
		Form F9("Form 9", 50, 151);
	}
	catch(const std::exception& e)	{
		std::cerr << e.what() << std::endl;
	}

	try	{
		std::cout << std::endl << "---Increment exception Bureaucrat---" << std::endl;
		Larry.incrementGrade(3);
		std::cout << Larry << std::endl;
	}
	catch(const std::exception& e)	{
		std::cerr << e.what() << std::endl;
	}
	
	try	{
		std::cout << std::endl << "---Decrement exception Bureaucrat---" << std::endl;
		Michael.decrementGrade(1);
		std::cout << Michael << std::endl;
	}
	catch(const std::exception& e)	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;

	return 0;
}
