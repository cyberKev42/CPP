/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevin <kevin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 19:00:49 by kbrauer           #+#    #+#             */
/*   Updated: 2025/02/08 15:45:04 by kevin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() {

    ClapTrap C1("Larry");
    ScavTrap S1("Hank");
    FragTrap F1("Sabine");

    C1.attack("Hank");
    C1.takeDamage(4);
    C1.beRepaired(2);

    S1.guardGate();
    S1.attack("Larry");
    S1.takeDamage(40);
    S1.beRepaired(20);
    
    F1.attack("Larry");
    F1.takeDamage(66);
    F1.beRepaired(23);
    F1.highFivesGuys();

}
