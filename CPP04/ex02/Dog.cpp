/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrauer <kbrauer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 16:18:05 by kevin             #+#    #+#             */
/*   Updated: 2025/02/14 15:39:15 by kbrauer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() {
    std::cout << "Dog constructor called" << std::endl;
    this->_type = "Dog";
    this->_b = new Brain();
}
Dog::Dog(Dog& original) {
    std::cout << "Dog copy constructor called" << std::endl;
    *this = original;
}
Dog::~Dog() {
    delete this->_b;
    std::cout << "Dog destructor called" << std::endl;
}
Dog& Dog::operator=(const Dog& D) {
    std::cout << "Dog copy assignment operator called" << std::endl;
    if (this != &D) {
        this->_type = D._type;
    }
    return *this;
}

void Dog::makeSound() const{
    std::cout << "Dog makes wuff wuff" << std::endl;
}

std::string Dog::getType() const{
    return this->_type;
}

void Dog::setType(std::string type) {
    this->_type = type;
}