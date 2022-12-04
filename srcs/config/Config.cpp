/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Config.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan <ntan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 16:41:21 by ntan              #+#    #+#             */
/*   Updated: 2022/12/04 22:31:24 by ntan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Config.hpp"

Config::Config() {}

Config::~Config() {}

Config::Config(char const *path)
{
	try 
	{
		read_config_file(path);
		parse_server_blocks();
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << "CONFIG ERROR" << std::endl;
	}
}

std::string	Config::getConfig()
{
	return (this->textfile);
}

///////// STATIC FUNCTIONS /////////

int	Config::read_config_file(char const *path)
{
	std::fstream	fs(path, std::fstream::in);
	if (!(fs.is_open()))
		throw (std::exception());	
	this->textfile = std::string((std::istreambuf_iterator<char>(fs)),
						std::istreambuf_iterator<char>());
	return (0);
}

int	Config::parse_server_blocks()
{
	size_t pos = 0, beg = 0, end = 0;
	while (pos)
	{
		beg = textfile.find("<server>", pos);
		end = textfile.find("</server>", beg);
		if (beg && end && (beg != end))
		{
			std::cout << "from pos " << pos << std::endl;
			std::string res(&textfile[beg], end - beg);
			std::cout << res << std::endl;
		}
		else
		{
			break;
		}
		pos = end + 1;
	}
	return (0);
}