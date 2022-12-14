/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Response.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan <ntan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 15:49:15 by ntan              #+#    #+#             */
/*   Updated: 2022/12/14 16:44:16 by ntan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RESPONSE_HPP
# define RESPONSE_HPP

# include "Context.hpp"
# include "Status.hpp"

class Response {
	public:
		Response(Context cont);
		
	private:
		Status		status;
		Context		context;
		std::string	response;

	// Elements of the response
	public:
		Keys	version_code_message;
		Keys	server;
		Keys	content_length;
		Keys	content_type;
		Keys	body;

	private:
		void	make_response();

	public:
		void	print_response();
		const char	*get_response();
		
};

#endif