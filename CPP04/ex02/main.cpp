/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrauer <kbrauer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 16:16:29 by kevin             #+#    #+#             */
/*   Updated: 2025/02/14 17:54:27 by kbrauer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

int main()
{
	
	// Animal 	ani;
	Cat		cat;
	
    std::cout << std::endl << "Construction" << std::endl << std::endl;
	
    const Animal* j = new Dog();
    const Animal* i = new Cat();
	
    std::cout << std::endl << "Destruction" << std::endl << std::endl;
	
    delete j;//should not create a leak
    delete i;
	
    std::cout << std::endl << "Construction Array" << std::endl << std::endl;
	
    const Animal* x[10];

    for (int i = 0; i < 10; i++) {
        if (i < 5)
            x[i] = new Dog();
        else
            x[i] = new Cat();
    }

    std::cout << std::endl << "Destruction Array" << std::endl;
	
    for (int i = 0; i < 10; i++) {
        delete x[i];
    }
	
    std::cout << std::endl << "Construction Wrong example" << std::endl << std::endl;

    Cat *l = new Cat;
    Cat *k = new Cat(*l);
	
    std::cout << std::endl;
	

    std::cout << l->getType() << std::endl;
    std::cout << k->getType() << std::endl;
	
    std::cout << std::endl;
	
    k->setType("wrongCat");
    
    std::cout << l->getType() << std::endl;
    std::cout << k->getType() << std::endl;
	
    std::cout << std::endl << "Destruction Wrong example" << std::endl << std::endl;
	
	delete l;
	delete k;
    
    return 0;
}
