/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Claptrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 23:43:18 by lcouto            #+#    #+#             */
/*   Updated: 2022/06/19 03:35:21 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap
{
	private:
		std::string m_name;
		int			m_hitPoints;
		int			m_energyPoints;
		int			m_attackDamage;

		void		setName(std::string const name);
		void		setHitPoints(int const hitPoints);
		void		setEnergyPoints(int const energyPoints);
		void		setAttackDamage(int const attackDamage);

		std::string	getName(void) const;
		int			getHitPoints(void) const;
		int			getEnergyPoints(void) const;
		int			getAttackDamage(void) const;

	public:
		ClapTrap(void);
		ClapTrap(std::string name);
		~ClapTrap(void);
		ClapTrap(ClapTrap const &instancedObject);
		ClapTrap &operator=(ClapTrap const &rightHandSide);

		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
};

#endif

//                    @/*/////**//////////@                   
//               @/////**////*/(##/((((///((///@              
//           #@//*////@@@@@@@@@@@@@@@@@@@@@////////%          
//         @//*///@@@@@        @(((//////@/@@@@//////@        
//       @*////(@@@          (@/*/@@@@////@   &@@@//(//@      
//     @(////(@@            @////@@  #@(//@/     @@@/////@    
//    @(((/(@@            @////@@#    @(//&@       @@&#//(@   
//   @/////@@           @/////@@      @(///@        @@@#///@  
//  @@/###@@          &@//(#@@@       @(//#@         @@%((((@ 
//  @##//(@          @/////@@         @((/(@/         @@((((@ 
// @@(/##@@        @/((((#@@          @((((%@         &@((((@@
// @@##((@@      @((((((@@            @(((((@         /@((((@@
// %@((##(@    @&((#(#(@@             @(((((@         @@((((@&
//  @@(%%(@,  @((((((@@(              @(((##@(        @%%%#@@ 
//  %@@%#%(@@((####%@@                @#####%@       @#####@% 
//   @@@#######%%%@@@                 @####%%@      @#####@@  
//    &@@###%%%#%@@                   @######@    @#####@@@   
//      @@@%%###%@                    @####%%@% @%%##%%@@     
//        @@@##%###%%                 @%%%%%%%%%%%%%@@@       
//          @@@@%%%%%%%%%%            @%%%%%%%%%%%@@@         
//             @@@@&%%%%%%%%%%%%%%%%%%%%%%%%%%@@@@            
//                ,@@@@@@@%%%&%%%%%%%%%@@@@@@@.               
//                       @@@@@@@@@@@@@@@           