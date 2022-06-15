/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 23:15:30 by lcouto            #+#    #+#             */
/*   Updated: 2022/06/15 20:07:47 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>

class Weapon
{
    private:
        std::string _type;
    
    public:
        Weapon(std::string weaponType);
        ~Weapon(void);
        
		void                setType(std::string weaponType);
        std::string const   &getType(void);
};

#endif