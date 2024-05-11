/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 09:29:48 by caalbert          #+#    #+#             */
/*   Updated: 2024/03/03 12:16:28 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RNP_HPP
#define RNP_HPP

#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <string>
#include <stack>
class RPN
{
private:
	std::string _expression;
	std::stack<double> _stack;

public:
	RPN();
	~RPN();
	RPN(const RPN &copy);
	RPN &operator=(const RPN &op);
	explicit RPN(std::string expression);
	std::string get_expression(void) const;
	double calculate(void);
};

#endif
