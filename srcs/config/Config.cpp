/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Config.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan <ntan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 16:41:21 by ntan              #+#    #+#             */
/*   Updated: 2022/12/05 16:51:30 by ntan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Config.hpp"

Config::Config() : servers_count(0) {}

Config::~Config() {}

Config::Config(char const *path) : servers_count(0)
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

void	Config::printServers()
{
	for (size_t i = 0; i < servers_count; i++)
	{
		std::cout << "[ SERVER : " << i << " ]" << std::endl;
		std::cout << servers[i].getTextfile() << std::endl;
	}
		 
}

///////// STATIC FUNCTIONS /////////

void	print_exit(char const *error, std::string msg)
{
	std::cout << error << msg << std::endl;
	exit(1);
}

void	print_exit(char const *error, size_t num)
{
	std::cout << error << num << std::endl;
	exit(1);
}

///////// PRIVATE FUNCTIONS /////////

int	Config::read_config_file(char const *path)
{
	std::fstream	fs(path, std::fstream::in);
	if (!(fs.is_open()))
		throw (std::exception());
	// this->textfile = std::string((std::istreambuf_iterator<char>(fs)),
	// 					std::istreambuf_iterator<char>());
	std::string line;
	while (getline(fs, line))
	{
		line.erase(std::remove_if(line.begin(), line.end(), isspace), line.end());
		if (line[0] == '#' || line.empty())
			continue;
		textfile.append(line + "\n");
	}
	return (0);
}

int	Config::parse_server_blocks()
{
	std::string keyword = "server";
	std::string open_bracket = "{";
	std::string close_bracket = "}";
	size_t pos = 0;
	size_t index = 0;
	while (pos != std::string::npos)
	{
		pos = this->textfile.find(keyword, index);
		if (pos == std::string::npos)
			break;
		size_t first = textfile.find(open_bracket, pos);
		size_t last = textfile.find(close_bracket, pos);

		// ERRORS CHECKING //
		if (first != std::string::npos && last == std::string::npos) 
			print_exit("ERROR: Missing operator: ", close_bracket);
		if (first == std::string::npos && last != std::string::npos)
			print_exit("ERROR: Missing operator: ", open_bracket);
		if (textfile[pos + keyword.size()] != open_bracket[0]) 
			print_exit("ERROR: Unrecognized : ", textfile.substr(pos, first - pos));
		if (last < first)
			print_exit("ERROR: Incorrect use of { or } at pos: ", last);
		first += 2;
		addServer(textfile.substr(first , last - first));
		index = last;
	}
	return (0);
}

void	Config::addServer(std::string server_block)
{
	this->servers[servers_count] = Server(server_block);
	servers_count++;
}
