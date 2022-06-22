/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 00:27:43 by lcouto            #+#    #+#             */
/*   Updated: 2022/06/22 03:35:03 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Brain.hpp"
# include <iostream>
# include <cstdlib>
# include <ctime>
# include <sstream>

std::string Brain::ideas[100] = {"XZQZXxnUy4",
                                "68p6JmRLhd",
                                "jVQ4FpcNQK",
                                "FivEaHEKzX",
                                "6zPY3V4pjn",
                                "KCxdHtIi9T",
                                "xNuskxG0dm",
                                "mvDEG233r6",
                                "udgkgN35SQ",
                                "Fui54Mg0ts",
                                "AYWHsK4gbG",
                                "7N1LDUMEoL",
                                "OVgswwhB1V",
                                "rxgTEDwFol",
                                "vWVLoaFklR",
                                "baX19UjmnH",
                                "7ScSz6sC9d",
                                "eN9VJvXm8i",
                                "2p0jL3cPOW",
                                "x9biARxZ7z",
                                "BEnf0cqUgX",
                                "kx1OmZIbaP",
                                "QIjTp7AFfp",
                                "TY8mOwofIG",
                                "fjAgABqEy3",
                                "bWZHd6ol3m",
                                "fUGGErX5kV",
                                "YqhGiI8A7X",
                                "aLMw7gXtMy",
                                "rmWWeFCnwx",
                                "szUYEN0UUB",
                                "tbS2xwZtpI",
                                "TY15HW0hTG",
                                "J47HO3YvLb",
                                "b4urwEiNKf",
                                "JdoOu3NKXS",
                                "fioGip8v8C",
                                "8LB4zss9bS",
                                "4h3XeymQTc",
                                "m8shcmIB3O",
                                "YpAqX71S9P",
                                "ZNcYk2HP7C",
                                "fjDr2Sf6Vl",
                                "OXyYjuYGmx",
                                "8a7DlplESJ",
                                "0hz8l7Lsld",
                                "KEIfTl692l",
                                "ia3MGJzeYv",
                                "WSTpbMJ8Zn",
                                "fYwBPnG7EO",
                                "DgIzJnj1Ur",
                                "6QIVXC6XIM",
                                "AI54Pvi9J0",
                                "CkZH5Gt5bb",
                                "9jZ5IWlwGN",
                                "YB9Z2CLdUZ",
                                "dHone0FsmA",
                                "MaWix1vQog",
                                "RJdEsvsycB",
                                "13lpGMsmPX",
                                "rpq2gvwf6m",
                                "pq5Oy4orNC",
                                "SlCgOTGA3M",
                                "djdNyQ7S6c",
                                "ICErIARwr0",
                                "vCookj7xtx",
                                "zMfvZjAlUc",
                                "LgB5LYqyFJ",
                                "J6b09Y219n",
                                "2t3D8nZZZY",
                                "cIY1ceogzi",
                                "aN1vwRmWxx",
                                "QhMdp4auTW",
                                "BBlmGSD4jb",
                                "dPS0EfNaHs",
                                "wkf7v5YpsP",
                                "t2uNywByeN",
                                "cbc7ZoX23S",
                                "qhLJFHcVbE",
                                "vYRwpJdQWu",
                                "448izsUhzv",
                                "OX8SCNbWxO",
                                "GvDFS1nIDR",
                                "LVXuZieWnw",
                                "ohj19P6s52",
                                "Zkatdl3Auy",
                                "AB9PD1z4VB",
                                "rKFp92Di7H",
                                "upJF6zJQMH",
                                "TiMsfQYgtX",
                                "Th9i5v2t0U",
                                "palk1jjj5I",
                                "BsHNZGnCuL",
                                "tNA9ZkhsSp",
                                "AxgCT8bcXm",
                                "uMHEauwstL",
                                "frEqt54rqD",
                                "Q4Va3Qnz8f",
                                "j5PCI7NBbu",
                                "2AwBhHfbT0"};

Brain::Brain(void)
{
    srand((unsigned int)time(NULL));
    for (int i = 0; i < 100; i++)
        this->ideas[i] = Brain::ideas[rand() % 100];
	return ;
}

Brain::~Brain(void)
{
	return ;
}

Brain::Brain(Brain const &instancedObject)
{
	*this = instancedObject;
	return ;
}

Brain &Brain::operator=(Brain const &rightHandSide)
{
	for(int i = 0; i < 100; i++)
		this->ideas[i] = rightHandSide.ideas[i];
	return (*this);
}
