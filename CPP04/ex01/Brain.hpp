/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevin <kevin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 17:13:27 by kevin             #+#    #+#             */
/*   Updated: 2025/02/08 17:15:30 by kevin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>
#include <iostream>

class Brain {
private:
    std::string _ideas[100];
public:
    Brain();
    Brain(Brain& original);
    virtual ~Brain();
    Brain& operator=(const Brain& B);
    
};

#endif