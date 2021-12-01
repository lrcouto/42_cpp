/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 20:38:55 by lcouto            #+#    #+#             */
/*   Updated: 2021/10/15 22:15:59 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

static void	loudNoises(char *argv)
{
	for (int i = 0; argv[i]; i++)
		argv[i] = toupper(argv[i]);
	std::cout << argv << " ";
}

int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		std::cout << "\a" << std::flush;
	}
	else
	{
		for (int i = 1; argv[i]; i++)
			loudNoises(argv[i]);
		std::cout << std::endl;
	}
	return (0);
}