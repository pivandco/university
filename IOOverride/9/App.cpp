#include "App.hpp"

void App::loop() {
    while (true) {
        state.consume_callback(cli.get_command().callback);
    }
}
