#include <ST7066U.hpp>

#include "mbed.h"
DigitalOut led1(LED1);
int main() {
    ST7066U st7066u(PB_0, PB_1, PB_2, PA_15, PD_0, PD_1, PD_2, PD_3, PD_4, PD_5,
                    PD_6, PD_7, false, false);
    
    uint8_t test[8][5] = {
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {1, 0, 1, 0, 1},
        {0, 0, 1, 0, 0},
        {1, 0, 1, 0, 1},
        {0, 1, 1, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}
    };
    
    uint8_t smileyAddr = st7066u.storeCustomChar(st7066u.smiley);
    st7066u.helloWorld();
    uint8_t testAddr = st7066u.storeCustomChar(test);
    st7066u.writeCustomChar(smileyAddr);
    st7066u.writeCustomChar(testAddr);
    thread_sleep_for(2000); // 2 seconds
    

    while(true) {
        st7066u.clear();
        st7066u.firstLine();
        st7066u.printString("gb1149xxxxxxxxxy");
        st7066u.secondLine();
        st7066u.printString("joe2k01xxxxxxxxy");
        thread_sleep_for(200); // 200 ms
        st7066u.clearFirstLine();
        thread_sleep_for(200); // 200 ms
        st7066u.printString("First line");
        thread_sleep_for(200); // 200 ms
        st7066u.clearSecondLine();
        thread_sleep_for(200); // 200 ms
        st7066u.printString("Second line");
        thread_sleep_for(200); // 200 ms
    }

    return 0;
}