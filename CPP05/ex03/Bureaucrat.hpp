/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrauer <kbrauer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 12:37:26 by kbrauer           #+#    #+#             */
/*   Updated: 2025/03/29 17:25:00 by kbrauer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include "AForm.hpp"

class AForm;

class Bureaucrat {
private:
	const std::string 	_name;
	int					_grade;
public:
	Bureaucrat();
	Bureaucrat(std::string name, int num);
	Bureaucrat(Bureaucrat& original);
	Bureaucrat& operator=(const Bureaucrat& B);
	~Bureaucrat();
	const std::string getName() const;
	int			getGrade() const;
	void		incrementGrade(int n);
	void		decrementGrade(int n);
	void		signAForm(AForm& F);
	void 		executeForm(AForm const & form);
	class GradeTooHighException : public std::exception {
	public:
		const char* what() const throw() {
			return "Error: Grade too high!";
		} 	
	};
	class GradeTooLowException : public std::exception {
	public:
		const char* what() const throw() {
			return "Error: Grade too low!";
		}
	};
	class NotSignedException : public std::exception {
		const char* what() const throw() {
			return "Error: Form not signed!";
		}
	};
};

std::ostream& operator<<(std::ostream& os, Bureaucrat& B);

#endif




// A Bureaucrat must have:
// • A constant name.
// • And a grade that ranges from 1 (highest possible grade) to 150 (lowest possible
// grade).

// Any attempt to instantiate a Bureaucrat using an invalid grade must throw an exception:
// either a Bureaucrat::GradeTooHighException or a Bureaucrat::GradeTooLowException.

// You will provide getters for both these attributes: getName() and getGrade(). Implement also two member functions to increment or decrement the bureaucrat grade. If
// the grade is out of range, both of them will throw the same exceptions as the constructor.