#include "ClassJournalFile.hpp"

#include <filesystem>
#include <fstream>

using std::ifstream, std::ofstream;
using std::make_optional;

ClassJournalFile::ClassJournalFile(std::string name) : name(name) {
    if (exists_on_disk()) {
        load();
    } else {
        _journal = make_optional<ClassJournal>();
    }
}

const ClassJournal &ClassJournalFile::journal() {
    return *_journal;
}

ClassJournal &ClassJournalFile::writable_journal() {
    _unsaved = true;
    return const_cast<ClassJournal &>(journal());
}

void ClassJournalFile::save() {
    ofstream out(name);
    out << *_journal;
    _unsaved = false;
}

bool ClassJournalFile::unsaved() const {
    return _unsaved;
}

void ClassJournalFile::load() {
    ifstream in(name);
    ClassJournal loaded;
    in >> loaded;
    _journal = loaded;
    _unsaved = false;
}

bool ClassJournalFile::exists_on_disk() const {
    return std::filesystem::exists(name);
}
