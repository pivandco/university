#pragma once

#include <iostream>
#include <stdexcept>

struct Date {
    int day = 0, month = 0, year = 0;

    static Date from_string(const std::string &);

    std::string to_string() const;
};

std::istream &operator>>(std::istream &, Date &);
std::ostream &operator<<(std::ostream &, const Date &);

class BadDateException : public std::invalid_argument {
public:
    BadDateException(const std::string &what) : std::invalid_argument(what) {
    }
};
