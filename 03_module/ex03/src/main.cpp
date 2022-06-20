/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 02:06:58 by lcouto            #+#    #+#             */
/*   Updated: 2022/06/19 23:49:17 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Claptrap.hpp"
# include "Fragtrap.hpp"
# include "Scavtrap.hpp"
# include "Diamondtrap.hpp"
# include <iostream>

int	main(void)
{
	std::cout << "\n ------- Calling DiamondTrap Constructor ------- \n" << std::endl;

	DiamondTrap diamond("Butt Stallion");

	std::cout << "\n ------- Calling ScavTrap attack function from DiamondTraps ------- \n" << std::endl;

	diamond.attack("The Calypso Twins");

	std::cout << "\n ------- Calling damage functions from parent classes ------- \n" << std::endl;

	diamond.FragTrap::takeDamage(20);
	diamond.ScavTrap::takeDamage(20);

	std::cout << "\n ------- Calling repair functions from parent classes ------- \n" << std::endl;

	diamond.ScavTrap::beRepaired(10);
	diamond.FragTrap::beRepaired(12);

	std::cout << "\n ------- Calling highFiveGuys() and guardGate() from parent classes ------- \n" << std::endl;

	diamond.ScavTrap::guardGate();
	diamond.FragTrap::highFiveGuys();

	std::cout << "\n ------- Calling whoAmI() function ------- \n" << std::endl;

	diamond.whoAmI();

	std::cout << "\n ------- End program. ------- \n" << std::endl;

	return (0);
}