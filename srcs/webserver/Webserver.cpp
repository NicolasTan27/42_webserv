/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Webserver.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojung <sojung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 17:18:15 by ntan              #+#    #+#             */
/*   Updated: 2022/12/29 14:18:40 by sojung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Webserver.hpp"
#define GREEN "\033[1;32m"
#define NOR "\033[0m"

Webserver::Webserver(const char *path_to_config) : config(path_to_config)
{
	config.printServers();
	std::cout << "----- [CONFIG OK] -----" << std::endl;
}

int Webserver::start()
{
	SocketInfo test(this->config);

	std::vector<int> ports;
	int port;

	for (size_t i = 0; i < config.servers_count; i++)
	{
		port = atoi(config.servers[i].listen.values[1].c_str());
		std::cout << GREEN << "PORT NUM : " << port << NOR << std::endl;  
		if (std::find(ports.begin(), ports.end(), port) == ports.end())
		{
			ports.push_back(port);
			std::cout << "push backed port : " << port << std::endl;
		}
	}
	test.socket_master(ports);
	test.listen_socket();
	test.set_timeout();
	test.server_loop();

	return (0);
}
