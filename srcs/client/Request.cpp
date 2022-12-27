/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Request.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan <ntan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 14:04:34 by ntan              #+#    #+#             */
/*   Updated: 2022/12/27 19:11:12 by ntan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Request.hpp"

Request::Request() {}

Request::Request(std::string request) : request(request),
	// http("http", "", " "),
	method("method", "GET", ""),
	path("path", "/", ""),
	version("version", "HTTP", ""),
	host("host", "127.0.0.1:8000", ":"),
	body("body", "", ""),
	user_agent("user_agent", "", "")
{
	parse_request();
}

/* ************************************************************************** */
/* MAIN */

void	Request::parse_request()
{
	std::string name, value;
	size_t i = 0, delim = 0, endline = 0;
	while (endline != std::string::npos)
	{
		endline = request.find("\n");
		if (request.size() == 0)
			break;
		std::string line(request.substr(0, endline));
		request = request.substr(endline + 1);
		if (i == 0)									// parse the first line
		{
			Keys http("http", "", " ");
			http.setValue(line);
			method.setValue(http[0]);
			path.setValue(http[1]);
			version.setValue(http[2]);
			if (version.values[0].find("\r") != std::string::npos)
				version.values[0].erase(version.values[0].find("\r"));
		}
		else
		{
			delim = line.find(":");
			if (delim != std::string::npos) 		// if in header part
			{
				name = line.substr(0, delim);
				value = line.substr(delim + 1);
				parse_request_forest(name, value);
			}
			else									// if in body part (no ":" found on the line)
			{
				if (!line.empty())
				{
					if (line.find("\r") != std::string::npos)
						line.erase(line.find("\r"));
					body.addValue(line);
				}
				
			}
		}
		i++;
	}
}

void	Request::parse_request_forest(std::string name, std::string value)
{
	value.erase(std::remove_if(value.begin(), value.end(), isspace), value.end());
	if (name == "Host")
	{
		host.setValue(value);
		if (host.values.size() < 2 || host.values[1].empty())
			host.values.push_back("8000"); // Defaut port if not given in the request
	}
	if (name == "User-Agent")
	{
		user_agent.setValue(value);
	}
}

/* ************************************************************************** */
/* DEBUG */

void	Request::print_request()
{
	std::cout << std::endl;
	std::cout << "----- [REQUEST] -----" << std::endl;
	method.print();
	path.print();
	version.print();
	// // std::cout << "name: " << version.values[0] << ";" << std::endl;
	// for (size_t i = 0; i < version.values[0].size(); i++)
	// {
	// 	std::cout << (int) version.values[0][i] << std::endl;
	// }
	host.print();
	body.print();
	user_agent.print();
}