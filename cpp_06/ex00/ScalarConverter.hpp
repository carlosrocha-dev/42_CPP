/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 10:20:42 by caalbert          #+#    #+#             */
/*   Updated: 2024/02/27 23:26:05 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <cstdlib>
# include <sstream>
# include <string>
# include <math.h>
# include <stdlib.h>

typedef enum {
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	INV
} e_type;

class ScalarConverter {
	private:
		static std::string	_literals;
		static e_type		_type;
		static void			_print_c(char c);
		static void			_print_i(int i);
		static void			_print_f(float f);
		static void			_print_d(double d);

	public:
		ScalarConverter();
		ScalarConverter(ScalarConverter const &src);
		~ScalarConverter();
		ScalarConverter &operator=(ScalarConverter const &rhs);
		static void convert(std::string literals);
		static e_type findType(std::string literals);
};

#endif
