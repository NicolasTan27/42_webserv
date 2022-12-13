/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Response.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan <ntan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 15:49:06 by ntan              #+#    #+#             */
/*   Updated: 2022/12/13 16:36:11 by ntan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Response.hpp"

Response::Response(Config conf) : config(conf),
	version("version", "HTTP/1.1", ""),
	status_code("status_code", "200", ""),
	status_message("status_message", "OK", ""),
	Date("date", "", ""),
	Content_Type("context_type", "", ""),
	Server("server", "42Webserv", "")
{
}