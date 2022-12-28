/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Webserver.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soyoungjung <soyoungjung@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 17:18:15 by ntan              #+#    #+#             */
/*   Updated: 2022/12/28 22:27:12 by soyoungjung      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Webserver.hpp"

Webserver::Webserver(const char *path_to_config) : config(path_to_config)
{
	config.printServers();
	std::cout << "----- [CONFIG OK] -----" << std::endl;
}

int Webserver::start()
{
	SocketInfo test(this->config);

	for (size_t i = 0; i < config.servers_count; i++)
	{
		int fd = -1;
		test.create_socket(&fd);
		test.set_socket_option(&fd);
		test.set_non_blocking(&fd);
		struct sockaddr_in address;
		std::memset((char *)&address, 0, sizeof(address));
		address.sin_family = AF_INET;
		address.sin_addr.s_addr = htonl(INADDR_ANY);
		address.sin_port = htons(atoi(config.servers[i].listen.values[1].c_str()));
		test.bind_socket(&address, &fd);
		test.server_fds.push_back(fd);
		test.init_master_set(&fd);
	}
	for (size_t i = 0; i < config.servers_count; i++)
		test.listen_socket(&test.server_fds[i]);

	test.set_timeout();
	test.server_loop();

	return (0);
}
