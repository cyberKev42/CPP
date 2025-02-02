
#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : Animal {
protected:
public:
    Dog();
    Dog(Dog& original);
    ~Dog();
    Dog& operator=(const Dog& D);
    void makeSound();
}

#endif