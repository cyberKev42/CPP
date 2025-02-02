/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrauer <kbrauer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 19:00:49 by kbrauer           #+#    #+#             */
/*   Updated: 2025/01/23 19:00:50 by kbrauer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {

    ClapTrap C1("Larry");
    ScavTrap S1("Hank");

    C1.attack("Hank");
    C1.takeDamage(4);
    C1.beRepaired(2);

    S1.guardGate();

}
