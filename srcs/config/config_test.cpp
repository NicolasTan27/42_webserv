/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_test.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan <ntan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 17:21:29 by ntan              #+#    #+#             */
/*   Updated: 2022/12/05 17:43:45 by ntan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Config.hpp"
# include <iostream>
# include <fstream>
# include <string>

int main()
{
	char *str = (char *)"../../config_files/default.conf";
	try
	{
		Config conf(str);	
		conf.printServers();
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
		return (1);		
	}
	return (0);
}