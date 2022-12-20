/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan <ntan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 14:57:05 by ntan              #+#    #+#             */
/*   Updated: 2022/12/20 19:01:31 by ntan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "config/Config.hpp"
# include "client/Request.hpp"
# include "webserver/Webserver.hpp"

#include <unistd.h>
#include <cstring>
#include <iostream>
#include <sys/socket.h>
#include "netinet/in.h"
#include <poll.h>
#include <sys/epoll.h>

// #define PORT 8000

int main()
{
	char	path[] = "./config_files/default.conf";
	try
	{
		Webserver webserver(path);
		webserver.start();			
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return (1);
	}
	return (0);
}
