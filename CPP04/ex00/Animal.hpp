
#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <iostream>

class Animal {
protected:
    std::string _type;
public:
    Animal();
    Animal(Animal& original);
    ~Animal();
    Animal& operator=(const Animal& A);
    void makeSound();
}

#endif