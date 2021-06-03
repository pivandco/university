#pragma once

#include <string>
#include <optional>

#include "ClassJournal.hpp"

class ClassJournalFile {
public:
    std::string name;

    ClassJournalFile(std::string name);
    const ClassJournal &journal();
    ClassJournal &writable_journal();
    void save();
    bool unsaved() const;
    bool exists_on_disk() const;

private:
    std::optional<ClassJournal> _journal;
    bool _unsaved = false;

    void load();
};
