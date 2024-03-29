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
# include <fstream>
# include <sstream>
# include <stdlib.h>
# include <iomanip>

class BitcoinExchange
{
private:
    std::map<std::string, double>   _exchangeRate;
    const char                      *_userInput;

    std::map<std::string, double>   csvToExchangeRate(std::string filePath);
    std::string                     validateDate(std::string line);
    double                          validateValue(std::string line, double rate);
    double                          getClosestExchangeRate(std::string date);

public:
    BitcoinExchange();
    BitcoinExchange(const char *filePath);
    BitcoinExchange(const BitcoinExchange& other);
    ~BitcoinExchange();
    BitcoinExchange &operator=(const BitcoinExchange& other);

    void        setUserInput(const char *filePath);
    void        processInput();
};

#endif