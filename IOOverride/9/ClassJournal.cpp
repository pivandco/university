#include "ClassJournal.hpp"

#include <sstream>

#include "binary_io.hpp"
#include "printing.hpp"

using std::istream, std::ostream;
using std::string;
using std::stringstream;
using std::endl;

string ClassJournal::to_string() const {
    stringstream ss;
    ss << "Журнал \"" << name << "\"\n"
       << BAR << endl;
    for (size_t i = 0; i < lessons.size(); i++) {
        ss << "№" << i + 1 << ": " << lessons[i].to_string_brief();
    }
    ss << BAR << endl;
    return ss.str();
}

istream &operator>>(istream &in, ClassJournal &journal) {
    bin_read(in, journal.name);
    bin_read_vector<Lesson>(in, journal.lessons, [] (istream &in, Lesson &lesson) {
        in >> lesson;
    });
    return in;
}

ostream &operator<<(ostream &out, const ClassJournal &journal) {
    bin_write(out, journal.name);
    bin_write_vector<Lesson>(out, journal.lessons, [] (ostream &out, const Lesson &lesson) {
        out << lesson;
    });
    return out;
}
