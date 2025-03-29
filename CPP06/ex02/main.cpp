/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrauer <kbrauer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 21:42:29 by kevin             #+#    #+#             */
/*   Updated: 2025/03/29 17:13:59 by kbrauer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* generate(void) {
    int random = (time(0) % 3) + 1;
    switch (random) {
        case 1: {
            std::cout << "Generated object A" << std::endl;
            Base* a = new A();
            return a;
        }
        case 2: {
            std::cout << "Generated object B" << std::endl;
            Base* b = new B();
            return b;
        }
        case 3: {
            std::cout << "Generated object C" << std::endl;
            Base* c = new C();
            return c;
        }
        default:
            return NULL;
    }
}

void identify(Base* p) {
    std::cout << std::endl << "Identify by pointer" << std::endl;
    
    A* a = dynamic_cast<A*>(p);
    B* b = dynamic_cast<B*>(p);
    C* c = dynamic_cast<C*>(p);
    
    if (a != 0)
        std::cout << "I am A" << std::endl;
    if (b != 0)
        std::cout << "I am B" << std::endl;
    if (c != 0)
        std::cout << "I am C" << std::endl;
}

void identify(Base& p) {
    std::cout << std::endl << "Identify by reference" << std::endl;

    try
    {
        A& a = dynamic_cast<A&>(p);
        std::cout << &a << " I am A" << std::endl;
    }
    catch(const std::exception& e)
    {}
    
    try
    {
        B& b = dynamic_cast<B&>(p);
        std::cout << &b << " I am B" << std::endl;
    }
    catch(const std::exception& e)
    {}

    try
    {
        C& c = dynamic_cast<C&>(p);
        std::cout << &c << " I am C" << std::endl;
    }
    catch(const std::exception& e)
    {}
    
}

int main() {
    
    Base* ptr = generate();
    
    identify(ptr);
    
    identify(*ptr);
    
    
    return 0;
}