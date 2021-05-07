#include "Journal.hpp"

#include <cstring>

template<typename T>
void read(std::istream &in, T &value) {
    in.read(reinterpret_cast<char *>(&value), sizeof(T));
}

void readstr(std::istream &in, char *&value) {
    size_t len;
    read(in, len);
    value = (char *)malloc(len);
    in.read(value, len);
}

std::istream &operator>>(std::istream &in, ClassJournal &journal) {
    read(in, journal.n_lessons);
    journal.lessons = (Lesson *)calloc(journal.n_lessons, sizeof(Lesson));
    for (size_t i = 0; i < journal.n_lessons; i++) {
        Lesson &lesson = journal.lessons[i];
        readstr(in, lesson.topic);
        read(in, lesson.date);
        read(in, lesson.n_marks);
        lesson.marks = (Mark *)calloc(lesson.n_marks, sizeof(Mark));
        for (size_t j = 0; j < lesson.n_marks; j++) {
            Mark &mark = lesson.marks[j];
            readstr(in, mark.student);
            read(in, mark.mark);
        }
    }
    return in;
}

template<typename T>
void write(std::ostream &out, const T &value) {
    out.write(reinterpret_cast<const char *>(&value), sizeof(T));
}

void writestr(std::ostream &out, const char *value) {
    size_t len = strlen(value);
    write(out, len);
    out.write(value, len);
}

std::ostream &operator<<(std::ostream &out, const ClassJournal &journal) {
    write(out, journal.n_lessons);
    for (size_t i = 0; i < journal.n_lessons; i++) {
        Lesson &lesson = journal.lessons[i];
        writestr(out, lesson.topic);
        write(out, lesson.date);
        write(out, lesson.n_marks);
        for (size_t j = 0; j < lesson.n_marks; j++) {
            Mark &mark = lesson.marks[j];
            writestr(out, mark.student);
            write(out, mark.mark);
        }
    }
    return out;
}

