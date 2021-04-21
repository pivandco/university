#pragma once

#include <limits>
#include <stdexcept>
#include <sstream>

template<typename T>
class SafeArithmetics {
public:
    static T add(T a, T b) {
        if (a > 0 && b > std::numeric_limits<T>::max() - a) {
            throw std::overflow_error("overflow");
        }
        if (a < 0 && b < std::numeric_limits<T>::min() - a) {
            throw std::overflow_error("underflow");
        }
        return a + b;
    }

    static T subtract(T a, T b) {
        if (b < 0 && a > std::numeric_limits<T>::max() + b) {
            throw std::overflow_error("overflow");
        }
        if (b > 0 && a < std::numeric_limits<T>::min() + b) {
            throw std::overflow_error("underflow");
        }
        return a - b;
    }

    static T multiply(T a, T b) {
        if (!a || !b)
            return 0;

        T min = std::numeric_limits<T>::min(), max = std::numeric_limits<T>::max();
        if ((b == -1 && a == min) || (a == -1 && b == min) || (a > max / b) || (a < min / b))
            throw std::overflow_error("overflow");
        return a * b;
    }

    static T divide(T a, T b) {
        if (!b)
            throw std::domain_error("division by zero");
        if (b == -1 && a == std::numeric_limits<T>::min())
            throw std::overflow_error("overflow");
        return a / b;
    }

    static T abs(T n) {
        if (n < -std::numeric_limits<T>::max())
            throw std::overflow_error("overflow");
        return ::abs(n);
    }
};
