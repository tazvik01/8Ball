// Include the LiquidCrystal library, which allows us to control the LCD display
#include <LiquidCrystal.h>

// Initialize a LiquidCrystal object with the corresponding pin numbers for the LCD
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// Define variables to handle the switch input
int switchPin = 6;       // The pin number where the switch is connected
int switchState = 0;     // Variable to store the current state of the switch (HIGH or LOW)
int prevSwitchState = 0; // Variable to store the previous state of the switch
int reply;               // Variable to store the random reply index

// Setup function runs once when the Arduino is powered on or reset
void setup() {
  // Initialize the LCD display with 16 columns and 2 rows
  lcd.begin(16, 2);
  
  // Set the switchPin as an input
  pinMode(switchPin, INPUT);

  // Display an initial message on the LCD
  lcd.print("Ask the");
  lcd.setCursor(0, 1);
  lcd.print("Crystal Ball");
}

// Loop function runs repeatedly as long as the Arduino is powered on
void loop() {
  // Read the current state of the switch (HIGH or LOW)
  switchState = digitalRead(switchPin);

  // Check if the switch state has changed since the last loop iteration
  if (switchState != prevSwitchState) {
    // If the switch is pressed (switchState is LOW)
    if (switchState == LOW) {
      // Generate a random number between 0 and 7 (8 possibilities)
      reply = random(8);

      // Clear the LCD display
      lcd.clear();

      // Print a message on the LCD to indicate the Crystal Ball is responding
      lcd.setCursor(0, 0);
      lcd.print("The ball says: ");
      lcd.setCursor(0, 1);

      // Depending on the random reply index, display a response on the LCD
      switch (reply) {
        case 0:
          lcd.print("Yes");
          break;
        case 1:
          lcd.print("Definitely");
          break;
        case 2:
          lcd.print("No");
          break;
        case 3:
          lcd.print("Haha you wish");
          break;
        case 4:
          lcd.print("I guess");
          break;
        // Add more cases for additional responses if needed

        default:
          lcd.print("Ask again");
          break;
      }
    }
  }

  // Update the previous switch state for the next loop iteration
  prevSwitchState = switchState;
}
