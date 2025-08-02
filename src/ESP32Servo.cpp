#include "ESP32Servo.h"

// Initialize static variables
uint8_t ESP32Servo::_resolutionBits = 10;      // Default resolution: 10 bits
uint16_t ESP32Servo::_frequencyHz = 50;        // Default servo frequency: 50Hz

ESP32Servo::ESP32Servo() {
    _pin = 255;
    _channel = 255;
}

void ESP32Servo::setResolution(uint8_t resolutionBits) {
    _resolutionBits = resolutionBits;
}

void ESP32Servo::setFrequency(uint16_t frequencyHz) {
    _frequencyHz = frequencyHz;
}

void ESP32Servo::attach(uint8_t pin, uint8_t channel) {
    _pin = pin;
    _channel = channel;

    // Setup PWM functionality on the specified pin and channel
    ledcSetup(_channel, _frequencyHz, _resolutionBits);
    ledcAttachPin(_pin, _channel);
}

void ESP32Servo::writeMicroseconds(uint16_t microseconds) {
    // Typical servo pulse width range: 1000µs to 2000µs
    // Map this range to the PWM duty cycle based on resolution
    uint32_t maxDuty = (1 << _resolutionBits) - 1;  // Max duty for given resolution
    uint32_t duty = (microseconds * maxDuty * _frequencyHz) / 1000000;

    ledcWrite(_channel, duty);
}

void ESP32Servo::write(int angle) {
    if (_pin == -1 || _channel == -1) return;

    angle = constrain(angle, 0, 180);

    // Calcule des rapports cycliques en fonction de la résolution
    uint32_t max_duty = (1 << _resolution) - 1;
    uint32_t dutyMin = max_duty * 0.025; // ~0.5 ms
    uint32_t dutyMax = max_duty * 0.125; // ~2.5 ms

    int duty = map(angle, 0, 180, dutyMin, dutyMax);
    ledcWrite(_channel, duty);
    _angle = angle;
}

int ESP32Servo::getAngle() const {
    return _angle;
}