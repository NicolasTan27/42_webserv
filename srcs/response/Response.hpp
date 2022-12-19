/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Response.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan <ntan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 15:49:15 by ntan              #+#    #+#             */
/*   Updated: 2022/12/19 19:44:00 by ntan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RESPONSE_HPP
# define RESPONSE_HPP

# include "Context.hpp"
# include "Status.hpp"

# include <algorithm>
# include <fstream>
# include <cstdlib>
# include <sstream>
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>

class Response {
	public:
		Response(Context cont);
		
	private:
		Status		status;
		Context		context;
		std::string	response;

	// Elements of the response
	public:
		Keys	version_code_message; 				// [0] = version, [1] = status_code, [2] = status_msg 
		Keys	server;
		Keys	content_length;
		Keys	content_type;
		Keys	body;

	private:
		void	check_response();
		void	set_status(std::string code);
		int		check_allowed_methods();
		int		check_version();
		int		check_max_body_size();
		int		check_file();    
		
		void		make_body();						// generate the body according to the status
		std::string	read_html(std::string path);
		// std::string	read_png(std::string path);
		
		void	make_response();					// assemble response in http format

	public:
		void	print_response();
		const char	*get_response();
		
};

#endif