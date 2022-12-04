/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_test.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan <ntan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 17:21:29 by ntan              #+#    #+#             */
/*   Updated: 2022/12/04 22:02:39 by ntan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Config.hpp"
# include <iostream>
# include <fstream>
# include <string>

int main()
{
	try
	{	
		char *str = (char *)"../../config_files/default.conf";
		Config conf(str);
	}
	catch (std::exception e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}