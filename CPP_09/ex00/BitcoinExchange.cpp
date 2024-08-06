#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() { }

BitcoinExchange::BitcoinExchange(const BitcoinExchange &cpy) {
    if (this != &cpy) {
        this->btc_data = cpy.btc_data;
        this->min_year = cpy.min_year;
    }
}

BitcoinExchange &BitcoinExchange::operator = (const BitcoinExchange &copy) {
    (void)copy;
    return *this;
}

BitcoinExchange::~BitcoinExchange() { }

int ft_stoi(std::string str) {
    int i = 0;
    int num = 0;
    int isNegative = 0;

    if (str[i] == '-' || str[i] == '+')
        if (str[i++] == '-')
            isNegative = 1;
    while (str[i] >= '0' && str[i] <= '9') {
        num = num * 10 + (str[i++] - '0');
    }
    if (isNegative)
        num *= -1;
    return (num);
}

void BitcoinExchange::read_data() {
    try {
        std::ifstream data_csv("data.csv");

        if (!data_csv.is_open())
            throw std::runtime_error("Data file is not open!");
        std::string each_line_here;
        getline(data_csv, each_line_here);
        while (getline(data_csv, each_line_here)) {
            float value = atof((each_line_here.substr(11)).c_str());
            btc_data[each_line_here.substr(0, 10)] = value;
        }
        data_csv.close();
    } catch (std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    min_year = 2024;
    std::map<std::string, float>::iterator it = btc_data.begin();
    while (it != btc_data.end()) {
        if (min_year > ft_stoi(it->first.substr(0,4)))
			min_year = ft_stoi(it->first.substr(0,4));
        it++;
    }
}

void BitcoinExchange::read_input(std::string input_file_name) {
    try {
        std::ifstream input_file(input_file_name.c_str());

        if (!input_file.is_open())
            throw std::runtime_error("Input file is not open!");
        std::string each_line_here;
        getline(input_file, each_line_here);
        while (getline(input_file, each_line_here)) {
            check_line_and_print(each_line_here);
        }
        input_file.close();
    } catch (std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
}

void BitcoinExchange::check_line_and_print(std::string line) {
    if (line.length() > 11) {
        float value = atof((line.substr(13)).c_str());

        int year = ft_stoi(line.substr(0, 4));
        int month = ft_stoi(line.substr(5, 2));
        int day = ft_stoi(line.substr(8, 10));

        if (((year > 2022) || (year < min_year)) || ((month > 12) || (month < 1)) || ((day > 31) || (day < 1)))
            std::cout << "Error: bad input => " << line.substr(0, 10) << std::endl;
        else if (value < 0)
            std::cout << "Error: not a positive number." << " = "<< value << std::endl;
        else if (value > 1000)
            std::cout << "Error: too large a number." << " = "<< value << std::endl;
        else
            find_date_and_print(line.substr(0, 10), value);
    } else
        std::cout << "Error: bad input => " << line.substr(0, 10) << std::endl;
}

void BitcoinExchange::find_date_and_print(std::string date, float value) {
    std::map<std::string, float>::iterator it = btc_data.begin();
    bool flag;

    while (it != btc_data.end()) {
        if (it->first == date) {
            std::cout << date << " => " << value << " = " << (it->second * value) << std::endl;
            flag = false;
            break;
        }
        it++;
        if (it == btc_data.end())
            flag = true;
    }
    if (flag) {
        it = btc_data.lower_bound(date);
        it--;
        std::cout << date << " => " << value << " = " << (it->second * value) << std::endl;
    }
}