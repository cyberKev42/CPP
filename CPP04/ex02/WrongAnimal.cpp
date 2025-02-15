/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevin <kevin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 16:55:17 by kevin             #+#    #+#             */
/*   Updated: 2025/02/08 16:56:42 by kevin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
    std::cout << "WrongAnimal constructor called" << std::endl;
    this->_type = "";
}
WrongAnimal::WrongAnimal(WrongAnimal& original) {
    std::cout << "WrongAnimal copy constructor called" << std::endl;
    *this = original;
}
WrongAnimal::~WrongAnimal() {
    std::cout << "WrongAnimal destructor called" << std::endl;
}
WrongAnimal& WrongAnimal::operator=(const WrongAnimal& A) {
    std::cout << "WrongAnimal copy assignment operator called" << std::endl;
    if (this != &A) {
        this->_type = A._type;
    }
    return *this;
}

void WrongAnimal::makeSound() const {
    std::cout << "WrongAnimal makes sound" << std::endl;
}

std::string WrongAnimal::getType(void) const {
    return this->_type;
}