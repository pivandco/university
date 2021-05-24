#include "ClassJournalFile.hpp"

#include <filesystem>
#include <fstream>

using std::ifstream, std::ofstream;

ClassJournalFile::ClassJournalFile(std::string name) : name(name) {
}

const ClassJournal &ClassJournalFile::get_journal() {
    if (!journal.has_value()) {
        load();
    }
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
