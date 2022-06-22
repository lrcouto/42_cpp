/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 19:55:08 by lcouto            #+#    #+#             */
/*   Updated: 2022/06/22 03:08:48 by lcouto           ###   ########.fr       */
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
	usleep(10000);
	const Animal* copyCat(cat);
	usleep(10000);
	const Animal* cat2 = new Cat();

	std::cout << cat->getIdea(15) << '\n';
	std::cout << copyCat->getIdea(15) << '\n';
	std::cout << cat2->getIdea(15) << '\n';

	delete cat;
	delete cat2;
	return (0);
}

