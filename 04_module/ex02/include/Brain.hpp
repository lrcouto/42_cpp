/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 00:12:27 by lcouto            #+#    #+#             */
/*   Updated: 2022/06/22 10:45:48 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

class Brain
{
    public:
        std::string ideas[100];

        Brain(void);
        ~Brain(void);
		Brain(Brain const &instancedObject);
		Brain &operator=(Brain const &rightHandSide);
};

#endif
