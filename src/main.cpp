/**
 * @file Ultrasonic_Servo_Control.ino
 * @version 1.0
 * @date 18 Feb 2026
 * @author Bhartendu Ji
 *
 * @brief Object detection and servo control using Ultrasonic Sensor (HC-SR04).
 *
 * @details
 * This program measures the distance of an object using an HC-SR04
 * ultrasonic sensor. If the detected object is within 15 cm,
 * a servo motor rotates to 180 degrees. Otherwise, it returns
 * to 0 degrees.
 *
 * @section hardware Hardware Requirements
 * - Arduino Board (Uno/Nano/etc.)
 * - HC-SR04 Ultrasonic Sensor
 * - Servo Motor (SG90 or equivalent)
 *
 * @section wiring Wiring Configuration
 * Ultrasonic Sensor:
 * - VCC  -> 5V
 * - GND  -> GND
 * - Trig -> Digital Pin 9
 * - Echo -> Digital Pin 10
 *
 * Servo Motor:
 * - Signal -> Digital Pin 5
 * - VCC    -> 5V
 * - GND    -> GND
 *
 * @section working Working Principle
 * 1. Send a short trigger pulse to the ultrasonic sensor.
 * 2. Measure echo return time using pulseIn().
 * 3. Calculate distance using speed of sound.
 * 4. Rotate servo based on threshold distance (15 cm).
 */

#include <Servo.h>

/** @brief Servo motor object */
Servo myservo;

/** @brief Ultrasonic trigger pin */
int trg_pin = 9;

/** @brief Ultrasonic echo pin */
int ech_pin = 10;


/**
 * @brief System initialization routine.
 *
 * Initializes:
 * - Ultrasonic sensor pins
 * - Servo motor attachment
 * - Serial communication (9600 baud)
 */
void setup() {
  pinMode(trg_pin, OUTPUT);
  pinMode(ech_pin, INPUT);

  myservo.attach(5);   ///< Attach servo to digital pin 5

  Serial.begin(9600);
}


/**
 * @brief Main control loop.
 *
 * @details
 * - Sends trigger pulse to ultrasonic sensor.
 * - Measures echo duration.
 * - Calculates distance in centimeters.
 * - Rotates servo to 180° if object ≤ 15 cm.
 * - Otherwise sets servo to 0°.
 * - Prints distance on Serial Monitor.
 */
void loop() {

  // Send trigger pulse
  digitalWrite(trg_pin, LOW);
  delayMicroseconds(2);
  digitalWrite(trg_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trg_pin, LOW);

  // Measure echo duration
  long duration = pulseIn(ech_pin, HIGH);

  // Calculate distance (cm)
  float distance = duration * (0.0343 / 2);

  // Control servo based on distance threshold
  if (distance <= 15) {
    myservo.write(180);
  } else {
    myservo.write(0);
  }

  // Print distance to Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  delay(10);
}
