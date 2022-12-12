/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Context.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan <ntan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 23:43:07 by ntan              #+#    #+#             */
/*   Updated: 2022/12/12 17:58:14 by ntan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTEXT_HPP
# define CONTEXT_HPP

# include "../config/Config.hpp"
# include "../client/Request.hpp"

# include <string>
# include <iostream>

class Context {
	public:
		Context(Config conf, Request req);

	// private:
		Config	config;
		Request	request;
		void	print_context();

	private:
		void	find_server();
		void	find_location();
	
	public:
		std::vector<Server>	servers;
};

#endif