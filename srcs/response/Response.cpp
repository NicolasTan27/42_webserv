/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Response.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan <ntan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 15:49:06 by ntan              #+#    #+#             */
/*   Updated: 2022/12/16 18:32:33 by ntan             ###   ########.fr       */
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
	check_response();
	make_body();
	make_response();
}

/////////////////////////////////////////////////////////////////////////////////
///////////////////////////// CHECK RESPONSE FIELDS /////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

void	Response::check_response()
{
	if (check_allowed_methods())
		return (set_status("405"));
	if (check_max_body_size())
		return (set_status("413"));
	if (check_version())
		return (set_status("505"));
	set_status("200");
}

int		Response::check_allowed_methods()
{
	typedef std::vector<std::string>::iterator	iterator;
	iterator	beg = context.location.allowed_methods.values.begin();
	iterator	end = context.location.allowed_methods.values.end();
	std::string	find = context.request.method[0];
	if (std::find(beg, end, find) == end)
		return (1);
	return (0);
}

int		Response::check_version()
{
	if (context.request.version[0] != "HTTP/1.1")
		return (1);
	return (0);
}

int		Response::check_max_body_size()
{
	typedef std::vector<std::string>::iterator	iterator;
	iterator	beg = context.request.body.values.begin();
	iterator	end = context.request.body.values.end();
	size_t		count = 0;
	for (;beg != end; beg++)
	{
		count += (*beg).size();
	}

	if (count > std::atof(context.server.client_max_body_size[0].c_str()))
		return (1);
	return (0);
}

int		Response::check_file()
{
	std::string 	path = context.location.root[0] + context.request.path[0]; 
	std::fstream	fs(path.c_str(), std::fstream::in);

	if (fs.is_open())
		return (fs.close(), 0);
	return (1);
}

void	Response::set_status(std::string code)
{
	this->version_code_message[0] = "HTTP/1.1";
	this->version_code_message[1] = code;
	this->version_code_message[2] = status.get_message(code);
}

/////////////////////////////////////////////////////////////////////////////////
///////////////////////// MAKE BODY ACCORDING TO STATUS /////////////////////////
/////////////////////////////////////////////////////////////////////////////////

void	Response::make_body()
{
	std::string temp = "Status code : " + version_code_message[1] + "/" + version_code_message[2];
	body[0] = temp;
}

/////////////////////////////////////////////////////////////////////////////////
////////////////////////// FINAL RESPONSE ASSEMBLER /////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

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

///////////////////////////////////////////////////////////////////////////////////// 

void	Response::print_response()
{
	std::cout << std::endl;
	std::cout << "----- [RESPONSE] -----" << std::endl;
	version_code_message.print();
	content_type.print();
	server.print();
	body.print();
}
 