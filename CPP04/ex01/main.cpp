/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevin <kevin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 16:16:29 by kevin             #+#    #+#             */
/*   Updated: 2025/02/08 19:16:33 by kevin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

int main()
{
    // const Animal* j = new Dog();
    // const Animal* i = new Cat();
    // const Animal* x[10];
    
    // delete j;//should not create a leak
    // delete i;

    // for (int i = 0; i < 10; i++) {
    //     if (i < 5)
    //         x[i] = new Dog();
    //     else
    //         x[i] = new Cat();
    // }
    
    // for (int i = 0; i < 10; i++) {
    //     delete x[i];
    // }

    Animal* i = new Cat();
    Animal k(*i);

    std::cout << i->getType() << std::endl;
    std::cout << k.getType() << std::endl;
    k.setType("wrongCat");
    // delete i;
    std::cout << i->getType() << std::endl;
    std::cout << k.getType() << std::endl;
    
    return 0;
}
