/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 13:29:08 by lcouto            #+#    #+#             */
/*   Updated: 2023/03/19 13:29:08 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <string>
# include <stack>

class RPN
{
private:
    std::stack<int>     _operationStack;
    const char          *_userInput;

    void                processInput();

public:
    RPN();
    RPN(const char *input);
    RPN(const RPN& other);
    ~RPN();
    RPN &operator=(const RPN& other);

    void    setUserInput(const char *input);
};

#endif