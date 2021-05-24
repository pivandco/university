#include "App.hpp"

void App::loop() {
    while (true) {
        cli.get_command().callback(state);
    }
}
