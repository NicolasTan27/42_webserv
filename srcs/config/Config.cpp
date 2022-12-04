/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Config.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan <ntan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 16:41:21 by ntan              #+#    #+#             */
/*   Updated: 2022/12/04 19:08:33 by ntan             ###   ########.fr       */
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
		std::cout << e.what() << std::endl;
		exit(1);
	}
}

std::string	Config::getConfig()
{
	return (this->textfile);
}

///////// STATIC FUNCTIONS /////////

void	Config::read_config_file(char const *path)
{
	std::fstream	fs(path, std::fstream::in);
	if (!(fs.is_open()))
		throw (ConfigErrorException("Could not open file at " + path));	
	this->textfile = std::string((std::istreambuf_iterator<char>(fs)),
						std::istreambuf_iterator<char>());
}

void	Config::parse_server_blocks()
{
	size_t file_size = this->textfile.size();
	size_t pos, beg, end = 0;
	while (pos < file_size)
	{
		beg = textfile.find("<server>", pos);
		end = textfile.find("</server>", pos);
		if (beg == std::string::npos || end == std::string::npos)
			throw (ConfigErrorException("Server block not closed"));
	}
}