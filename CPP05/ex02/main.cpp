/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrauer <kbrauer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 12:37:19 by kbrauer           #+#    #+#             */
/*   Updated: 2025/02/27 18:12:09 by kbrauer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
	
	Bureaucrat 				Larry("Larry", 5);
	Bureaucrat 				Michael("Michael", 150);
	ShrubberyCreationForm	SForm("Garden");

	std::cout << Larry << std::endl;
	std::cout << Michael << std::endl;

	std::cout << std::endl;
	
	std::cout << SForm << std::endl << std::endl;
	
	try	{
		std::cout << "---Michael signes SForm---" << std::endl;
		Michael.signAForm(SForm);
	}
	catch(const std::exception& e)	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << SForm << std::endl;
	
	try	{
		std::cout << "---Michael executes SForm ---" << std::endl;
		Michael.executeForm(SForm);
	}
	catch(const std::exception& e)	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << SForm << std::endl;

	try	{
		std::cout << "---Larry executes SForm ---" << std::endl;
		Larry.executeForm(SForm);
	}
	catch(const std::exception& e)	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << SForm << std::endl;
	
	try	{
		std::cout << "---Larry signes SForm---" << std::endl;
		Larry.signAForm(SForm);
	}
	catch(const std::exception& e)	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << SForm << std::endl;

	try	{
		std::cout << "---Larry signes SForm again---" << std::endl;
		Larry.signAForm(SForm);
	}
	catch(const std::exception& e)	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << SForm << std::endl;
	
	try	{
		std::cout << "---Larry executes SForm ---" << std::endl;
		Larry.executeForm(SForm);
	}
	catch(const std::exception& e)	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << SForm << std::endl;
	

//#########################################################################################

	// std::cout << std::endl;

	// Bureaucrat 				Larry("Larry", 5);
	// Bureaucrat 				Michael("Michael", 150);
	// RobotomyRequestForm		RForm("Elon");

	// std::cout << Larry << std::endl;
	// std::cout << Michael << std::endl;

	// std::cout << std::endl;
	
	// std::cout << RForm << std::endl << std::endl;
	
	// try	{
	// 	std::cout << "---Michael signes RForm---" << std::endl;
	// 	Michael.signAForm(RForm);
	// }
	// catch(const std::exception& e)	{
	// 	std::cerr << e.what() << std::endl;
	// }
	// std::cout << RForm << std::endl;
	
	// try	{
	// 	std::cout << "---Michael executes RForm ---" << std::endl;
	// 	Michael.executeForm(RForm);
	// }
	// catch(const std::exception& e)	{
	// 	std::cerr << e.what() << std::endl;
	// }
	// std::cout << RForm << std::endl;

	// try	{
	// 	std::cout << "---Larry executes RForm ---" << std::endl;
	// 	Larry.executeForm(RForm);
	// }
	// catch(const std::exception& e)	{
	// 	std::cerr << e.what() << std::endl;
	// }
	// std::cout << RForm << std::endl;
	
	// try	{
	// 	std::cout << "---Larry signes RForm---" << std::endl;
	// 	Larry.signAForm(RForm);
	// }
	// catch(const std::exception& e)	{
	// 	std::cerr << e.what() << std::endl;
	// }
	// std::cout << RForm << std::endl;

	// try	{
	// 	std::cout << "---Larry signes RForm again---" << std::endl;
	// 	Larry.signAForm(RForm);
	// }
	// catch(const std::exception& e)	{
	// 	std::cerr << e.what() << std::endl;
	// }
	// std::cout << RForm << std::endl;
	
	// try	{
	// 	std::cout << "---Larry executes RForm ---" << std::endl;
	// 	Larry.executeForm(RForm);
	// }
	// catch(const std::exception& e)	{
	// 	std::cerr << e.what() << std::endl;
	// }
	// std::cout << RForm << std::endl;
	
	// std::cout << std::endl;

	
//#########################################################################################
	
	
	// std::cout << std::endl;
	
	// Bureaucrat 				Larry("Larry", 5);
	// Bureaucrat 				Michael("Michael", 150);
	// PresidentialPardonForm	PForm("January 6th criminal");

	// std::cout << Larry << std::endl;
	// std::cout << Michael << std::endl;

	// std::cout << std::endl;
	
	// std::cout << PForm << std::endl << std::endl;
	
	// try	{
	// 	std::cout << "---Michael signes PForm---" << std::endl;
	// 	Michael.signAForm(PForm);
	// }
	// catch(const std::exception& e)	{
	// 	std::cerr << e.what() << std::endl;
	// }
	// std::cout << PForm << std::endl;
	
	// try	{
	// 	std::cout << "---Michael executes PForm ---" << std::endl;
	// 	Michael.executeForm(PForm);
	// }
	// catch(const std::exception& e)	{
	// 	std::cerr << e.what() << std::endl;
	// }
	// std::cout << PForm << std::endl;

	// try	{
	// 	std::cout << "---Larry executes PForm ---" << std::endl;
	// 	Larry.executeForm(PForm);
	// }
	// catch(const std::exception& e)	{
	// 	std::cerr << e.what() << std::endl;
	// }
	// std::cout << PForm << std::endl;
	
	// try	{
	// 	std::cout << "---Larry signes PForm---" << std::endl;
	// 	Larry.signAForm(PForm);
	// }
	// catch(const std::exception& e)	{
	// 	std::cerr << e.what() << std::endl;
	// }
	// std::cout << PForm << std::endl;

	// try	{
	// 	std::cout << "---Larry signes PForm again---" << std::endl;
	// 	Larry.signAForm(PForm);
	// }
	// catch(const std::exception& e)	{
	// 	std::cerr << e.what() << std::endl;
	// }
	// std::cout << PForm << std::endl;
	
	// try	{
	// 	std::cout << "---Larry executes PForm ---" << std::endl;
	// 	Larry.executeForm(PForm);
	// }
	// catch(const std::exception& e)	{
	// 	std::cerr << e.what() << std::endl;
	// }
	// std::cout << PForm << std::endl;
	

	// std::cout << std::endl;

	
	return 0;
}
