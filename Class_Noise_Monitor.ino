#include <Wire.h>          // Required for I2C communication
#include <Adafruit_GFX.h>  // Core graphics library
#include <Adafruit_SSD1306.h> // Library for SSD1306 OLED displays

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
// The -1 indicates no reset pin, as it's a 4-pin module
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// Noise Level Sensor
const int analogInPin = A0;  // Analog input pin that the potentiometer is attached to
int sensorValue = 0;  // value read from the pot

void setup() {
  Serial.begin(9600); // Initialize serial communication for debugging

  // Initialize OLED display with I2C address 0x3C (common address)
  // You might need to change this if your OLED has a different address (e.g., 0x3D)
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { 
    Serial.println(F("SSD1306 allocation failed"));
    for (;;); // Don't proceed, loop forever
  }

  // Clear the buffer
  display.clearDisplay();

  // Display initial text
  display.setTextSize(2);      // Set text size (1 is smallest)
  display.setTextColor(SSD1306_WHITE); // Set text color
  display.setCursor(0, 0);     // Set cursor position (x, y)
  display.println("Class Noise Monitor");
  display.display();           // Show the content on the display
}

void loop() {

  // read the analog in value:
  sensorValue = analogRead(analogInPin);
  Serial.println(sensorValue);
  display.clearDisplay();
 

  if(sensorValue > 100) {
      display.setCursor(20, 5);
      display.println("Noise : ");
      display.display();
      display.setCursor(20, 25);
      display.println("High");
      display.display();
      delay(20000);
  }
  if(sensorValue > 50 && sensorValue < 100) {
      display.setCursor(20, 5);
      display.println("Noise : ");
      display.display();
      display.setCursor(20, 25);
      display.println("Medium");
      display.display();
      delay(10000);
  }
 if(sensorValue < 50) {
      display.setCursor(20, 5);
      display.println("Noise : ");
      display.display();
      display.setCursor(20, 25);
      display.println("Low");
      display.display();
  }


  delay(100);



}