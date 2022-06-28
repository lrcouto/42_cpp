/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreatonForm.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 20:46:55 by lcouto            #+#    #+#             */
/*   Updated: 2022/06/28 03:29:37 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include "Form.hpp"

class ShrubberyCreatonForm : public Form
{
    private:
        std::string const m_target;

    public:
        ShrubberyCreationForm(void);
        ShrubberyCreationForm(std::string name, std::string target);
        ~ShrubberyCreationForm(void);
		ShrubberyCreationForm(ShrubberyCreationForm const& instance);
		ShrubberyCreationForm	&operator=(ShrubberyCreationForm const &rightHandSide);

        std::string             getTarget(void);
		bool					execute(Bureaucrat const &executor) const;
};

std::ostream &operator<<(std::ostream &output, ShrubberyCreationForm const &instance);

#endif
