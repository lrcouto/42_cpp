/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 16:43:04 by lcouto            #+#    #+#             */
/*   Updated: 2023/03/17 16:43:04 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "\033[31;1mThis program expects a file path as an argument.\033[0m" << std::endl;
        return 1;
    }

    BitcoinExchange btc(argv[1]);
    btc.processInput();
    return 0;
}

