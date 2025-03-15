/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevin <kevin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 19:51:22 by kevin             #+#    #+#             */
/*   Updated: 2025/03/15 20:05:44 by kevin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <string>
#include <iostream>

template<class T> class Array {
    private:
        T* arr;
    public:
        Array();
        Array(unsigned int n);
        Array& operator=(const Array& A);
        ~Array();
};

#endif