/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 19:55:08 by lcouto            #+#    #+#             */
/*   Updated: 2022/06/22 13:27:42 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include "Animal.hpp"
# include "Dog.hpp"
# include "Cat.hpp"
# include "Brain.hpp"
# include <unistd.h>

int		main(void)
{
	const Animal* cat = new Cat();
	usleep(50000);
	const Animal* cat2 = new Cat();
	usleep(50000);
	Cat cat3;
	Cat cat4(cat3);

	cat->getBrainAddress();
	cat2->getBrainAddress();
	cat3.getBrainAddress();
	cat4.getBrainAddress();

	delete cat;
	delete cat2;
	return (0);
}

