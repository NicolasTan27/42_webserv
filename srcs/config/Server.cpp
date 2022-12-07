/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan <ntan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 16:47:35 by ntan              #+#    #+#             */
/*   Updated: 2022/12/07 19:17:03 by ntan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Server.hpp"

Server::Server() {}

Server::~Server() {}


Server::Server(std::string text) :	textfile(text),
	// **ADD KEYS HERE, DEFAULT VALUES, DON'T LET SPACES BETWEEN VALUES
	// usage : object("object", "values seperated by delim", "delim", mandatory?, multiargs?)
	listen("listen", "0.0.0.0:8080", ":", false, true),
	server_name("server_name", "", "", false, false),
	client_max_body_size("client_max_body_size", "100", "", false, false),
	error_page("error_page", "404,errors_pages/error404.html", ",", false, true)								
{
	parse_lines();
} 

////// DEBUG FUNCTIONS //////

std::string	Server::getTextfile()
{
	return (this->textfile);
}


void		Server::print_config()
{
	// **ADD KEYS HERE
	listen.print();
	server_name.print();
	client_max_body_size.print();
	error_page.print();
}

//////////  STATIC  //////////

void	remove_newline(std::string &str)
{
	while (str.find("\n") != std::string::npos)
	{
		str.erase(str.find("\n"));
	}
}

//////////////////////////////

void	Server::parse_lines_forest(std::string name, std::string value)
{
	//	**ADD KEYS HERE
	if (name == "listen")
		listen.setValue(value);
	else if (name == "server_name")
		server_name.setValue(value);
	else if (name == "client_max_body_size")
		client_max_body_size.setValue(value);
	else if (name == "error_page")
		error_page.setValue(value);
	else if (name == "location")
}

void	Server::parse_lines()
{
	size_t pos = 0, delim = 0;
	std::string line, name, value;
	while (pos != std::string::npos)
	{
		line = textfile.substr(pos, textfile.find("\n", pos));
		remove_newline(line);
		
		delim = line.find(":");
		if (delim != std::string::npos)
		{
			name = line.substr(0, delim);
			value = line.substr(delim + 1);
			parse_lines_forest(name, value);
		}
		
		pos = textfile.find("\n", pos);
		if (pos != std::string::npos)
			pos += 1;
	}
}