#pragma once

#include <optional>

#include "Command.hpp"
#include "ClassJournalFile.hpp"

struct AppState {
    std::optional<ClassJournalFile> journal_file;

    void consume_callback(void (*)(AppState &));
};
