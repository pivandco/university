#include "_util.hpp"

#include "../Command.hpp"

using std::optional;
using std::cout;

bool check_file_saved(optional<ClassJournalFile> &file) {
    if (!file.has_value()) {
        return true;
    }
    if (file->unsaved()) {
        cout << "Есть несохраненные изменения.\nИспользуйте \"save\" для сохранения, или \"close!\" для принудительного закрытия.\n";
        return false;
    }
    return true;
}

void require_journal_to_be_open(const optional<ClassJournalFile> &file) {
    if (!file.has_value()) {
        cout << "Файл не открыт.\n";
        throw CommandAborted();
    }
}
