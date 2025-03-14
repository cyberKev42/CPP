/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevin <kevin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 16:18:49 by kevin             #+#    #+#             */
/*   Updated: 2025/02/08 16:44:12 by kevin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() {
    std::cout << "Cat constructor called" << std::endl;
    this->_type = "Cat";
}
Cat::Cat(Cat& original) {
    std::cout << "Cat copy constructor called" << std::endl;
    *this = original;
}
Cat::~Cat() {
    std::cout << "Cat destructor called" << std::endl;
}
Cat& Cat::operator=(const Cat& C) {
    std::cout << "Cat copy assignment operator called" << std::endl;
    if (this != &C) {
        this->_type = C._type;
    }
    return *this;
}

void Cat::makeSound() const{
    std::cout << "Cat makes miau miau" << std::endl;
}

std::string Cat::getType() const{
    return this->_type;
}