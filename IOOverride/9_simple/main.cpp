#include <fstream>

#include <gtest/gtest.h>
#include "Journal.hpp"

char *dup(const char *s) {
    char *new_s = (char *)malloc(strlen(s) + 1);
    strcpy(new_s, s);
    return new_s;
}

TEST(ClassJournal, IO) {
    Mark *marks = (Mark *)calloc(2, sizeof(Mark));
    marks[0].student = dup("Student1");
    marks[0].mark = 5;
    marks[1].student = dup("Student2");
    marks[1].mark = 2;

    Lesson *lessons = (Lesson *)calloc(1, sizeof(Lesson));
    lessons[0] = { dup("Topic"), {25, 4, 2021}, 2, marks };

    ClassJournal journal_out { 1, lessons };

    const auto FILENAME = "out.tmp";
    std::ofstream out;
    out.open(FILENAME, std::ios::out);
    out << journal_out;
    out.close();

    std::ifstream in;
    in.open(FILENAME, std::ios::in);
    ClassJournal journal_in;
    in >> journal_in;
    in.close();
    // remove(FILENAME);

    ASSERT_EQ(journal_in.n_lessons, 1);
    ASSERT_STREQ(journal_in.lessons[0].topic, "Topic");
    ASSERT_EQ(journal_in.lessons[0].date.day, 25);
    ASSERT_EQ(journal_in.lessons[0].date.month, 4);
    ASSERT_EQ(journal_in.lessons[0].date.year, 2021);
    ASSERT_EQ(journal_in.lessons[0].n_marks, 2);
    ASSERT_STREQ(journal_in.lessons[0].marks[0].student, "Student1");
    ASSERT_EQ(journal_in.lessons[0].marks[0].mark, 5);
    ASSERT_STREQ(journal_in.lessons[0].marks[1].student, "Student2");
    ASSERT_EQ(journal_in.lessons[0].marks[1].mark, 2);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
