/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 22:29:04 by lcouto            #+#    #+#             */
/*   Updated: 2022/06/14 02:42:34 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "HumanA.hpp"
# include "HumanB.hpp"

int	main(void)
{
	{
		Weapon polearm = Weapon("German Halberd");
		
		HumanA felisberto("Felisberto", polearm);
		felisberto.attack();
		polearm.setType("French Glaive-Guisarme");
		felisberto.attack();
	}
	{
		Weapon polearm = Weapon("German Halberd");

		HumanB gilberto("Gilberto");
		gilberto.attack();
		gilberto.setWeapon(polearm);
		gilberto.attack();
		polearm.setType("French Glaive-Guisarme");
		gilberto.attack();
	}
	return (0);
}