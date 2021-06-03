#pragma once

#include <string>
#include <map>
#include <iostream>

#include "Date.hpp"

struct Lesson {
    std::string topic;
    Date date;
    std::map<std::string, int> marks;

    std::string to_string_brief() const;
    std::string to_string_with_marks() const;
};

std::istream &operator>>(std::istream &, Lesson &);
std::ostream &operator<<(std::ostream &, const Lesson &);
