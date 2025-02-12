/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevin <kevin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 16:18:19 by kevin             #+#    #+#             */
/*   Updated: 2025/02/08 18:10:22 by kevin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
private:
    Brain* _b;
public:
    Dog();
    Dog(Dog& original);
    ~Dog();
    Dog& operator=(const Dog& D);
    void makeSound() const;
    std::string getType(void) const;
    void setType(std::string type);
};

#endif