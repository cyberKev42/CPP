/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevin <kevin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 16:52:59 by kevin             #+#    #+#             */
/*   Updated: 2025/02/08 16:54:07 by kevin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <string>
#include <iostream>

class WrongAnimal {
protected:
    std::string _type;
public:
    WrongAnimal();
    WrongAnimal(WrongAnimal& original);
    virtual ~WrongAnimal();
    WrongAnimal& operator=(const WrongAnimal& A);
    void makeSound() const;
    std::string getType(void) const;
};

#endif