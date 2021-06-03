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
    ss << "Занятие " << date.to_string() << ": " << topic << ", оценок: " << marks.size() << endl;
    return ss.str();
}

string Lesson::to_string_with_marks() const {
    stringstream ss;
    ss << to_string_brief() << endl << BAR << "\nОценки:";
    if (marks.empty()) {
        ss << "\nПусто";
    }
    for (auto &[student, mark] : marks) {
        ss << endl << student << " : " << mark;
    }
    return ss.str();
}

istream &operator>>(istream &in, Lesson &lesson) {
    bin_read(in, lesson.topic);
    in >> lesson.date;
    bin_read_map<string, int>(in, lesson.marks, [] (istream &in, string &student, int &mark) {
        bin_read(in, student);
        bin_read(in, mark);
    });
    return in;
}

ostream &operator<<(ostream &out, const Lesson &lesson) {
    bin_write(out, lesson.topic);
    out << lesson.date;
    bin_write_map<string, int>(out, lesson.marks, [] (ostream &out, const string &student, const int &mark) {
        bin_write(out, student);
        bin_write(out, mark);
    });
    return out;
}
