/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgil <cgil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 16:35:23 by cgil              #+#    #+#             */
/*   Updated: 2026/01/28 16:12:55 by cgil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
    _database = other._database;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
    if (this != &other)
        _database = other._database;
    return *this;
}

void BitcoinExchange::loadDatabase(const std::string &file)
{   
    std::ifstream filename(file.c_str()); // convert to const since ifstream needs it
    if (!filename.is_open())
        throw std::runtime_error("Error: could not open file.");
    if (filename.peek() == std::ifstream::traits_type::eof())
        throw std::runtime_error("Error: empty .csv file");

    std::string line;
    getline(filename, line); // "date | value" -> skip

    while (getline(filename, line))
    {
        std::istringstream ss(line);
        std::string        date;
        std::string        value_str;
        
        if (!getline(ss, date, ',') || !getline(ss, value_str))
        {
            std::cerr << RED << "Error: bad input => " << line << RESET << std::endl;
            continue ;
        }
        date.erase(0, date.find_first_not_of(" \t"));
        date.erase(date.find_last_not_of(" \t") + 1);
        
        value_str.erase(0, value_str.find_first_not_of(" \t"));
        value_str.erase(value_str.find_last_not_of(" \t") + 1);

        try
        {
            std::stringstream ss_val(value_str);
            float value;
            ss_val >> value;

            if (ss_val.fail() || !ss_val.eof())
                throw std::runtime_error("Error: bad value");

            if (value < 0)
            {
                std::cerr << RED << "Error: not a positive number." << RESET << std::endl;
                continue;
            }
            _database[date] = value;
        }
        catch (...)
        {
            std::cerr << RED << "Error: bad value" << RESET << std::endl;
        }
    }
}


bool BitcoinExchange::isValidDate (const std::string &date)
{
    // format = YYYY-MM-DD
    if (date.length() != 10)
        return false;
    // check correct position of '-'
    if (date[4] != '-' || date[7] != '-')
        return false;
    int year = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());
    if (month < 1 || month > 12)
        return false;
    int max_day = 31;
    if (month == 4 || month == 6 || month == 9 || month == 11)
        max_day = 30;
    else if (month == 2)
    {
        if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
            max_day = 29;
        else
            max_day = 28;
    }
    if (day < 1 || day > max_day)
        return false;
    return true;
}

void BitcoinExchange::processInput(const std::string &file)
{
    std::ifstream input(file.c_str());
    if (!input.is_open())
        throw std::runtime_error("Error: could not open file.");
    if (input.peek() == std::ifstream::traits_type::eof())
        throw std::runtime_error("Error: empty file");
    
    std::string line;
    getline(input, line); // skip header

    while (getline(input, line))
    {
        std::string date;
        std::string value_str;
        float value;

        std::size_t sep = line.find('|');
        if (sep == std::string::npos)
        {
            std::cerr << RED << "Error: bad input => " << line << RESET << std::endl;
            continue;
        }

        date = line.substr(0, sep);
        value_str = line.substr(sep + 1);
        date.erase(0, date.find_first_not_of(" \t"));
        date.erase(date.find_last_not_of(" \t") + 1);
        
        value_str.erase(0, value_str.find_first_not_of(" \t"));
        value_str.erase(value_str.find_last_not_of(" \t") + 1);

        if (!isValidDate(date))
        {
            std::cerr << RED << "Error: bad input => " << line << RESET << std::endl;
            continue;
        }
        std::stringstream ss_val(value_str);
        ss_val >> value;
        if (ss_val.fail() || !ss_val.eof())
        {
            std::cerr << RED << "Error: bad input => " << line << RESET << std::endl;
            continue;
        }
        if (value < 0)
        {
            std::cerr << RED << "Error: not a positive number." << RESET << std::endl;
            continue;
        }
        if (value > 1000)
        {
            std::cerr << RED << "Error: too large a number." << RESET << std::endl;
            continue;
        }
        // smallest element within the group of elements greater than or equal to date
        std::map<std::string, double>::iterator it = _database.lower_bound(date);
        if (it == _database.end() || it->first != date)
        {
            if (it == _database.begin())
            {
                std::cerr << RED << "Error: bad input => " << date << RESET << std::endl;
                continue;
            }
            --it;
        }
        float result = value * it->second;
        std::cout << date << " => " << value << " = " << result << std::endl;
    }
}