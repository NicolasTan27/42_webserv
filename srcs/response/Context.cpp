/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Context.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan <ntan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 00:28:01 by ntan              #+#    #+#             */
/*   Updated: 2022/12/12 16:25:22 by ntan        	     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Context.hpp"

Context::Context(Config conf, Request req) : config(conf), request(req)
{
	find_server();
	this->server = this->servers[0];

	this->location = Location();
	find_location();
	this->server.locations_count = 1;
	this->server.locations[0] = this->location;
}

void	Context::find_server()
{
	// If there is no server in config file, use default server
	if (this->config.servers_count == 0)
	{
		this->servers.push_back(this->config.servers[0]);
		std::cout << "No server corresponding in config file, using default server" << std::endl;
		return ;
	}

	// Search a server with exact same ip and port
	for (size_t i = 0; i < this->config.servers_count; i++)
	{
		if ((this->config.servers[i].listen[0] == "127.0.0.1" 
				|| this->config.servers[i].listen[0] == "localhost")
				&& this->config.servers[i].listen[1] == this->request.host[1])
			this->servers.push_back(this->config.servers[i]);
	}

	// Consider server witout ip or with default ip 0.0.0.0 if no server found
	// (server without ip get 0.0.0.0 by default in server.cpp)
	if (this->servers.empty())
	{
		for (size_t i = 0; i < this->config.servers_count; i++)
		{
			if (this->config.servers[i].listen[0] == "0.0.0.0"
					&& this->config.servers[i].listen[1] == this->request.host[1])
				this->servers.push_back(this->config.servers[i]);
		}
	}

	if (this->servers.size() == 1)
		return ;
	
	// find the server with the same server_name
	for (size_t i = 0; i < this->servers.size(); i++)
	{
		if (this->servers[i].server_name[0] == this->request.host[0])
		{
			this->servers.insert(this->servers.begin(), this->servers[i]);
			break;
		}
	}
}

// prioritize exact path, then / path, then default location if no location found
void	Context::find_location()
{
	if (this->servers.empty())
		return ;

	// Search a location with exact same path
	for (size_t i = 0; i < this->server.locations_count; i++)
	{
		if (this->server.locations[i].path == this->request.path)
		{
			this->location = this->servers[0].locations[i];
			return;
		}
	}

	for (size_t i = 0; i < this->server.locations_count; i++)
	{
		if (this->server.locations[i].path.values[0] == "/")
		{
			this->location = this->server.locations[i];
			return;
		}
	}
}

/* ************************************************************************** */
/* DEBUG */

void	Context::print_context()
{
	std::cout << "----- [CONTEXT] -----" << std::endl;
	if (this->servers.empty())
		std::cout << "No server found" << std::endl;
	else
		this->server.print_config();
}