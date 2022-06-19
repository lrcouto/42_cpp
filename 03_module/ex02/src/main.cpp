/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 02:06:58 by lcouto            #+#    #+#             */
/*   Updated: 2022/06/19 20:33:42 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Claptrap.hpp"
# include "Fragtrap.hpp"
# include <iostream>

int	main(void)
{
	std::cout << "\n ------- Creating ClapTrap from default constructor ------- \n" << std::endl;

	ClapTrap claptrap;

	std::cout << "\n ------- Creating named ClapTrap from name constructor ------- \n" << std::endl;

	ClapTrap namedClaptrap("Claptrap P. Claptrappington");

	std::cout << "\n ------- Creating FragTrap from name constructor ------- \n" << std::endl;

	FragTrap namedFragtrap("Fragtrap");

	std::cout << "\n ------- Creating FragTrap from default constructor ------- \n" << std::endl;

	FragTrap Fragtrap;

	std::cout << "\n ------- Performing attacks. ------- \n" << std::endl;

	claptrap.attack("Ultimate Badass Goliath");
	namedClaptrap.attack("Vermivorous the Invincible");
	Fragtrap.attack("Ultimate Badass Goliath");
	namedFragtrap.attack("Vermivorous the Invincible");

	std::cout << "\n ------- Repairing. ------- \n" << std::endl;

	claptrap.beRepaired(1);
	Fragtrap.beRepaired(1);

	std::cout << "\n ------- Taking damage. ------- \n" << std::endl;

	namedClaptrap.takeDamage(5);
	namedFragtrap.takeDamage(5);

	std::cout << "\n ------- FragTrap requesting a high five. ------- \n" << std::endl;

	Fragtrap.highFiveGuys();

	std::cout << "\n ------- End program. ------- \n" << std::endl;

	return (0);
}