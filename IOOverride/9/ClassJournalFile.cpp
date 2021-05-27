#include "ClassJournalFile.hpp"

#include <filesystem>
#include <fstream>

using std::ifstream, std::ofstream;
using std::make_optional;

ClassJournalFile::ClassJournalFile(std::string name) : name(name) {
    if (exists_on_disk()) {
        load();
    } else {
        journal = make_optional<ClassJournal>();
    }
}

const ClassJournal &ClassJournalFile::get_journal() {
    return *journal;
}

ClassJournal &ClassJournalFile::get_journal_and_mark_changed() {
    _has_unsaved_changes = true;
    return const_cast<ClassJournal &>(get_journal());
}

void ClassJournalFile::save() {
    ofstream out(name);
    out << *journal;
    _has_unsaved_changes = false;
}

void ClassJournalFile::load() {
    ifstream in(name);
    ClassJournal loaded;
    in >> loaded;
    journal = loaded;
    _has_unsaved_changes = false;
}

bool ClassJournalFile::exists_on_disk() const {
    return std::filesystem::exists(name);
}
