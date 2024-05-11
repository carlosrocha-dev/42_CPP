/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileReplacer.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 18:56:55 by caalbert          #+#    #+#             */
/*   Updated: 2024/02/01 02:44:28 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FileReplacer.hpp"
#include <fstream>
#include <sstream>
#include <iostream>

void FileReplacer::replaceStringInFile(const std::string& filename, const std::string& s1, const std::string& s2) {
	std::ifstream fileIn(filename.c_str());
	if (!fileIn) {
		std::cerr << "Error opening file: " << filename << std::endl;
		return;
	}

	std::stringstream buffer;
	buffer << fileIn.rdbuf();
	std::string content = buffer.str();
	fileIn.close();

	size_t pos = 0;
	while ((pos = content.find(s1, pos)) != std::string::npos) {
		content.replace(pos, s1.length(), s2);
		pos += s2.length();
	}

	std::ofstream fileOut((filename + ".replace").c_str());
	if (!fileOut) {
		std::cerr << "Error creating file: " << filename + ".replace" << std::endl;
		return;
	}

	fileOut << content;
	fileOut.close();
}
