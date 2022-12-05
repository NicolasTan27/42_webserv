/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan <ntan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 16:47:35 by ntan              #+#    #+#             */
/*   Updated: 2022/12/05 16:48:22 by ntan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Server.hpp"

Server::Server(): textfile("") {}

Server::~Server() {}

Server::Server(std::string text) : textfile(text) {}

Server &Server::operator=(const Server &other)
{
	this->textfile = other.textfile;
	return (*this);
}

std::string	Server::getTextfile()
{
	return (this->textfile);
}