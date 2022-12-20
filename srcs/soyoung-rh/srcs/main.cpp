/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsung <rsung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 14:14:41 by rsung             #+#    #+#             */
/*   Updated: 2022/12/20 15:08:39 by rsung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/SocketInfo.hpp"

int main(void)
{
	SocketInfo	test;

	test.create_socket();
	test.set_socket_option();
	test.set_non_blocking();
	test.bind_socket();
	test.listen_socket();
	test.init_master_set();
	test.set_timeout();
	test.server_loop();
	return (0);
}
