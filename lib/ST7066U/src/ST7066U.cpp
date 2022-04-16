#include "ST7066U.hpp"

#include "mbed.h"

ST7066U::ST7066U(PinName rs, PinName rw, PinName e, PinName oe, PinName d0, PinName d1,
                 PinName d2, PinName d3, PinName d4, PinName d5, PinName d6,
                 PinName d7, Serial * serial)
    : _rs(rs),
      _rw(rw),
      _e(e),
      _oe(oe),
      _d0(d0),
      _d1(d1),
      _d2(d2),
      _d3(d3),
      _d4(d4),
      _d5(d5),
      _d6(d6),
      _d7(d7) {

    // Default all pins to ground
    _rs = 0;
    _rw = 0;
    _e = 0;
    _d0 = 0;
    _d1 = 0;
    _d2 = 0;
    _d3 = 0;
    _d4 = 0;
    _d5 = 0;
    _d6 = 0;
    _d7 = 0;

    // Enable LCD output
    _oe = 1;

    // Store pointers to pins
    pins = (DigitalInOut **) malloc(DATA_PINS * sizeof(DigitalInOut *));
    pins[0] = &(_d0);
    pins[1] = &(_d1);
    pins[2] = &(_d2);
    pins[3] = &(_d3);
    pins[4] = &(_d4);
    pins[5] = &(_d5);
    pins[6] = &(_d6);
    pins[7] = &(_d7);

    _serial = serial;

    // Allocate memory for data array
    data = (int *) malloc(DATA_PINS * sizeof(int));

    reset();
    test();
}

void ST7066U::write(int * data) {
    int i;
    // Enable write mode (write is active low)
    _rw = 0;
    // Select instruction register
    _rs = 0;
    // Start enable signal (pw 140ns)
    _e = 1;
    wait_ns(100);

    // Load data to write on pin
    for(i = 0; i < DATA_PINS; i++) {
        pins[i]->write(data[i]);
    }

    // Hold data (pw 40 ns)
    wait_ns(40);

    // Emable signal goes low
    _e = 0;

    // Hold data for 10 ns
    wait_ns(10);

    wait_us(2000);
}

void ST7066U::reset() {
    data[0] = 1;

    int i;
    for(i = 1; i < DATA_PINS; i++) {
        data[i] = 0;
    }

    write(data);
    _serial->printf("reset done\n");
}

void ST7066U::test() {
    int i;
    for(i = 0; i < DATA_PINS; i++) {
        data[i] = 0;
    }

    data[3] = 1;
    data[2] = 1;

    write(data);
    _serial->printf("test done\n");
}