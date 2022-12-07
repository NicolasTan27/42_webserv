/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Location.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan <ntan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 17:15:49 by ntan              #+#    #+#             */
/*   Updated: 2022/12/07 19:19:15 by ntan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOCATION_HPP
# define LOCATION_HPP

class Location {

	public:
		Location();
	
		Keys	path;
		Keys	allowed_methods;
		Keys	rewrite;
		Keys	root;
		Keys	cgi;
		Keys	autoindex;
};

#endif