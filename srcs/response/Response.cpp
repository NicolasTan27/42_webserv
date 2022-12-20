/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Response.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan <ntan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 15:49:06 by ntan              #+#    #+#             */
/*   Updated: 2022/12/20 15:58:52 by ntan             ###   ########.fr       */
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
	if (check_file())
		return (set_status("404"));
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

	struct stat s;
	if( stat(path.c_str(),&s) == 0 )
	{
		if( s.st_mode & S_IFDIR )
			std::cout << path << " is a directory !" << std::endl;
		else if( s.st_mode & S_IFREG )
			std::cout << path << " is a file !" << std::endl;
		else
			std::cout << path << " is something else ?" << std::endl;
		return (0);
	}
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

void		Response::read_html(std::string path)
{
	std::fstream	fs(path.c_str(), std::fstream::in);
	std::string		html;
	std::string		line;

	if (fs.is_open())
	{
		while (getline(fs, line))
		{
			if ((line[0] == '<' && line[1] == '!')|| line.empty())
				continue;
			html.append(line + "\n");
		}
	}
	add_string_to_vector(html);
	int i = html.size();
	std::stringstream digit;
	digit << i;
	std::string numberString(digit.str());
	content_length[0] = numberString;
	// return (html);
}

void		Response::read_png(std::string path)
{
	std::ifstream input(path.c_str(), std::ios::binary);
    std::vector<unsigned char> buffer((std::istreambuf_iterator<char>(input)), std::istreambuf_iterator<char>());

	for (size_t i = 0; i < buffer.size(); i++)
		charvec_response.push_back(buffer[i]);
	// std::vector<unsigned char>::iterator beg = buffer.begin();
	// std::cout << "vec : ";
	// while (beg != buffer.end())
	// {
	// 	std::cout << (int) *beg;
	// }
	// std::string res;
	// for (std::vector<unsigned char>::iterator beg = buffer.begin(); beg != buffer.end(); beg++)
	// {
	// 	res.append(std::string(1, *beg + 48));
	// }
	
	content_type[0] = "image/jpeg";

	int i = buffer.size();
	std::stringstream digit;
	digit << i;
	std::string numberString(digit.str());
	content_length[0] = numberString;
	// return (res);
}

void	Response::make_body()
{
	std::string temp;
	struct stat s;
	std::string path = context.location.root[0] + context.request.path[0];
	if( stat(path.c_str(),&s) == 0 )
	{
		if( s.st_mode & S_IFDIR )
		{
			// std::cout << path << " is a directory !" << std::endl;
		}
		else if( s.st_mode & S_IFREG )
		{
			// std::cout << path << " is a file !" << std::endl;
			if (context.request.path[0].find_last_of(".html") == context.request.path[0].size() - 1)
				read_html(context.location.root[0] + context.request.path[0]);
			else if (context.request.path[0].find_last_of(".png") == context.request.path[0].size() - 1)
				read_png(context.location.root[0] + context.request.path[0]);
		}
		else
			temp = "Status code : " + version_code_message[1] + "/" + version_code_message[2];
	}
	else
		temp = "Status code : " + version_code_message[1] + "/" + version_code_message[2];
	body[0] = temp;
   
	// set body length
	// int i = body[0].size();
	// std::stringstream digit;
	// digit << i;
	// std::string numberString(digit.str());
	// content_length[0] = numberString;
}

/////////////////////////////////////////////////////////////////////////////////
////////////////////////// FINAL RESPONSE ASSEMBLER /////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

void	Response::add_string_to_vector(std::string str)
{
	for (size_t i = 0; i < str.size(); i++)
		this->charvec_response.push_back(str[i]);
}

void	Response::make_response()
{
	// http 
	// this->response += version_code_message[0] + " " + version_code_message[1] + " " + version_code_message[2] + "\n";
	add_string_to_vector(version_code_message[0] + " " + version_code_message[1] + " " + version_code_message[2] + "\n");
	
	// header
	// this->response += server.name + ": " + server[0] + "\n";
	// this->response += content_length.name + ": " + content_length[0] + "\n";
	// this->response += content_type.name + ": " + content_type[0] + "\n";
	add_string_to_vector(server.name + ": " + server[0] + "\n");
	add_string_to_vector(content_length.name + ": " + content_length[0] + "\n");
	add_string_to_vector(content_type.name + ": " + content_type[0] + "\n");

	// body
	this->response += "\n" + body[0]; 
} 

const char	*Response::get_response()
{
	return (response.c_str());
}

std::vector<unsigned char> Response::get_vector()
{
	return (charvec_response);
}

///////////////////////////////////////////////////////////////////////////////////// 

void	Response::print_response()
{
	std::cout << std::endl;
	std::cout << "----- [RESPONSE] -----" << std::endl;
	version_code_message.print();
	content_length.print();
	content_type.print();
	server.print();
	body.print();
}
 