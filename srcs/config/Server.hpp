/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan <ntan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 17:15:38 by ntan              #+#    #+#             */
/*   Updated: 2022/12/05 19:15:01 by ntan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_HPP
# define SERVER_HPP

# include "Location.hpp"
# include <string>

# define MAX_LOCATIONS 10

class Server
{
	public:
		Server();
		Server(std::string text);
		~Server();
		Server(const Server &other);
		Server &operator=(const Server &other);

	public:
		std::string	getTextfile();
		void	parse_lines();

	private:
		std::string	textfile;
		// Location	locations[MAX_LOCATIONS];
		
		std::string str_listen;
		std::string str_server_name;
		std::string str_client_max_body_size;
		std::string str_error_page;
};

#endif