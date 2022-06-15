/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 00:42:17 by lcouto            #+#    #+#             */
/*   Updated: 2022/06/15 01:44:34 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Harl.hpp"

    Harl::Harl(void)
    {
        return;
    }

    Harl::~Harl(void)
    {
        return;
    }

    void    Harl::complain(std::string level)
    {
        void	    (Harl::*fnPointer[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
        std::string harlLevels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

        for (int i = 0; i < 4; i++)
        {
            if (harlLevels[i] == level)
                (this->*fnPointer[i])();
        }
    }

    void    Harl::debug(void)
    {
        std::cout << "\033[0;36mI love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do! (*￣▽￣)b\033[0m" << std::endl;
    }

    void    Harl::info(void)
    {
        std::cout << "\033[0;33mI cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more! (；￣Д￣)\033[0m" << std::endl;
    }

    void    Harl::warning(void)
    {
        std::cout << "\033[1;33mI think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month. (‡▼益▼)\033[0m" << std::endl;
    }

    void    Harl::error(void)
    {
        std::cout << "\033[1;31mThis is unacceptable! I want to speak to the manager now. ٩(╬ʘ益ʘ╬)۶\033[0m" << std::endl;
    }