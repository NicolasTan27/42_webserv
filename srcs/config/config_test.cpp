/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_test.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan <ntan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 17:21:29 by ntan              #+#    #+#             */
/*   Updated: 2022/12/04 18:07:47 by ntan             ###   ########.fr       */
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
		std::cout << conf.getConfig() << std::endl;
	}
	catch (std::exception e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}