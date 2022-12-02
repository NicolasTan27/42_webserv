/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan <ntan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 16:47:35 by ntan              #+#    #+#             */
/*   Updated: 2022/12/02 16:48:56 by ntan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_HPP
# define SERVER_HPP

# include "Server.hpp"

class Server
{
	public:
		Server();
		~Server();
		Server(const Server &other);
		Server &operator=(const Server &other);

	private:
		std::string
};

#endif