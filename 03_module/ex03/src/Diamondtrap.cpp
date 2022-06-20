/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Diamondtrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 21:40:02 by lcouto            #+#    #+#             */
/*   Updated: 2022/06/20 00:10:32 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Diamondtrap.hpp"

DiamondTrap::DiamondTrap(void)
{
    std::string name = "DMND-TP";

    this->m_name = name;
    ClapTrap::m_name = name + "_clap_name";
    this->m_attackDamage = FragTrap::getAttackDamage();
    this->m_energyPoints = ScavTrap::getEnergyPoints();
    this->m_hitPoints = FragTrap::getHitPoints();
    std::cout << "I am the best robot. Yeah, yeah, yeah, I am the best robot. Ooh, ooh, here we go! Designation: DMND-TP" << std::endl;
    return ;
}

DiamondTrap::DiamondTrap(std::string name) :  ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name)
{
    this->m_name = name;
    ClapTrap::m_name = name + "_clap_name";
    this->m_attackDamage = FragTrap::getAttackDamage();
    this->m_energyPoints = ScavTrap::getEnergyPoints();
    this->m_hitPoints = FragTrap::getHitPoints();
    std::cout << "I am the best robot. Yeah, yeah, yeah, I am the best robot. Ooh, ooh, here we go! Designation: " << this->m_name << std::endl;
    return ;
}

DiamondTrap::~DiamondTrap(void)
{
    std::cout << "I can see... the code" << std::endl;
    std::cout << this->m_name << " has been destroyed in a glorious explosion." << std::endl;
    return ;
}
DiamondTrap::DiamondTrap(DiamondTrap const &instancedObject)
{
	*this = instancedObject;
    std::cout << "Yoo hoooooooooo!" << std::endl;
	return ;
}

DiamondTrap &DiamondTrap::operator=(DiamondTrap const &rightHandSide)
{
	this->m_name = rightHandSide.getName();
	this->m_hitPoints = rightHandSide.getHitPoints();
	this->m_energyPoints = rightHandSide.getHitPoints();
	this->m_attackDamage = rightHandSide.getAttackDamage();
	return (*this);
}

void	DiamondTrap::attack(const std::string& target)
{
    if (this->m_energyPoints > 0 && this->m_hitPoints > 0)
        ScavTrap::attack(target);
    else
        std::cout << this->m_name << " seems to be inactive." << std::endl;
    return ;
}

void    DiamondTrap::whoAmI(void)
{
    if (this->m_energyPoints > 0 && this->m_hitPoints > 0)
    {
        std::cout << "Who am I? Am I " << this->m_name << "? Am I " << ClapTrap::getName() << "? I AM SO CONFUSED, VAULT HUNTER!!" << std::endl;
        this->m_energyPoints -= 1;
    }
    else
        std::cout << this->m_name << " seems to be inactive." << std::endl;
    return ;
}