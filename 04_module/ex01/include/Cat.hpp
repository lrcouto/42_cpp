/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 23:17:03 by lcouto            #+#    #+#             */
/*   Updated: 2022/06/22 11:40:16 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"
# include <iostream>

class Cat : public Animal
{
	private:
		Brain* brain;
    public:
		Cat(void);
		~Cat(void);
		Cat(Cat const &instancedObject);
		Cat &operator=(Cat const &rightHandSide);
    
        void        makeSound(void) const;
		Brain*		getBrain(void) const;
		std::string getIdea(int index) const;
		void		getBrainAddress(void) const;
};

#endif
