// Pin Definitions
const int buttonPin = 2;    // Pin for the push button
const int relayPin = 3;     // Pin for the relay control

// Variables
bool buttonState = LOW;     // Current state of the button
bool lastButtonState = LOW; // Previous state of the button

void setup() {
  // Initialize Serial communication at 9600 baud rate
  Serial.begin(9600);

  // Configure pin modes
  pinMode(buttonPin, INPUT);  // Push button as input
  pinMode(relayPin, OUTPUT);  // Relay as output

  // Ensure the relay is initially off
  digitalWrite(relayPin, LOW);
}

void loop() {
  // Read the current state of the button
  buttonState = digitalRead(buttonPin);

  // Check if the button was just pressed (rising edge detection)
  if (buttonState == HIGH && lastButtonState == LOW) {
    // Debounce delay (to avoid multiple triggers)
    delay(50);

    // Confirm the button is still pressed after debounce
    if (digitalRead(buttonPin) == HIGH) {
      // Step 1: Turn on the relay
      digitalWrite(relayPin, HIGH);

      // Step 2: Send barcode data to the computer
      sendBarcodeData();

      // Step 3: Turn off the relay after a short delay
      delay(500); // Keep the relay on for 500 ms
      digitalWrite(relayPin, LOW);
    }
  }

  // Update the last button state
  lastButtonState = buttonState;
}

// Function to send barcode data to the computer
void sendBarcodeData() {
  // Example barcode data (replace this with your actual barcode content)
  String barcodeData = "123456789012"; // Example EAN-13 barcode

  // Send the barcode data to the computer
  Serial.println(barcodeData); // Send barcode data followed by a newline
}
