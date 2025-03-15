/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevin <kevin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 19:24:25 by kevin             #+#    #+#             */
/*   Updated: 2025/03/14 20:31:37 by kevin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data() {
    this->num = 42;
}
Data::Data(Data& original) {
    this->num = original.num;
}
Data& Data::operator=(const Data& D) {
    if (this != &D)
        this->num = D.num;
    return *this;
}
Data::~Data() {
    
}
