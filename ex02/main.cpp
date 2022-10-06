/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoffo <ljoffo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 14:26:32 by ljoffo            #+#    #+#             */
/*   Updated: 2022/08/22 19:51:39 by ljoffo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base * generate(void)
{
	srand (time(NULL));
	int nb = rand() % 3;
	Base * ptr;

	if (nb == 0)
		ptr = new A();

	if (nb == 1)
		ptr = new B();

	if (nb == 2)
		ptr = new C();
	return ptr;
}

void identify(Base* p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "A" << std::endl;
	if (dynamic_cast<B *>(p))
		std::cout << "B" << std::endl;
	if (dynamic_cast<C *>(p))
		std::cout << "C" << std::endl;
}

void identify(Base& p)
{
	try
	{
		A inst = dynamic_cast<A &>(p);
		std::cout << "A" << std::endl;
	}
	catch (std::exception & e){}

	try
	{
		B inst = dynamic_cast<B &>(p);
		std::cout << "B" << std::endl;
	}
	catch (std::exception & e){}

	try
	{
		C inst = dynamic_cast<C &>(p);
		std::cout << "C" << std::endl;
	}
	catch (std::exception & e){}
	
}

int main(void)
{
	std::cout << "pointer randomly generated to classe A, B or C" << std::endl;
	Base * ptr = generate();
	
	std::cout << "class identified from pointer: "; 
	identify(ptr);
	
	std::cout << "class identified from reference: "; 
	identify(*ptr);
	
	delete ptr;
}