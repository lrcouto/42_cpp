/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 02:06:58 by lcouto            #+#    #+#             */
/*   Updated: 2022/06/17 21:59:28 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Fixed.hpp"
# include <iostream>

int	main(void)
{
	Fixed a;
	Fixed const b(10);
	Fixed const c(42.42f);
	Fixed const d(b);

	std::cout << "\n--------------------\n" << std::endl;

	a = Fixed(1234.4321f);

	std::cout << "\n--------------------\n" << std::endl;

	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;

	std::cout << "\n--------------------\n" << std::endl;

	std::cout << "a is " << a.toInt() << " as Integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as Integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as Integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as Integer" << std::endl;

	std::cout << "\n--------------------\n" << std::endl;
	
	return (0);
}