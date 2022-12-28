/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SocketInfo.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojung <sojung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 17:13:35 by rsung             #+#    #+#             */
/*   Updated: 2022/12/28 13:53:32 by sojung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOCKETINFO_HPP
# define SOCKETINFO_HPP

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

# include "../config/Config.hpp"
# include "../client/Request.hpp"
# include "../response/Response.hpp"

#define PORT 8000
#define MAX_BACKLOG	64
#define TRUE 1
#define FALSE 0

class	SocketInfo
{
	private:

		int						server_fd, on, max_fd, end_server, len;
		struct sockaddr_in		address;
		fd_set					master_set, working_set;
		struct timeval			timeout;
		std::string				buffer;
		Config					config;

	public:

		SocketInfo(Config config);
		~SocketInfo(){}
		SocketInfo(const SocketInfo &other);
		SocketInfo &operator=(const SocketInfo &other);
		int		create_socket(void);
		int		set_socket_option(void);
		int		set_non_blocking(void);
		int		bind_socket(void);
		int		listen_socket(void);
		void	init_master_set(void);
		void	server_loop(void);
		void	set_timeout(void);
		
};
#endif
