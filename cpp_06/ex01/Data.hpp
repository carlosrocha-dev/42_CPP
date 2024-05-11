/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 11:33:51 by caalbert          #+#    #+#             */
/*   Updated: 2024/02/27 23:26:24 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

# include <iostream>
# include <stdint.h>

class Data
{
private:
	std::string _name;
	int _len;
	int _height;

public:
	Data();
	Data(std::string name, int len, int height);
	~Data();
	Data(Data const &src);
	Data &operator=(Data const &rhs);
	std::string getName();
	int getLen();
	int getHeight();
	void setLen(int len);
	void setHeight(int height);
	void setName(std::string name);
	double calcIMC();
};

#endif
