/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoffo <ljoffo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 14:26:32 by ljoffo            #+#    #+#             */
/*   Updated: 2022/08/19 15:51:51 by ljoffo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <climits>
#include <cfloat>
#include <iomanip>
#include <cmath>

void pseudoFloat(float a)
{
	std::cout << "Literal type is a float: " << a << "f" << std::endl;

	char b = static_cast<char>(a);
	std::cout << "Converted to char: " << b << "impossible" << std::endl;
					
	int c = static_cast<int>(a);
	if (c == -2147483648)
		std::cout << "Converted to int: impossible" << std::endl;
		
	double d = static_cast<double>(a);
	std::cout << "Converted to double: " << d << std::endl;
}

void pseudoDouble(double a)
{
	std::cout << "Literal type is a double: " << a << std::endl;

	char b = static_cast<char>(a);
	std::cout << "Converted to char: " << b << "impossible" << std::endl;
					
	int c = static_cast<int>(a);
	if (c == -2147483648)
		std::cout << "Converted to int: impossible" << std::endl;
		
	float d = static_cast<float>(a);
	std::cout << "Converted to float: " << d << "f" << std::endl;
}

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Wrong number of arguments, need 2 arg" << std::endl;
		return 0;
	}

	std::string str = av[1];
	int i = 0;
	int f = 0;
	
	for (i = 0; str[i]; i++)
	{
		if (str[i] == '.')
		{
			while (str[i+1+f])
				f++;
			if (str[i+f] == 'f')
				f--;
		}
	}
	std::cout << std::fixed << std::setprecision(f);

	if (str == "-inff")
		pseudoFloat(-INFINITY);
	if (str == "+inff" || str == "inff")
		pseudoFloat(+INFINITY);
	if (str == "nanf")
		pseudoFloat(NAN);
	if (str == "-inf")
		pseudoDouble(-INFINITY);
	if (str == "+inf" || str == "inf")
		pseudoDouble(+INFINITY);
	if (str == "nan")
		pseudoDouble(NAN);
	
	if (str.length() == 1 && !isdigit(str[0]) && isprint(str[0]))
	{
		char c = str[0];
		std::cout << "Literal type is a char: " << c << std::endl;
		int m = static_cast<int>(c);
		std::cout << "Converted to int: " << m << std::endl;
		double n = static_cast<double>(c);
		std::cout << "Converted to double: " << n << std::endl;
		float o = static_cast<float>(c);
		std::cout << "Converted to float: " << o << "f" << std::endl;
	}

	else if ((str[0] == '-' && isdigit(str[1])) || isdigit(str[0]))
	{	
		i = 1;
		while (isdigit(str[i]))
			i++;
		if (str[i] == '\0')
		{
			double h = atof(str.c_str());
			if (h < INT_MIN || h > INT_MAX)
				std::cout << "Wrong literal format: too big or too small to be an int" << std:: endl;
			else
			{
				int j = static_cast<int>(h);
				std::cout << "Literal type is an int: " << j << std:: endl;
				
				char p = static_cast<char>(j);
				if (j < 0 || j > 127)
					std::cout << "Converted to char: impossible" << std::endl;
				else if (!isprint(j))
					std::cout << "Converted to char: non displayable" << std::endl;
				else
					std::cout << "Converted to char: " << p << std::endl;
				
				double q = static_cast<double>(j);
				std::cout << "Converted to double: " << q << std::endl;
				
				float r = static_cast<float>(j);
				std::cout << "Converted to float: " << r << "f" << std::endl;
			}	
		}
		else if (str[i] == '.' && isdigit(str[i+1])) 
		{
			i++;
			while (isdigit(str[i]))
				i++;
			if (str[i] == '\0')
			{
				double k = atof(str.c_str());
				std::cout << "Literal type is a double: " << k << std:: endl;

				char s = static_cast<char>(k);
				if (k < 0 || k > 127)
					std::cout << "Converted to char: impossible" << std::endl;
				else if (!isprint(k))
					std::cout << "Converted to char: non displayable" << std::endl;
				else
					std::cout << "Converted to char: " << s << std::endl;
				
				int t = static_cast<int>(k);
				if (t == -2147483648)
					std::cout << "Converted to int: impossible" << std::endl;
				else
					std::cout << "Converted to int: " << t << std::endl;
				
				float u = static_cast<float>(k);
				std::cout << "Converted to float: " << u << "f" << std::endl;
			}
			else if (str[i] == 'f' && str[i+1] == '\0')
			{
				double g = atof(str.c_str());
				if (g < FLT_MIN || g > FLT_MAX)
					std::cout << "Wrong literal format: too big or too small to be a float" << std:: endl;
				else
				{
					float l = static_cast<float>(g);
					std::cout << "Literal type is a float: " << l << "f" << std:: endl;
					
					char v = static_cast<char>(l);
					if (l < 0 || l > 127)
						std::cout << "Converted to char: impossible" << std::endl;
					else if (!isprint(l))
						std::cout << "Converted to char: non displayable" << std::endl;
					else
						std::cout << "Converted to char: " << v << std::endl;

					int w = static_cast<int>(l);
					if (w == -2147483648)
						std::cout << "Converted to int: impossible" << std::endl;
					else
						std::cout << "Converted to int: " << w << std::endl;
					
					double x = static_cast<double>(l);
					std::cout << "Converted to double: " << x << std::endl;
				}
			}
			else 
				std::cout << "Wrong literal format" << std:: endl;
		}
		else 
			std::cout << "Wrong literal format" << std:: endl;
	}
	
	else if (str != "-inff" && str != "+inff" && str != "inff" && str != "nanf" && str != "-inf" && str != "+inf" && str != "inf" && str != "nan")
		std::cout << "Wrong literal format" << std:: endl;
		
	return 0;
}
