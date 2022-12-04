/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Config.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan <ntan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 16:41:15 by ntan              #+#    #+#             */
/*   Updated: 2022/12/04 19:12:31 by ntan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_HPP
# define CONFIG_HPP

# include "Server.hpp"
# include <iostream>
# include <fstream>
# include <string>
# include <cstdlib>

class Config
{
	public:
		Config(char const *path);
		Config();
		~Config();
		Config(const Config &other);
		Config &operator=(const Config &other);
		
		std::string		getConfig();

	private:
		std::string		textfile;
		Server			servers;

	private:
		void	read_config_file(char const *path);
		void	parse_server_blocks();

		class	ConfigErrorException : public std::runtime_error
		{
			// private:
			// 	std::string	message;

			public:
				ConfigErrorException(const char *what) : runtime_error(what) {}
				// message("CONFIG ERROR: " + msg)
				// {}
				// virtual const char* what() const throw () 
				// {
				// 	return (message.c_str());
				// }
		};
};

#endif