#include "Lesson.hpp"

#include "binary_io.hpp"

std::istream &operator>>(std::istream &in, Lesson &lesson) {
    bin_read(in, lesson.topic);
    in >> lesson.date;
    bin_read(in, lesson.marks);
    return in;
}

std::ostream &operator<<(std::ostream &out, const Lesson &lesson) {
    bin_write(out, lesson.topic);
    out << lesson.date;
    bin_write(out, lesson.marks);
    return out;
}
