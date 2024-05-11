/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 12:49:17 by caalbert          #+#    #+#             */
/*   Updated: 2024/02/27 23:27:43 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

#include <cstdlib>
#include <iostream>

class Base {
 public:
  virtual ~Base(void) {}
};

class A : public Base {};

class B : public Base {};

class C : public Base {};

Base* generate(void);
void identify(Base* p);
void identify(Base& p);

#endif
