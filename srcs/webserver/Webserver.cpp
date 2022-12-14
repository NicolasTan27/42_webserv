/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Webserver.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan <ntan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 17:18:15 by ntan              #+#    #+#             */
/*   Updated: 2022/12/14 16:51:16 by ntan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Webserver.hpp"

Webserver::Webserver(const char *path_to_config) : config(path_to_config)
{
	
}

int	Webserver::start()
{
	int server_fd = socket(AF_INET, SOCK_STREAM, 0);
	if (server_fd < 0)
	{
		std::cerr << "Could not create socket" << std::endl;
		return (1);
	}

	struct sockaddr_in address;
	std::memset((char *) &address, 0, sizeof(address));
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = htonl(INADDR_ANY);
	address.sin_port = htons(PORT);

	if (bind(server_fd, (struct sockaddr *) &address, sizeof(address)) < 0)
	{
		std::cerr << "Bind failed" << std::endl;
		return (1);
	}

	if (listen(server_fd, 3) < 0)
	{
		std::cerr << "In listen" << std::endl;
		return (1);
	}

	struct pollfd fds[1024];
	fds[0].fd = server_fd;
	fds[0].events = POLLIN;
	int nfds = 1;
	int addrlen = sizeof(address);
	while (1)
	{
		std::cout << "====== WAITING FOR NEW CONNECTION =====" << std::endl;
		int poll_ret = poll(fds, nfds, -1);
		if (poll_ret < 0)
		{
			std::cerr << "Poll error" << std::endl;
			return (1);
		}
		if (poll_ret == 0)
		{
			std::cerr << "Poll timeout" << std::endl;
			return (1);
		}
		for (int i = 0; i < nfds; i++)
		{
			if (fds[i].revents == 0)
				continue;
			if (fds[i].revents != POLLIN)
			{
				std::cerr << "Error in poll" << std::endl;
				return (1);
			}
			if (i == 0)
			{
				int new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen);
				if (new_socket < 0)
				{
					std::cerr << "In accept" << std::endl;
					return (1);
				}
				fds[nfds].fd = new_socket;
				fds[nfds].events = POLLIN;
				nfds++;
			}
			else
			{
				char buffer[30000];
				int rd = read(fds[i].fd, buffer, 30000);
				if (rd < 0)
				{
					std::cerr << "Read error" << std::endl;
					return (1);
				}
				std::string str_buf(buffer, rd);
				std::cout << str_buf << std::endl;
				// char message[] = "HTTP/1.1 200 OK\nContent-Type: text/plain\nContent-Length: 12\n\nHello world!";
								
				Request		request(str_buf);
				request.print_request();
				
				Context		context(config, request);
				context.print_context();
				
				Response	response(context);
				response.print_response();
				
				const char *message = response.get_response();
				write(fds[i].fd, message, strlen(message));
				
				std::cout << "===== RESPONSE SENT =====" << std::endl;
				close(fds[i].fd);
				fds[i].fd = -1;
			}
		}
	}
	close(server_fd);
	return (1);
}
