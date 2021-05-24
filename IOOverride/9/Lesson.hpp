#pragma once

#include <string>
#include <map>
#include <iostream>

#include "Date.hpp"

struct Lesson {
    std::string topic;
    Date date;
    std::map<std::string, int> marks;
};

std::istream &operator>>(std::istream &, Lesson &);
std::ostream &operator<<(std::ostream &, const Lesson &);
