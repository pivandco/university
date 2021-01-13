#define _USE_MATH_DEFINES
#include <cmath>

const double ONE_MINUTE_DEG = 360.0 / 60;
const double ONE_HOUR_DEG = 360.0 / 12;
// Доп. смещение часовой стрелки от минут внутри часа
const double HOUR_1_MINUTE_OFFSET_DEG = ONE_HOUR_DEG / 60;

int main() {
    int hours = 14, minutes = 30;

    double minute_angle = ONE_MINUTE_DEG * minutes;
    double hour_angle = ONE_HOUR_DEG * (hours % 12) + HOUR_1_MINUTE_OFFSET_DEG * minutes;

    double angle = std::abs(minute_angle - hour_angle);
    if (angle >= 180)
        angle = 360 - angle;

    return 0;
}
