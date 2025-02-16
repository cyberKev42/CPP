/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrauer <kbrauer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 16:17:36 by kevin             #+#    #+#             */
/*   Updated: 2025/02/16 20:20:23 by kbrauer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
    virtual ~Animal();
    Animal& operator=(const Animal& A);
    virtual void makeSound() const = 0;
    std::string getType(void) const;
    void setType(std::string type);
};

#endif