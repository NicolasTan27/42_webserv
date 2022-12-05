/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan <ntan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 14:57:05 by ntan              #+#    #+#             */
/*   Updated: 2022/12/05 17:06:51 by ntan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <cstring>
#include <iostream>
#include <sys/socket.h>
#include "netinet/in.h"
#include <poll.h>

#define PORT 8080

int main()
{
	// creates a socket. it allows a socket to be used to connect this program
	// to networks.
	int server_fd = socket(AF_INET, SOCK_STREAM, 0);
	if (server_fd < 0)
	{
		std::cerr << "Could not create socket" << std::endl;
		return (1);
	}
		
	/*the structure sockaddr is a generic container that just allows the OS to
	be able to read the first couple of bytes that identify the address family. 
	The address family determines what variant of the sockaddr struct to use
	that contains elements that make sense for that specific communication type.
	For IP networking, we use struct sockaddr_in, which is defined in the header
	netinet/in.h. This structure defines:

	struct sockaddr_in 
	{ 
		__uint8_t         sin_len; 
		sa_family_t       sin_family; 
		in_port_t         sin_port; 
		struct in_addr    sin_addr; 
		char              sin_zero[8]; 
	};*/
	struct sockaddr_in address;
	std::memset((char *) &address, 0, sizeof(address));
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = htonl(INADDR_ANY);
	address.sin_port = htons(PORT);


	/*When we talk about naming a socket, we are talking about assigning a
	transport address to the socket (a port number in IP networking). 
	In sockets, this operation is called binding an address and the bind 
	system call is used for this.*/
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
	
	int addrlen = sizeof(address);
	while (1)
	{
		std::cout << "====== WAITING FOR NEW CONNECTION =====" << std::endl;
		int new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen);
		if (new_socket < 0)
		{
			std::cerr << "In accept" << std::endl;
			return (1);
		}
		char buffer[30000];
		int rd = read(new_socket, buffer, 30000);
		if (rd < 0)
		{
			std::cerr << "Read error" << std::endl;
			return (1);
		}
		std::cout << buffer << std::endl;
		char response[] = "HTTP/1.1 200 OK\nContent-Type: text/plain\nContent-Length: 12\n\nHello world!";
		write(new_socket, response, sizeof(response));
		std::cout << "===== RESPONSE SENT =====" << std::endl;
		close(new_socket);
	}
	return (0);
}