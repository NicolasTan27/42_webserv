/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Webserver.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan <ntan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 17:18:18 by ntan              #+#    #+#             */
/*   Updated: 2022/12/09 17:30:13 by ntan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEBSERVER_HPP
# define WEBSERVER_HPP

#include <unistd.h>
#include <cstring>
#include <iostream>
#include <sys/socket.h>
#include "netinet/in.h"
#include <poll.h>
#include <sys/epoll.h>

# include "../config/Config.hpp"
# include "../client/Request.hpp"

#define PORT 8000

class Webserver {
	
	public:
		Webserver(const char* path_to_config);

	public:
		void	start();

	private:
		Config	config;
};

#endif