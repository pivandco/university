#include <cmath>

int main() {
    int n = 888888;
    //          Так как N<=10 в 6 степ.
    //                              |||  Макс. рассматриваемое P или Q. sqrt(n) потому что при таких P и Q выражение на 14 строке будет 0.
    //                              |||  Т. к. там модуль, меньше 0 мы не получим.
    //                              vvv  vvvvvvvvvvvvvvvvvvvvvv
    unsigned long int min_absexpr = 1E6, max_addendum = sqrt(n), min_q = 0, min_p = 0;
    for (int p = 1; p <= max_addendum; p++) {
        //       q = p , а не q = 1, так как иначе бы мы перебирали уже рассмотренные пары чисел.
        //       vvvvv
        for (int q = p; q <= max_addendum; q++) {
            int absexpr = abs(n - pow(p, 2) - pow(q, 2));  // Та самая формула из условия
            if (absexpr < min_absexpr || (absexpr == min_absexpr && min_q > q)) {
                min_absexpr = absexpr;
                min_p = p;
                min_q = q;
            }
        }
    }

    return 0;
}
