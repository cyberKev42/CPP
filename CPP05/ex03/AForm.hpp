/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrauer <kbrauer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 13:28:34 by kbrauer           #+#    #+#             */
/*   Updated: 2025/02/22 15:31:01 by kbrauer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AForm_HPP
#define AForm_HPP

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
private:
	const std::string 	_name;
	bool				_signed;
	const int			_sign_grade;
	const int			_exec_grade;
public:
	AForm();
	AForm(std::string name, int sign_grade, int exec_grade);
	AForm(AForm& original);
	AForm& operator=(const AForm& F);
	virtual ~AForm();
	const std::string	getName() const;
	bool				getSigned() const;
	int			getSignGrade() const;
	int			getExecGrade() const;
	void				beSigned(Bureaucrat& B);
	void 				execute(Bureaucrat const & executor) const;
	virtual void		myExe() const = 0;
	class GradeTooHighException : public std::exception {
		const char* what() const throw() {
			return "Error: Grade too high!";	
		}
	};
	class GradeTooLowException : public std::exception {
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

std::ostream& operator<<(std::ostream& os, AForm& F);

#endif

/*
The grades of the AForm follow the same rules that apply to the Bureaucrat. Thus,
the following exceptions will be thrown if a AForm grade is out of bounds:
AForm::GradeTooHighException and AForm::GradeTooLowException.
Same as before, write getters for all attributes and an overload of the insertion («)
operator that prints all the AForm’s inAFormations.

Add also a beSigned() member function to the AForm that takes a Bureaucrat as
parameter. It changes the AForm status to signed if the bureaucrat’s grade is high enough
(higher or egal to the required one). Remember, grade 1 is higher than grade 2.
If the grade is too low, throw a AForm::GradeTooLowException.

Then, modify the signAForm() member function in the Bureaucrat class. This function must call 
AForm::beSigned() to attempt to sign the AForm. If the AForm is signed
successfully, it will print something like:
<bureaucrat> signed <AForm>
Otherwise, it will print something like:
<bureaucrat> couldn’t sign <AForm> because <reason>.
*/