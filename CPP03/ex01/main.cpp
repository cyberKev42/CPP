/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevin <kevin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 19:00:49 by kbrauer           #+#    #+#             */
/*   Updated: 2025/02/08 15:28:07 by kevin            ###   ########.fr       */
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
    S1.attack("Larry");
    S1.takeDamage(4);
    S1.beRepaired(2);

}
