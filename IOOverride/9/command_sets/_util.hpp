#pragma once

#include <optional>

#include "../AppState.hpp"
#include "../ClassJournalFile.hpp"

bool check_file_saved(std::optional<ClassJournalFile> &);
void require_journal_to_be_open(const std::optional<ClassJournalFile> &);
