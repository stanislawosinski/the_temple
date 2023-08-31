#include <WebUSB.h>

/**
 * Creating an instance of WebUSBSerial will add an additional USB interface to
 * the device that is marked as vendor-specific (rather than USB CDC-ACM) and
 * is therefore accessible to the browser.
 *
 * The URL here provides a hint to the browser about what page the user should
 * navigate to to interact with the device.
 */
WebUSB WebUSBSerial(1 /* https:// */, "webusb.github.io/arduino/demos/rgb");

#define Serial WebUSBSerial

void setup() {
  while (!Serial) {
    ;
  }
  Serial.begin(9600);
  Serial.write("Sketch begins.\r\n");
  Serial.flush();

  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  if (Serial && Serial.available()) {
    int status = Serial.read();
    digitalWrite(LED_BUILTIN, status == 1 ? HIGH : LOW);
  }
}
