/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Config.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan <ntan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 16:41:15 by ntan              #+#    #+#             */
/*   Updated: 2022/12/02 16:47:28 by ntan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_HPP
# define CONFIG_HPP

# include "Server.hpp"

class Config
{
	public:
		Config();
		~Config();
		Config(const Config &other);
		Config &operator=(const Config &other);

	private:
		Server	servers;
};

#endif