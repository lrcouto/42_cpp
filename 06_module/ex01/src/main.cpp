/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 22:04:39 by lcouto            #+#    #+#             */
/*   Updated: 2022/07/17 22:39:52 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Data.hpp"
# include <iostream>

int main(void)
{
    Data *myData = new Data();
    myData->content = 10.567;
    std::cout << "Now printing the original data content: " << myData->content << std::endl;

    uintptr_t serializedDataPointer;
    Data *deserializedDataPointer;

    serializedDataPointer = serialize(myData);
    deserializedDataPointer = deserialize(serializedDataPointer);
    std::cout << "Now printing serialized/deserialized data content: " << deserializedDataPointer->content << std::endl;

    delete myData;
    return (0);
}
