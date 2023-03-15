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
# include <map>

class BitcoinExchange
{
private:

public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& other);
    ~BitcoinExchange();
    BitcoinExchange& operator=(const BitcoinExchange& other);
};

#endif