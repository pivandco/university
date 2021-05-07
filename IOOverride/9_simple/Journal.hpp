#pragma once

#include <iostream>

struct Date {
    int day, month, year;
};

struct Mark {
    char *student = nullptr;
    int mark;

    ~Mark() {
        free(student);
    }
};

struct Lesson {
    char *topic = nullptr;
    Date date;
    size_t n_marks;
    Mark *marks = nullptr;

    ~Lesson() {
        free(topic);
        free(marks);
    }
};

struct ClassJournal {
    size_t n_lessons;
    Lesson *lessons;

    ~ClassJournal() {
        free(lessons);
    }
};

std::istream &operator>>(std::istream &in, ClassJournal &journal);
std::ostream &operator<<(std::ostream &out, const ClassJournal &journal);
