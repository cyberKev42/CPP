/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevin <kevin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 16:18:37 by kevin             #+#    #+#             */
/*   Updated: 2025/02/08 16:43:39 by kevin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal {
protected:
public:
    Cat();
    Cat(Cat& original);
    ~Cat();
    Cat& operator=(const Cat& C);
    void makeSound() const;
    std::string getType(void) const;
};

#endif