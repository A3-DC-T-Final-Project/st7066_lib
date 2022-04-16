#include "mbed.h"

int main() {
    Serial serial(USBTX, USBRX);

    serial.printf("Hello World!\n");

    return 0;
}