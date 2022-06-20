/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Diamondtrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 21:21:22 by lcouto            #+#    #+#             */
/*   Updated: 2022/06/19 23:57:44 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include <iostream>
# include "Scavtrap.hpp"
# include "Fragtrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
    private:
        std::string m_name;

	public:
        DiamondTrap(void);
		DiamondTrap(std::string name);
		~DiamondTrap(void);
		DiamondTrap(DiamondTrap const &instancedObject);
        DiamondTrap &operator=(DiamondTrap const &rightHandSide);

		void	attack(const std::string& target);
        void    whoAmI(void);
};

#endif