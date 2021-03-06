/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 22:29:04 by lcouto            #+#    #+#             */
/*   Updated: 2022/06/15 02:43:07 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Harl.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Usage - input one of these commands: DEBUG | INFO | WARNING | ERROR" << std::endl;
		return (-1);
	}

	Harl harl;
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int index = -1;

	for (int i = 0; i < 4; i++)
	{
		if (argv[1] == levels[i])
			index = i;
	}

	while (index <= 3)
	{
		switch (index)
		{
			case 0:
				std::cout << std::endl;
				harl.complain("DEBUG");
				std::cout << std::endl;
				break;
			case 1:
				std::cout << std::endl;
				harl.complain("INFO");
				std::cout << std::endl;
				break;
			case 2:
				std::cout << std::endl;
				harl.complain("WARNING");
				std::cout << std::endl;
				break;
			case 3:
				std::cout << std::endl;
				harl.complain("ERROR");
				std::cout << std::endl;
				break;
			default:
				std::cout << std::endl;
				std::cout << "\033[0;32mHarl absent-mindedly picks his nose and grumbles something about bacon. (￣～￣;)\033[0m" << std::endl;
				std::cout << std::endl;
				index = 4;
				break;
		}
	index++;
	}
	
	return (0);
}