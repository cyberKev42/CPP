/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevin <kevin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 20:33:17 by kevin             #+#    #+#             */
/*   Updated: 2025/03/14 20:58:13 by kevin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"

int main() {

    Data* ptr = new Data;
    
    std::cout << ptr << std::endl;
    std::cout << ptr->num << std::endl << std::endl;

    uintptr_t x = Serializer::serialize(ptr);
    Data* ptr_new = Serializer::deserialze(x);
    
    std::cout << x << std::endl << std::endl;

    std::cout << ptr << std::endl;
    std::cout << ptr_new << std::endl;
    std::cout << ptr_new->num << std::endl;
    
    return 0;
}
