/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Location.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan <ntan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 17:15:49 by ntan              #+#    #+#             */
/*   Updated: 2022/12/08 18:19:46 by ntan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOCATION_HPP
# define LOCATION_HPP

# include "Keys.hpp"
# include <string>
# include <iostream>

class Location {

	public:
		Location();

		void	print_location();
	
		// **ADD KEYS HERE
		Keys	path;
		Keys	allowed_methods;
		Keys	rewrite;
		Keys	root;
		Keys	autoindex;
		Keys	cgi;
		Keys	default_dir_request;
		Keys	upload_dir;	
};

#endif