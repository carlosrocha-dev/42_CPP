/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 22:12:14 by caalbert          #+#    #+#             */
/*   Updated: 2024/02/29 08:07:16 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <vector>
#include <algorithm>
#include <stdexcept>

template <typename T>
typename T::iterator easyfind(T &container, int searchValue)
{
	typename T::iterator it = std::find(container.begin(), container.end(), searchValue);
	if (it == container.end() && *it != searchValue)
	{
		throw std::runtime_error("Value not found in container");
	}
	return it;
}

#endif
