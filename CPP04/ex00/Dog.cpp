
#include "Dog.hpp"

Dog::Dog() {
    std::cout << "Dog constructor called" << std::endl;
    this->_type = "Dog";
}
Dog::Dog(Dog& original) {
    std::cout << "Dog copy constructor called" << std::endl;
    *this = original;
}
Dog::~Dog() {
    std::cout << "Dog destructor called" << std::endl;
}
Dog& Dog::operator=(const Dog& D) {
    std::cout << "Dog copy assignment operator called" << std::endl;
    if (this != &A) {
        this->_type = D._type;
    }
    return *this;
}

void Dog::makeSound() {
    std::cout << "Dog makes wuff wuff" << std::endl;
}
