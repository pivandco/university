#pragma once

#include <string>
#include <optional>

#include "ClassJournal.hpp"

class ClassJournalFile {
public:
    std::string name;

    ClassJournalFile(std::string name);
    const ClassJournal &get_journal();
    ClassJournal &get_journal_and_mark_changed();
    void save();
    inline bool has_unsaved_changes() const {
        return _has_unsaved_changes;
    }
    bool exists_on_disk() const;

private:
    std::optional<ClassJournal> journal;
    bool _has_unsaved_changes = false;

    void load();
};
