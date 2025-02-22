/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrauer <kbrauer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 13:28:34 by kbrauer           #+#    #+#             */
/*   Updated: 2025/02/22 15:31:01 by kbrauer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
private:
	const std::string 	_name;
	bool				_signed;
	const int			_sign_grade;
	const int			_exec_grade;
public:
	Form();
	Form(std::string name, int sign_grade, int exec_grade);
	Form(Form& original);
	Form& operator=(const Form& F);
	~Form();
	const std::string	getName() const;
	bool				getSigned() const;
	const int			getSignGrade() const;
	const int			getExecGrade() const;
	void				beSigned(Bureaucrat& B);
	class GradeTooHighException : public std::exception {
		const char* what() const noexcept override {
			return "Error: Grade too high!";	
		}
	};
	class GradeTooLowException : public std::exception {
		const char* what() const noexcept override {
			return "Error: Grade too low!";
		}
	};
};

std::ostream& operator<<(std::ostream& os, Form& F);

#endif

/*
The grades of the Form follow the same rules that apply to the Bureaucrat. Thus,
the following exceptions will be thrown if a form grade is out of bounds:
Form::GradeTooHighException and Form::GradeTooLowException.
Same as before, write getters for all attributes and an overload of the insertion («)
operator that prints all the form’s informations.

Add also a beSigned() member function to the Form that takes a Bureaucrat as
parameter. It changes the form status to signed if the bureaucrat’s grade is high enough
(higher or egal to the required one). Remember, grade 1 is higher than grade 2.
If the grade is too low, throw a Form::GradeTooLowException.

Then, modify the signForm() member function in the Bureaucrat class. This function must call 
Form::beSigned() to attempt to sign the form. If the form is signed
successfully, it will print something like:
<bureaucrat> signed <form>
Otherwise, it will print something like:
<bureaucrat> couldn’t sign <form> because <reason>.
*/