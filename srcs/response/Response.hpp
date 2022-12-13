/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Response.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan <ntan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 15:49:15 by ntan              #+#    #+#             */
/*   Updated: 2022/12/13 16:53:38 by ntan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RESPONSE_HPP
# define RESPONSE_HPP

# include "Context.hpp"

class Response {
	public:
		Response(Config conf);
		
	private:
		Config		config;
		std::string	response;

	// Elements of the response
	public:
		Keys	version;
		Keys	status_code;
		Keys	status_message;
		Keys	Date;
		Keys	Content_Type;
		Keys	Server;
		Keys	body;

	private:
		void	make_response();

	public:
		char	*get_response();
		
};

#endif