#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "Lesson.hpp"

struct ClassJournal {
    std::string name;
    std::vector<Lesson> lessons;

    std::string to_string() const;
};

std::istream &operator>>(std::istream &, ClassJournal &);
std::ostream &operator<<(std::ostream &, const ClassJournal &);
