/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevin <kevin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 16:57:09 by kevin             #+#    #+#             */
/*   Updated: 2025/02/08 16:57:51 by kevin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() {
    std::cout << "WrongCat constructor called" << std::endl;
    this->_type = "WrongCat";
}
WrongCat::WrongCat(WrongCat& original) {
    std::cout << "WrongCat copy constructor called" << std::endl;
    *this = original;
}
WrongCat::~WrongCat() {
    std::cout << "WrongCat destructor called" << std::endl;
}
WrongCat& WrongCat::operator=(const WrongCat& C) {
    std::cout << "WrongCat copy assignment operator called" << std::endl;
    if (this != &C) {
        this->_type = C._type;
    }
    return *this;
}

void WrongCat::makeSound() const{
    std::cout << "WrongCat makes miau miau" << std::endl;
}

std::string WrongCat::getType() const{
    return this->_type;
}