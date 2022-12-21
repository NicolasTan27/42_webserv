/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CgiHandler.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsung <rsung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 15:42:34 by rsung             #+#    #+#             */
/*   Updated: 2022/12/21 18:33:08 by rsung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CGIHANDLER_HPP
# define CGIHANDLER_HPP

#define CGI_SIZE 50000
#include <iostream>
#include "../../response/Context.hpp"

class CgiHandler.hpp
{
	public:
		CgiHandler(Context &context) // sets up env according to the request
		CgiHandler(CgiHandler const &other);
		virtual ~CgiHandler(void);
		CgiHandler &operator=(CgiHandler const &other);
		std::string	executeCGI(const std::string &scriptName);	// executes cgi and returns body

	private:
		CgiHandler(void);
		void										_initEnv();
		char										**getEnv(void) const;
		std::string									_body; // passer le vector en string
		std::map<std::string, std::string>			_env;
};

#endif
