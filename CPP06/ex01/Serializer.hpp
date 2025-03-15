/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevin <kevin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 19:04:36 by kevin             #+#    #+#             */
/*   Updated: 2025/03/14 19:29:59 by kevin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <string>
#include <iostream>
#include "Data.hpp"

class Serializer {
    private:
        Serializer();
        Serializer(Serializer& original);
        Serializer& operator=(const Serializer& S);
        ~Serializer();
    public:
        static uintptr_t serialize(Data* ptr);
        static Data* deserialze(uintptr_t raw);
};


#endif