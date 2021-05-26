#include "Lesson.hpp"

#include <sstream>

#include "binary_io.hpp"
#include "printing.hpp"

using std::istream, std::ostream;
using std::string;
using std::stringstream;
using std::endl;

string Lesson::to_string_brief() const {
    stringstream ss;
    ss << "Занятие " << date.to_string() << ": " << topic << endl;
    return ss.str();
}

string Lesson::to_string_with_marks() const {
    stringstream ss;
    ss << to_string_brief() << endl << BAR << "\nОценки:\n";
    for (auto &[student, mark] : marks) {
        ss << student << " : " << mark << endl;
    }
    return ss.str();
}

istream &operator>>(istream &in, Lesson &lesson) {
    bin_read(in, lesson.topic);
    in >> lesson.date;
    bin_read(in, lesson.marks);
    return in;
}

ostream &operator<<(ostream &out, const Lesson &lesson) {
    bin_write(out, lesson.topic);
    out << lesson.date;
    bin_write(out, lesson.marks);
    return out;
}
