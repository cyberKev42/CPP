/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevin <kevin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 16:49:49 by kevin             #+#    #+#             */
/*   Updated: 2025/03/15 17:39:45 by kevin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SWAP_HPP
#define SWAP_HPP

template<typename T> void swap(T& first, T& second) {
    T tmp = first;
    first = second;
    second = tmp;
}

template<typename T> T min(T first, T second) {
    return (first < second) ? first : second;
}

template<typename T> T max(T first, T second) {
    return (first > second) ? first : second;
}


#endif