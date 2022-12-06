/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan <ntan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 17:15:38 by ntan              #+#    #+#             */
/*   Updated: 2022/12/06 19:43:51 by ntan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_HPP
# define SERVER_HPP

# include "Location.hpp"
# include "Keys.hpp"
# include <string>
# include <iostream>

# define MAX_LOCATIONS 10

class Server
{
	public:
		Server();
		Server(std::string text);
		~Server();
		// Server(const Server &other);
		// Server &operator=(const Server &other);

	public:
		std::string	getTextfile();
		void		print_config();
		void		parse_lines();

	private:
		std::string	textfile;
		// Location	locations[MAX_LOCATIONS];
		
		Keys	listen;
		Keys	server_name;
		Keys	client_max_body_size;
		Keys	error_page;
};

/* To add a new keyword :
1- Add the Keys object in Server.hpp
2- Add his default configuration in the Server constructor in Server.cpp
3- Add a if condition in parse_lines 
4- Add in oeprator= */
#endif