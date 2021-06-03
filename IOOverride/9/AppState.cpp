#include "AppState.hpp"

#include "Command.hpp"

void AppState::consume_callback(void (*callback)(AppState &)) {
    try {
        callback(*this);
    } catch (CommandAborted) {
    }
}
