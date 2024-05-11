/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 12:49:29 by caalbert          #+#    #+#             */
/*   Updated: 2024/02/27 23:27:52 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Base.hpp"

int main(void)
{
	 std::cout << "[ CLASS A ]\n";
  A *a = new A();
  identify(a);
  identify(*a);
  delete a;

  std::cout << "\n";

  std::cout << "[ CLASS B ]\n";
  B *b = new B();
  identify(b);
  identify(*b);
  delete b;

  std::cout << "\n";

  std::cout << "[ CLASS C ]\n";
  C *c = new C();
  identify(c);
  identify(*c);
  delete c;

  std::cout << "\n";

  std::cout << "[ CLASS INVALID ]\n";
  Base *base = new Base();
  identify(base);
  identify(*base);
  delete base;

  std::cout << "\n";

  std::cout << "[ RANDOM CLASS]\n";
  Base *random = generate();
  identify(random);
  identify(*random);
  delete random;

}
