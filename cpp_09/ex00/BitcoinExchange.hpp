/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 09:30:26 by caalbert          #+#    #+#             */
/*   Updated: 2024/03/28 18:57:11 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <map>

# define DATA_FILE	"data.csv"

# define RESET		"\e[m"
# define RED		"\e[31m"
# define GREEN		"\e[32m"
# define YELLOW		"\e[33m"

enum file_type {
    DATABASE,
    INPUT
};

class BitcoinExchange {
private:

    BitcoinExchange(BitcoinExchange const &src);
    BitcoinExchange &operator=(BitcoinExchange const &src);

    std::map<std::string, float> _database; //aqui
    std::string _min_date;
    std::string _max_date;

    void _loadDatabase(void);
    void _btc(std::string date, float value);
    bool _checkHeader(std::string line, file_type type);
    void _checkLine(std::string line, file_type type);
    bool _checkDate(std::string date, file_type type);
    bool _checkValue(std::string value, file_type type);
    void _trimCell(std::string &cell);

public:

    BitcoinExchange(void);
    ~BitcoinExchange(void);

    void show_conversions(std::string filename);

    class DatabaseLoadException : public std::exception {
        public:
            DatabaseLoadException(std::string error_message);
            virtual ~DatabaseLoadException(void) throw() {};
            virtual const char *what() const throw();
        private:
            std::string _error_message;
    };
    class DatabaseNotFoundException : public std::exception {
        virtual const char *what() const throw();
    };
    class BadDatabaseFormatException : public std::exception {
        virtual const char *what() const throw();
    };
    class BadDatabaseDataException : public std::exception {
        virtual const char *what() const throw();
    };
    class InputNotFoundException : public std::exception {
        virtual const char *what() const throw();
    };
    class BadInputFormatException : public std::exception {
        virtual const char *what() const throw();
    };
    class BadInputDataException : public std::exception {
        public:
            BadInputDataException(std::string line);
            virtual ~BadInputDataException(void) throw() {};
            virtual const char *what() const throw();
        private:
            std::string _error_message;
    };
    class BadDateException : public std::exception {
        public:
            BadDateException(std::string date);
            virtual ~BadDateException(void) throw() {};
            virtual const char *what() const throw();
        private:
            std::string _error_message;
    };
    class NegativeValueException : public std::exception {
        virtual const char *what() const throw();
    };
    class TooLargeValueException : public std::exception {
        virtual const char *what() const throw();
    };
};

#endif