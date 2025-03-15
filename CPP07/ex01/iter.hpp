/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevin <kevin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 19:13:25 by kevin             #+#    #+#             */
/*   Updated: 2025/03/15 19:44:14 by kevin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template<typename T> void iter(T* arr, int len, void(*f)(T&)) {
    for (int i = 0; i < len; i++) {
        f(arr[i]);
    }
}

template<typename T> void myFunc(T& ptr) {
    std::cout  << ptr << std::endl;
}

#endif