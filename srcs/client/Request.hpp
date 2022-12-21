/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Request.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan <ntan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 13:58:39 by ntan              #+#    #+#             */
/*   Updated: 2022/12/21 18:34:00 by ntan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REQUEST_HPP
# define REQUEST_HPP

# include <algorithm>

# include "../config/Keys.hpp"

class Request {

	public:
		Request();
		Request(std::string request);
	
	public:	
		void	print_request();
		void	parse_request();
		void	parse_request_forest(std::string name, std::string value);

	public:
		std::string request; // raw content

	public:
		Keys	method; 	// method for this request
		Keys	path; 		// path for this request
		Keys	version; 	// protocol/version for this request
		Keys	host;		// ip and port for virtual server
		Keys	body;		// content sended with the request, commonly used with POST
		Keys	user_agent; 
};

#endif