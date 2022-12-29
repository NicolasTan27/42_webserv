/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Webserver.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojung <sojung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 17:18:18 by ntan              #+#    #+#             */
/*   Updated: 2022/12/29 11:04:16 by sojung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEBSERVER_HPP
# define WEBSERVER_HPP

#include <unistd.h>
#include <cstring>
#include <iostream>
#include <sys/socket.h>
#include <arpa/inet.h>
#include "netinet/in.h"
#include <poll.h>
#include <sys/epoll.h>
#include <cstring>
#include <algorithm>

# include "../config/Config.hpp"
# include "../client/Request.hpp"
# include "../response/Response.hpp"
# include "SocketInfo.hpp"

// #define PORT 8000

class Webserver {
	
	public:
		Webserver(const char* path_to_config);

	public:
		int		start();

	public:
		Config	config;
};

#endif
