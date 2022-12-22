/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   UserData.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojung <sojung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 18:32:55 by sojung            #+#    #+#             */
/*   Updated: 2022/12/21 19:09:55 by sojung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "UserData.hpp"

UserData::UserData() : user_data(std::map<std::string, std::string>()) {}

UserData::~UserData() {}

UserData::UserData(const UserData &rhs) : user_data(rhs.user_data) {}

UserData &UserData::operator=(const UserData &rhs) {
    this->user_data = rhs.user_data;
    return (*this);
}

std::pair<std::string, std::string> UserData::decomposer(std::string &request) {

    std::string name;
    std::string color;

    size_t  delim_pos = 0;
    size_t  tmp = 0;
    // request ex : username=ddd&favcolor=%23b88989
    delim_pos = request.find('&');
    // username part
    if (!request.substr(0, delim_pos).empty())
    {        
        name = request.substr(0, delim_pos);
        tmp = name.find('=');
        if (!name.substr(tmp).empty())
            name = name.substr(tmp);
    }
    // color part
    if (!request.substr(delim_pos).empty())
    {        
        color = request.substr(delim_pos);
        tmp = color.find('=');
        if (!color.substr(tmp).empty())
            color = color.substr(tmp);
    }
    return (std::pair<std::string, std::string>(name, color));
}

void UserData::addUser(std::string &request) {
    std::pair<std::string, std::string> elem;
    elem = decomposer(request);
    std::map<std::string, std::string>::iterator    it;
    it = this->user_data.find(elem.first);
    if (it != this->user_data.end())
        this->user_data.erase(it);
    this->user_data.insert(elem);
}

void UserData::deleteUser(std::string &request) {
    std::pair<std::string, std::string> elem;
    elem = decomposer(request);
    std::map<std::string, std::string>::iterator    it;
    it = this->user_data.find(elem.first);
    if (it != this->user_data.end())
        this->user_data.erase(it);
}