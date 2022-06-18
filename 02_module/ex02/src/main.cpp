/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 02:06:58 by lcouto            #+#    #+#             */
/*   Updated: 2022/06/18 19:45:50 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Fixed.hpp"
# include <iostream>

int main(void)
{
	Fixed	a;
	Fixed const b(Fixed(5.05f) * Fixed(2));

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max(a, b) << std::endl;
	std::cout << Fixed::min(a, b) << std::endl;

	Fixed c(3);
	Fixed d(0.5f);
	Fixed e((c / d));

	std::cout << e << std::endl;
	std::cout << --e << std::endl;
	std::cout << e << std::endl;
	std::cout << e-- << std::endl;
	std::cout << e << std::endl;

	return 0;
}