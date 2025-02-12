/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevin <kevin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 16:16:45 by kevin             #+#    #+#             */
/*   Updated: 2025/02/08 18:12:41 by kevin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() {
    std::cout << "Animal constructor called" << std::endl;
    this->_type = "";
}
Animal::Animal(Animal& original) {
    std::cout << "Animal copy constructor called" << std::endl;
    *this = original;
}
Animal::~Animal() {
    std::cout << "Animal destructor called" << std::endl;
}
Animal& Animal::operator=(const Animal& A) {
    std::cout << "Animal copy assignment operator called" << std::endl;
    if (this != &A) {
        this->_type = A._type;
    }
    return *this;
}

void Animal::makeSound() const {
    std::cout << "Animal makes sound" << std::endl;
}

std::string Animal::getType(void) const {
    return this->_type;
}

void Animal::setType(std::string type) {
    this->_type = type;
}