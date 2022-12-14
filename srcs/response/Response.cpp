/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Response.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan <ntan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 15:49:06 by ntan              #+#    #+#             */
/*   Updated: 2022/12/14 16:43:47 by ntan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Response.hpp"

Response::Response(Context cont) : context(cont),
	version_code_message("version_code_message", "HTTP/1.1;200;OK", ";"),
	server("Server", "42Webserv", ""),
	content_length("Content_Length", "13", ""),
	content_type("Content_Type", "text/plain", ""),
	body("body", "Hello world!", "")
{
	make_response();
}

void	Response::print_response()
{
	std::cout << std::endl;
	std::cout << "----- [RESPONSE] -----" << std::endl;
	version_code_message.print();
	content_type.print();
	server.print();
	body.print();
}

void	Response::make_response()
{
	// http 
	this->response += version_code_message[0] + " " + version_code_message[1] + " " + version_code_message[2] + "\n";
	
	// header
	this->response += server.name + ": " + server[0] + "\n";
	this->response += content_length.name + ": " + content_length[0] + "\n";
	this->response += content_type.name + ": " + content_type[0] + "\n";

	// body
	this->response += "\n" + body[0];
}

const char	*Response::get_response()
{
	return (response.c_str());
}