/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Keys.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan <ntan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 14:48:55 by ntan              #+#    #+#             */
/*   Updated: 2022/12/09 14:52:59 by ntan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Keys.hpp"

Keys::Keys() {}

Keys::Keys(std::string _name, std::string _value, std::string _delimiter)
{
	this->name = _name;
	this->delimiter = _delimiter;
	setValue(_value);
}

Keys::~Keys() {}

std::string	&Keys::operator[](size_t n)
{
	return (this->values[n]);
}

/////////////////////////

void	Keys::setValue(std::string newValue)
{
	this->values.clear();

	size_t delim_pos = 0;
	if (this->delimiter != "")
	{
		while (delim_pos != std::string::npos)
		{
			delim_pos = newValue.find(this->delimiter);
			if (delim_pos == 0)
				break;
			addValue(newValue.substr(0, delim_pos));
			newValue = newValue.substr(delim_pos + 1);
		}
	}
	else
	{
		addValue(newValue);
	}
}

void	Keys::addValue(std::string newValue)
{
	this->values.push_back(newValue);
}

///// DEBUG FUNCTIONS /////

std::string	concat_vector_str(std::vector<std::string> &vec_list)
{
	typedef std::vector<std::string>::iterator	iterator;
	std::string res;
	size_t i = 0;
	for (iterator beg = vec_list.begin(); beg != vec_list.end(); ++beg, i++)
	{
		res +=  "[" + *beg + "] ";
	}
	return (res);
}

void		Keys::print()
{
	std::cout << this->name << " : " << concat_vector_str(this->values) << std::endl;
}