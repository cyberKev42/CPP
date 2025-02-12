/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevin <kevin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 16:53:56 by kevin             #+#    #+#             */
/*   Updated: 2025/02/08 16:54:48 by kevin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
protected:
public:
    WrongCat();
    WrongCat(WrongCat& original);
    ~WrongCat();
    WrongCat& operator=(const WrongCat& C);
    void makeSound() const;
    std::string getType(void) const;
};

#endif