/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevin <kevin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 17:33:13 by kevin             #+#    #+#             */
/*   Updated: 2025/02/08 17:43:16 by kevin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {
    std::cout << "Brain constructor called" << std::endl;
}
Brain::Brain(Brain& original) {
    std::cout << "Brain copy constructor called" << std::endl;
    *this = original;
}
Brain::~Brain() {
    std::cout << "Brain destructor called" << std::endl;
}
Brain& Brain::operator=(const Brain& B) {
    std::cout << "Brain copy assignment operator called" << std::endl;
    if (this != &B) {
        for (int i = 0; i < 100; i++) 
            this->_ideas[i] = B._ideas[i];
    }
    return *this;
}