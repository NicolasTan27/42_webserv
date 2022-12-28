/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SocketInfo.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soyoungjung <soyoungjung@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 17:13:35 by rsung             #+#    #+#             */
/*   Updated: 2022/12/28 22:26:54 by soyoungjung      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOCKETINFO_HPP
#define SOCKETINFO_HPP

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/select.h>
#include <sys/time.h>
#include <iostream>
#include <cstring>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <vector>

#include "../config/Config.hpp"
#include "../client/Request.hpp"
#include "../response/Response.hpp"

#define PORT 8000
#define MAX_BACKLOG 64
#define TRUE 1
#define FALSE 0

class SocketInfo
{
private:
	// int						ports[2];

	int on, max_fd, end_server, len;
	struct sockaddr_in address;
	fd_set master_set, working_set;
	struct timeval timeout;
	char buffer[50000];
	// std::string				buffer;
	Config config;

public:
	std::vector<int> server_fds;
	SocketInfo(Config config);
	~SocketInfo() {}
	SocketInfo(const SocketInfo &other);
	SocketInfo &operator=(const SocketInfo &other);
	struct sockaddr_in set_sockaddr(struct sockaddr_in &address, int ip, int port);
	void add_socket(int ip, int port);
	int create_socket(int *fd);
	int set_socket_option(int *fd);
	int set_non_blocking(int *fd);
	int bind_socket(struct sockaddr_in *address, int *fd);
	int listen_socket(int *fd);
	void init_master_set(int *fd);
	void server_loop(void);
	void set_timeout(void);
};
#endif
