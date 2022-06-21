/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 01:39:10 by lcouto            #+#    #+#             */
/*   Updated: 2022/06/21 01:43:18 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"
# include <iostream>

class WrongCat : public WrongAnimal
{
    public:
		WrongCat(void);
		~WrongCat(void);
		WrongCat(WrongCat const &instancedObject);
		WrongCat &operator=(WrongCat const &rightHandSide);
    
        void        makeSound(void) const;
};

#endif
