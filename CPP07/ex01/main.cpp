/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrauer <kbrauer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 19:11:49 by kevin             #+#    #+#             */
/*   Updated: 2025/03/21 16:55:23 by kbrauer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iter.hpp"

int main() {
    int arr[5] = {1, 5, 3, 8, 41};
    iter(arr, 5, myFunc);

    std::cout  << std::endl;
	
    std::string arr_2[3] = {"This", "is", "line 3"};
    iter(arr_2, 3, myFunc);

    std::cout  << std::endl;
	
    float arr_3[7] = {66.6f, 100.0f, 2.5f, 9.98f, 0.0f, 42.42f, 7.0f};
    iter(arr_3, 7, myFunc);
}
