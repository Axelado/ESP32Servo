#ifndef ESP32SERVO_H
#define ESP32SERVO_H

#include <Arduino.h>

class ESP32Servo {
public:
    ESP32Servo();

    // Set the PWM resolution (in bits)
    static void setResolution(uint8_t resolutionBits);

    // Set the PWM frequency (in Hz)
    static void setFrequency(uint16_t frequencyHz);

    // Attach the servo to a given pin and PWM channel
    void attach(uint8_t pin, uint8_t channel);

    // Write the PWM pulse width in microseconds
    void writeMicroseconds(uint16_t microseconds);

private:
    uint8_t _pin;
    uint8_t _channel;

    static uint8_t _resolutionBits;
    static uint16_t _frequencyHz;
};

#endif
