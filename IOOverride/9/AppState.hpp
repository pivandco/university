#pragma once

#include <optional>

#include "ClassJournalFile.hpp"

struct AppState {
    std::optional<ClassJournalFile> journal_file;
};
