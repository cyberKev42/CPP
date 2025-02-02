/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrauer <kbrauer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 19:01:11 by kbrauer           #+#    #+#             */
/*   Updated: 2025/01/23 19:01:12 by kbrauer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include <string>
#include <iostream>

class ScavTrap : ClapTrap {
private:
public:
    ScavTrap(std::string name);
    ScavTrap(ScavTrap& original);
    ~ScavTrap();
    ScavTrap& operator=(const ScavTrap& S);
    void guardGate();
};

#endif