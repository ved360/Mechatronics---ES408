#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

// Create an instance of the PWM driver
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

// Set the pulse length parameters
#define SERVOMIN  150   // Minimum pulse length for a 0-degree angle
#define SERVOMAX  600   // Maximum pulse length for a 180-degree angle
// #define SERVONUM  0     // Servo motor channel on the PWM board (0-15)

void setup() {
  Serial.begin(9600);
  Serial.println("Starting servo control");

  pwm.begin();
  pwm.setPWMFreq(60);  // Set the PWM frequency to 60 Hz for standard servos
}

void setServoAngle(uint8_t servo, float angle) {
  // Map the angle (0-180) to the pulse length range
  uint16_t pulselength = map(angle, 0, 180, SERVOMIN, SERVOMAX);
  pwm.setPWM(servo, 0, pulselength);
}

void loop() {
  // Test: Move servo to 0 degrees
  setServoAngle(4, 90);
  delay(1000);

  setServoAngle(1, 90);
  delay(1000);

  setServoAngle(1, 180);
  delay(1000);

  setServoAngle(4, 180);
  delay(1000);

  setServoAngle(4, 90);
  // delay(1000);

  setServoAngle(1, 90);
  delay(1000);

  setServoAngle(1, 0);
  delay(1000);

  setServoAngle(4, 180);
  delay(1000);

  setServoAngle(4, 90);
  // delay(1000);

  setServoAngle(1, 90);
  delay(1000);

}