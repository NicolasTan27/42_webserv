/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Keys.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan <ntan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 14:48:55 by ntan              #+#    #+#             */
/*   Updated: 2022/12/06 19:43:08 by ntan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Keys.hpp"

Keys::Keys() {}

Keys::Keys(std::string _name, std::string _value, std::string _delimiter, bool _mandatory, bool _multi_args)
{
	this->name = _name;
	// this->values[0] = _value;
	setValue(_value);
	this->delimiter = _delimiter;
	this->mandatory = _mandatory;
	this->multi_args = _multi_args;
}

Keys	&Keys::operator=(const Keys &other)
{
	this->name = other.name;
	this->values = other.values;
	this->delimiter = other.delimiter;
	this->mandatory = other.mandatory;
	this->multi_args = other.multi_args;
	return (*this);
}

Keys::~Keys() {}

void	Keys::setValue(std::string newValue)
{
	this->values.clear();
	if (this->delimiter != "")
	{
		size_t pos = 0;
		while (pos != std::string::npos)
		{
			this->values.push_back(newValue.substr(pos, newValue.find(this->delimiter, pos)));
			pos = newValue.find(this->delimiter, pos + 1);
		}
	}
	else
	{
		this->values.push_back(newValue);
	}
}

///// DEBUG FUNCTIONS /////

std::string	concat_vector_str(std::vector<std::string> &vec_list)
{
	typedef std::vector<std::string>::iterator	iterator;
	std::string res;
	for (iterator beg = vec_list.begin(); beg != vec_list.end(); ++beg)
	{
		if (beg != vec_list.begin())
			res += ", ";
		res += *beg;
	}
	return (res);
}

void		Keys::print()
{
	std::cout << this->name << " : [" << concat_vector_str(this->values) << "]" << std::endl;
}