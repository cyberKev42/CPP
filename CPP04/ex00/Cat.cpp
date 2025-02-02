
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
    if (this != &A) {
        this->_type = A._type;
    }
    return *this;
}

void Cat::makeSound() {
    std::cout << "Cat makes miau miau" << std::endl;
}
