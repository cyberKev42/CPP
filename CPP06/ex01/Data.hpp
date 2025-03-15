/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevin <kevin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 19:18:30 by kevin             #+#    #+#             */
/*   Updated: 2025/03/14 21:41:32 by kevin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
#define DATA_HPP

#include <iostream>

class Data {
    private:
    
    public:
        Data();
        Data(Data& original);
        Data& operator=(const Data& D);
        ~Data();
        int num;
};

#endif