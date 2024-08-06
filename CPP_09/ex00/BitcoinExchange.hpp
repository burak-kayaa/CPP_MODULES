#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <cstdlib>
#include <stdexcept>

class BitcoinExchange {
    private:
        std::map<std::string, float> btc_data;
        int min_year;
    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &cpy);
        BitcoinExchange &operator = (const BitcoinExchange &cpy);

        void read_data();
        void read_input(std::string input_file_name);
        void check_line_and_print(std::string line);
        void find_date_and_print(std::string date, float value);
        ~BitcoinExchange();
};

#endif