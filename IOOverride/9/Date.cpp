#include "Date.hpp"

#include <stdexcept>
#include <iomanip>
#include <sstream>
#include <regex>

#include "binary_io.hpp"

using std::string, std::stoi;
using std::stringstream;
using std::setfill, std::setw;
using std::regex, std::smatch, std::regex_match;
using std::logic_error;

Date Date::from_string(const string &date_string) {
    const regex DATE_REGEX("(\\d{1,2})\\.(\\d{1,2})\\.(\\d{4})");
    smatch match;
    if (!regex_match(date_string, match, DATE_REGEX)) {
        throw logic_error(date_string);
    }
    return Date { stoi(match[1]), stoi(match[2]), stoi(match[3]) };
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
