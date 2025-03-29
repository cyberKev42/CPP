/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrauer <kbrauer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 19:20:41 by kevin             #+#    #+#             */
/*   Updated: 2025/03/29 17:19:20 by kbrauer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer() {
}
Serializer::Serializer(Serializer& original) {
    *this = original;
}
Serializer& Serializer::operator=(const Serializer& S) {
	if (this != &S)
    	return *this;
    return *this;
}
Serializer::~Serializer() {
    
}

__intptr_t Serializer::serialize(Data* ptr) {
    return reinterpret_cast<__intptr_t>(ptr);
}

Data* Serializer::deserialze(__intptr_t raw) {
    return reinterpret_cast<Data*>(raw);
}