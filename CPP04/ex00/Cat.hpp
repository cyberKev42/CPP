
#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : Animal {
protected:
public:
    Cat();
    Cat(Cat& original);
    ~Cat();
    Cat& operator=(const Cat& C);
    void makeSound();
}

#endif