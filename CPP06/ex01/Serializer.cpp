/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevin <kevin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 19:20:41 by kevin             #+#    #+#             */
/*   Updated: 2025/03/14 20:54:29 by kevin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer() {
}
Serializer::Serializer(Serializer& original) {
    
}
Serializer& Serializer::operator=(const Serializer& S) {
    return *this;
}
Serializer::~Serializer() {
    
}

uintptr_t Serializer::serialize(Data* ptr) {
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialze(uintptr_t raw) {
    return reinterpret_cast<Data*>(raw);
}