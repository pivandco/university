#include "Date.hpp"

#include <iomanip>
#include <sstream>
#include <regex>

#include "binary_io.hpp"

using std::string;
using std::stringstream;
using std::setfill, std::setw;
using std::regex;

const regex DATE_REGEX("\\d{1,2}\\.\\d{1,2}\\.\\d{4}");

Date Date::from_string() {
    // TODO
}

string Date::to_string() const {
    stringstream ss;
    ss << setfill('0')
        << setw(2) << day
        << '.' << setw(2) << month
        << '.' << year;
    return ss.str();
}

std::istream &operator>>(std::istream &in, Date &date) {
    bin_read(in, date);
    return in;
}

std::ostream &operator<<(std::ostream &out, const Date &date) {
    bin_write(out, date);
    return out;
}
