/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoffo <ljoffo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 14:26:32 by ljoffo            #+#    #+#             */
/*   Updated: 2022/08/22 15:37:16 by ljoffo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdint.h>

struct Data {int nbr; std::string str;};

uintptr_t serialize(Data* ptr)
{
	uintptr_t uint = reinterpret_cast<uintptr_t>(ptr);
	return uint;
}

Data* deserialize(uintptr_t raw)
{
	Data* ptrData = reinterpret_cast<Data*>(raw);
	return ptrData;
}

int main(void)
{
	Data* ptr1 = new Data();
	ptr1->nbr = 42;
	ptr1->str = "Hello World!";

	std::cout << std::endl;
	std::cout << "pointer prt1-> struct Data { " << ptr1->nbr << "; " << ptr1->str << ";}" << std::endl << std::endl;

	uintptr_t uint = serialize(ptr1);
	std::cout << "ptr1 converted to unsigned integer type uint: " << uint << std::endl;
	
	Data* ptr2 = deserialize(uint);
	std::cout << "uint converted to Data structure pointer ptr2: " << ptr2 << std::endl << std:: endl;
	
	std::cout << "pointer prt2-> struct Data { " << ptr2->nbr << "; " << ptr2->str << ";}" << std::endl;

	delete ptr1;
}