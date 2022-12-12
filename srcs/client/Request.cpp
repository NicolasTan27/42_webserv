/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Request.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan <ntan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 14:04:34 by ntan              #+#    #+#             */
/*   Updated: 2022/12/12 18:16:10 by ntan             ###   ########.fr       */
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
	body("body", "", "")
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
					body.addValue(line);
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
}

/* ************************************************************************** */
/* DEBUG */

void	Request::print_request()
{
	std::cout << "----- [REQUEST] -----" << std::endl;
	method.print();
	path.print();
	version.print();
	host.print();
	body.print();
	std::cout << std::endl;
}