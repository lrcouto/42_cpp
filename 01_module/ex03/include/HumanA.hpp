/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 23:15:27 by lcouto            #+#    #+#             */
/*   Updated: 2022/06/14 15:20:01 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef HUMANA_HPP
# define HUMANA_HPP

# include <iostream>
# include "Weapon.hpp"

class HumanA
{
    private:
        std::string _name;
        Weapon      &_weapon;
    
    public:
        HumanA(std::string name, Weapon &weapon);
        ~HumanA(void);
        
		void    attack(void);
};

#endif