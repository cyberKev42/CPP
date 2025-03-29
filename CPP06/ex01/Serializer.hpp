/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrauer <kbrauer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 19:04:36 by kevin             #+#    #+#             */
/*   Updated: 2025/03/29 17:16:04 by kbrauer          ###   ########.fr       */
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
        static __intptr_t serialize(Data* ptr);
        static Data* deserialze(__intptr_t raw);
};


#endif