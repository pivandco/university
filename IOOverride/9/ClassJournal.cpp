#include "ClassJournal.hpp"

#include "binary_io.hpp"

std::istream &operator>>(std::istream &in, ClassJournal &journal) {
    bin_read(in, journal.name);
    bin_read(in, journal.lessons);
    return in;
}

std::ostream &operator<<(std::ostream &out, const ClassJournal &journal) {
    bin_write(out, journal.name);
    bin_write(out, journal.lessons);
    return out;
}
