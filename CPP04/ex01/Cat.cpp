/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrauer <kbrauer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 16:18:49 by kevin             #+#    #+#             */
/*   Updated: 2025/02/16 19:37:42 by kbrauer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() {
    std::cout << "Cat constructor called" << std::endl;
    this->_type = "Cat";
    this->_b = new Brain();
}
Cat::Cat(Cat& original) {
    std::cout << "Cat copy constructor called" << std::endl;
    this->_type = original.getType();
    this->_b = new Brain(*original._b);
}
Cat::~Cat() {
    delete this->_b;
    std::cout << "Cat destructor called" << std::endl;
}
Cat& Cat::operator=(const Cat& C) {
    std::cout << "Cat copy assignment operator called" << std::endl;
    if (this != &C) {
        this->_type = C._type;
        delete this->_b;
		this->_b = new Brain(*C._b);
    }
    return *this;
}

void Cat::makeSound() const{
    std::cout << "Cat makes miau miau" << std::endl;
}

std::string Cat::getType() const{
    return this->_type;
}

void Cat::setType(std::string type) {
    this->_type = type;
}
