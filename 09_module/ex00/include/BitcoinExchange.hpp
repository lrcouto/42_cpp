/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 23:48:26 by lcouto            #+#    #+#             */
/*   Updated: 2023/03/14 23:48:26 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <string>
# include <map>

class BitcoinExchange
{
private:
    std::map<std::string, double>   _exchangeRate;
    std::string                     _userInput;

    std::map<std::string, double>   csvToExchangeRate(std::string filePath);

public:
    BitcoinExchange();
    BitcoinExchange(const char *filePath);
    BitcoinExchange(const BitcoinExchange& other);
    ~BitcoinExchange();
    BitcoinExchange &operator=(const BitcoinExchange& other);

    getUserInput(const char *filePath);

};

#endif