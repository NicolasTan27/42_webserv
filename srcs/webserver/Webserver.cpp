/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Webserver.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan <ntan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 17:18:15 by ntan              #+#    #+#             */
/*   Updated: 2022/12/28 16:23:14 by ntan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Webserver.hpp"

Webserver::Webserver(const char *path_to_config) : config(path_to_config)
{
	config.printServers();
	std::cout << "----- [CONFIG OK] -----" << std::endl;
}

int	Webserver::start()
{
	SocketInfo	test(this->config);
	
	int port[2];
	port[0] = 8000;
	port[1] = 8002;
	// for (int i = 0; i < 2; i++)
		test.add_socket(INADDR_ANY, port[0]);
	
	// test.init_master_set();
	test.set_timeout();
	test.server_loop();

	return (0);
}
