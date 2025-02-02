
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

void Animal::makeSound() {
    std::cout << "Animal makes sound" << std::endl;
}
