/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 22:37:45 by lcouto            #+#    #+#             */
/*   Updated: 2022/06/22 19:21:35 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"
# include <iostream>

class Dog : public Animal
{
	private:
		Brain* brain;
    public:
		Dog(void);
		~Dog(void);
		Dog(Dog const &instancedObject);
		Dog &operator=(Dog const &rightHandSide);
    
        void        makeSound(void) const;
		std::string getIdea(int index) const;
		void		getBrainAddress(void) const;
};

#endif
