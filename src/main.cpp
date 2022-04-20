#include <ST7066U.hpp>

#include "mbed.h"
DigitalOut led1(LED1);
int main() {
    ST7066U st7066u(PB_0, PB_1, PB_2, PA_15, PD_0, PD_1, PD_2, PD_3, PD_4, PD_5,
                    PD_6, PD_7, false, false);

    while(true) {
        st7066u.clear();
        st7066u.firstLine();
        st7066u.printString("gb1149");
        st7066u.secondLine();
        st7066u.printString("joe2k01");
        thread_sleep_for(50); // 1 ms
    }

    return 0;
}