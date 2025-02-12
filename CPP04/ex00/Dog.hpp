/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevin <kevin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 16:18:19 by kevin             #+#    #+#             */
/*   Updated: 2025/02/08 16:43:44 by kevin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal {
protected:
public:
    Dog();
    Dog(Dog& original);
    ~Dog();
    Dog& operator=(const Dog& D);
    void makeSound() const;
    std::string getType(void) const;
};

#endif