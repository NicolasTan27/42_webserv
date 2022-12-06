/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan <ntan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 16:47:35 by ntan              #+#    #+#             */
/*   Updated: 2022/12/06 19:44:47 by ntan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Server.hpp"

Server::Server() {}

Server::~Server() {}

Server::Server(std::string text) :	textfile(text),
	listen("listen", "0.0.0.0:8080", ":", false, true),
	server_name("server_name", "", "", false, false),
	client_max_body_size("client_max_body_size", "100", "", false, false),
	error_page("error_page", "404, errors_pages/error404.html", ",", false, true)								
{
	// std::cout << "listen : [" << listen.values[0] << "]" << std::endl;
	parse_lines();
} 

// Server &Server::operator=(const Server &other)
// {
// 	this->textfile = other.textfile;
// 	this->listen = other.listen;
// 	this->server_name = other.server_name;
// 	this->client_max_body_size = other.client_max_body_size;
// 	this->error_page = other.error_page;
	
// 	return (*this);
// }

////// DEBUG FUNCTIONS //////

std::string	Server::getTextfile()
{
	return (this->textfile);
}

void		Server::print_config()
{
	listen.print();
	server_name.print();
}

//////////////////////////////

void	Server::parse_lines()
{
	size_t pos = 0, delim = 0;
	std::string line, name, value;
	while (pos != std::string::npos)
	{
		line = textfile.substr(pos, textfile.find("\n", pos));
		delim = line.find(":");
		name = line.substr(0, delim);
		value = line.substr(delim + 1);

		if (name == "listen")
			listen.setValue(value);
		else if (name == "server_name")
			server_name.setValue(value);

		pos = textfile.find("\n", pos + 1);
	}
}