/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 23:48:30 by lcouto            #+#    #+#             */
/*   Updated: 2023/03/14 23:48:30 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "BitcoinExchange.hpp"
# include <fstream>
# include <sstream>
# include <stdlib.h>

BitcoinExchange::BitcoinExchange(): _userInput("");
{
    this->_exchangeRate = csvToExchangeRate("data.csv");
    return;
}

BitcoinExchange::BitcoinExchange(std::string filePath)
{
    getUserInput(filePath);
    this->_exchangeRate = csvToExchangeRate("data.csv");
    return;
}

BitcoinExchange::~BitcoinExchange()
{
    std::map<std::string, double>::const_iterator it;
    for (it = this->_exchangeRate.begin(); it != this->_exchangeRate.end(); ++it) {
        std::cout << it->first << ": " << it->second << std::endl;
    }
    return;
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &other) 
{
    *this = other;
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &other) 
{
    if (this == &other)
        return *this;

    this->_exchangeRate = other._exchangeRate;

    return *this;
}

std::map<std::string, double> BitcoinExchange::csvToExchangeRate(std::string const filePath)
{
    std::map<std::string, double>       exchangeRateMap;
    std::string                         line;
    std::ifstream                       fileStream(filePath.c_str());

    while (std::getline(fileStream, line)) {
        std::istringstream lineStream(line);
        std::string key, value;
        if (std::getline(lineStream, key, ',') && std::getline(lineStream, value)) {
            exchangeRateMap[key] = strtod(value.c_str(), NULL);
        }
    }

    fileStream.close();
    exchangeRateMap.erase("date");
    return exchangeRateMap;
}

void BitcoinExchange::getUserInput(std::string filePath)
{
    this->_userInput = filePath;
}

void processInput()
{
    std::string                         line;
    std::ifstream                       fileStream(this->_userInput.c_str());

    while (std::getline(fileStream, line)) {
        std::istringstream lineStream(line);
        std::string date, value;
        if (std::getline(lineStream, date, '|') && std::getline(lineStream, value)) {
            validateDate(date);
            validateValue(date, value);
        }
    }

    fileStream.close();
}

void BitcoinExchange::validateDate(std::string date)
{
    // TODO: write format validation.
    std::cout << date;
}

void BitcoinExchange::validateValue(std::string value)
{
    multipliedValue = static_cast<int>(value);
    std::cout << intValue * this->_exchangeRate[date];
}