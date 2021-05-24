#pragma once

#include <iostream>

struct Date {
    int day = 0, month = 0, year = 0;

    std::string to_string() const;
};

std::istream &operator>>(std::istream &, Date &);
std::ostream &operator<<(std::ostream &, const Date &);
