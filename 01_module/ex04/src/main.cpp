/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 22:29:04 by lcouto            #+#    #+#             */
/*   Updated: 2022/06/14 23:59:47 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <fstream>
# include <sstream>

std::string	replaceSubstrings(std::string &string, std::string originalSubstring, std::string replacementSubstring)
{
	const size_t	originalLength = originalSubstring.length();
	const size_t	replacementLength = replacementSubstring.length();
	std::string		newString = string;

	if (string.find(originalSubstring) == std::string::npos)
		return(string);

	for (size_t position = 0; position != std::string::npos; position += replacementLength)
    {
        position = newString.find(originalSubstring, position);
        if (position == std::string::npos)
            break;
        newString.erase(position, originalLength);
        newString.insert(position, replacementSubstring);
    }
	return (newString);
}

std::string	replaceFileExtension(std::string path)
{
	size_t position = path.find_last_of(".");
	std::string result = path;
	if (position == std::string::npos)
		return (result.append(".replace"));
	std::string extension = path.substr(position);
    result.erase(position, extension.length());
    result.insert(position, ".replace");
	return (result);
}

int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "Wrong number of arguments. Usage: ./SedIsForLosers <filename> <original string> <replacement string>." << std::endl;
		return (-1);
	}

	std::ifstream		inputFile(argv[1], std::ios::in);
	std::ostringstream	buffer;

	if (!inputFile.is_open())
	{
		std::cerr << "Cannot open file. Please check if the file path is correct." << std::endl;
		return (-1);
	}

	buffer << inputFile.rdbuf();

	std::string	  fileContent;
	fileContent = buffer.str();
	
	std::string   newFileContent = replaceSubstrings(fileContent, argv[2], argv[3]);

	std::string filePath = argv[1];
	std::string outputFilePath = replaceFileExtension(filePath);
	std::ofstream outputFile(outputFilePath.c_str(), std::ios::out | std::ios::trunc);
	outputFile << newFileContent;

	inputFile.close();
	outputFile.close();

	return (0);
}