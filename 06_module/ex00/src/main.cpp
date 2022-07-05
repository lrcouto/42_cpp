/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 23:22:53 by lcouto            #+#    #+#             */
/*   Updated: 2022/07/04 23:37:06 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "\033[1;31mWrong number of arguments. Expected 1\033[0m" << std::endl;
        return(0);
    }
    std::cout << argv[1] << std::endl;
    return (0);
}
