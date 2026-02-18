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
#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <DHT.h>

/** @brief OLED display width in pixels */
#define SCREEN_WIDTH 128

/** @brief OLED display height in pixels */
#define SCREEN_HEIGHT 64

/** @brief OLED reset pin (-1 if shared reset line is used) */
#define OLED_RESET -1

/**
 * @brief SSD1306 OLED display object.
 * 
 * Uses I2C communication via the default Wire interface.
 */
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

/** @brief Digital pin connected to DHT11 data line */
#define DHTPIN 2

/** @brief DHT sensor type definition */
#define DHTTYPE DHT11

/**
 * @brief DHT sensor object instance.
 */
DHT dht(DHTPIN, DHTTYPE);

/**
 * @brief System initialization routine.
 *
 * @details
 * - Initializes Serial communication at 9600 baud.
 * - Initializes DHT11 sensor.
 * - Initializes OLED display.
 * - Displays startup splash message.
 * - Halts execution if OLED initialization fails.
 */

