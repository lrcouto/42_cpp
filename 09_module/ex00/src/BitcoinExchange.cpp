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
# include <iomanip>

BitcoinExchange::BitcoinExchange(): _userInput("")
{
    this->_exchangeRate = csvToExchangeRate("data.csv");
    return;
}

BitcoinExchange::BitcoinExchange(const char *filePath)
{
    setUserInput(filePath);
    this->_exchangeRate = csvToExchangeRate("data.csv");
    return;
}

BitcoinExchange::~BitcoinExchange()
{
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

void BitcoinExchange::setUserInput(const char *filePath)
{
    this->_userInput = filePath;
}

void BitcoinExchange::processInput()
{
    std::string                         line;
    std::string                         header;
    std::ifstream                       fileStream(this->_userInput);

    std::getline(fileStream, line);
    while (std::getline(fileStream, line)) 
    {
        std::istringstream lineStream(line);
        std::string date = validateDate(line);
        double rate = date.length() == 10 ? getClosestExchangeRate(date) : -1.0;
        double value = date.length() == 10 ? validateValue(line, rate) : -1.0;
        if (date.length() == 10 && value > -1.0 && rate > -1.0)
            std::cout << "\033[32;1m" << date << " => " << value << " = " << value * rate << " \033[0m" << std::endl;
    }
    fileStream.close();
}

std::string BitcoinExchange::validateDate(std::string line)
{
    std::string date = line.substr(0, 10);
    std::stringstream ss;
    int year, month, day;
    ss.str(date.substr(0, 4));
    ss >> year;
    ss.clear();
    ss.str(date.substr(5, 7));
    ss >> month;
    ss.clear();
    ss.str(date.substr(8, 10));
    ss >> day;

    if (year < 2009)
    {
        std::cerr << "\033[31;1mInformation unavailable. Earliest year available: 2009.\033[0m" << std::endl;
        return "";
    }
    if ((month < 1 || month > 12) || (day < 1 || day > 31))
    {
        std::cerr << "\033[31;1mImpossible date: " << date << "\033[0m" << std::endl;
        return "";
    }
    if (date[4] != '-' || date[7] != '-')
    {
        std::cerr << "\033[31;1mInvalid date format. Expected: YYYY-MM-DD.\033[0m" << std::endl;
        return "";
    }
    for (int i = 0; i < 10; i++) 
    { 
        if (i == 4 || i == 7)
            continue;
        if (date[i] < '0' || date[i] > '9')
        {
            std::cerr << "\033[31;1mDate must be only digits. Expected format: YYYY-MM-DD.\033[0m" << std::endl;
            return "";
        }
    }
    return date;
}

double BitcoinExchange::validateValue(std::string line, double rate)
{
    unsigned long int pipePosition = line.find('|');
    if (pipePosition == std::string::npos)
    {
        std::cerr << "\033[31;1mInvalid input format. Expected: 'YYYY-MM-DD | value'.\033[0m" << std::endl;
        return -1.0;
    }
    double value = strtod(line.substr(pipePosition + 1, line.length()).c_str(), NULL);
    if (value * rate > 1000 || value * rate < 0)
    {
        std::cerr << "\033[31;1mResulting value is invalid. Final value must be between 0 and 1000.\033[0m" << std::endl;
        return -1.0; 
    }
    return value;
}

double BitcoinExchange::getClosestExchangeRate(std::string date)
{
    std::map<std::string, double>::iterator it = this->_exchangeRate.find(date);
    if (it != this->_exchangeRate.end())
        return it->second;
    else
    {
        int year, month, day;
        std::stringstream ss;
        ss.str(date.substr(0, 4));
        ss >> year;
        ss.clear();
        ss.str(date.substr(5, 7));
        ss >> month;
        ss.clear();
        ss.str(date.substr(8, 10));
        ss >> day;
        ss.clear();
        it = this->_exchangeRate.end();
        while (it == this->_exchangeRate.end())
        {
            if (day > 1) 
                day--;
            else 
            {
                if (month == 1)
                {
                    month = 12;
                    year--;
                }
                else
                {
                    month--;
                }
                day = 31;
            }
            std::ostringstream oss;
            it = this->_exchangeRate.begin();
            oss << year << "-" << std::setw(2) << std::setfill('0') << month << "-" << std::setw(2) << std::setfill('0') << day;
            it = this->_exchangeRate.find(oss.str());
        }
    }
    return it->second;
}