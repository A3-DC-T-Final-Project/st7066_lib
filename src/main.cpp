#include "mbed.h"

#include <ST7066U.hpp>

int main() {
    Serial serial(USBTX, USBRX);
    ST7066U st7066u(PB_0, PB_1, PB_2, PA_15, PD_0, PD_1, PD_2, PD_3, PD_4, PD_5, PD_6, PD_7, &serial);

    serial.printf("Hello World!\n");

    return 0;
}