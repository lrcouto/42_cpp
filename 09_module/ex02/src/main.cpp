/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 01:41:21 by lcouto            #+#    #+#             */
/*   Updated: 2023/04/02 19:43:26 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PmergeMe.hpp"


int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cerr << "\033[31;1mPlease enter a sequence of positive integers.\033[0m" << std::endl;
        exit(1);
    }
        PmergeMe sorterObj(argc, argv);
        return 0;
}
