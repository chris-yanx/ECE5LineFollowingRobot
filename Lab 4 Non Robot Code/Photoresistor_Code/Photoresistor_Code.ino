/* Photoresistor Code UCSD ECE 5 Lab 4 */
/* Variables for Light Sensors*/

// Initialize Photo Resistor Array
int LDR_Pin[] = {A8, A9, A10, A11, A12, A13, A14}; 

int totalPhotoResistors = sizeof(LDR_Pin) / sizeof(LDR_Pin[0]);  

int LDR[99];

//int led_Pins[] = {41};
//int numLEDs = sizeof(led_Pins) / sizeof(led_Pins[0]);    
//int led_val=0;

void setup() {
  Serial.begin(9600); // For serial communication set up
  
  for (int i = 0; i < totalPhotoResistors; i++) 
    pinMode(LDR_Pin[i],  INPUT);
    
//  for (int i = 0; i < numLEDs; i++)
//    pinMode(led_Pins[i], OUTPUT);   


}

void loop() {
  /**FIX ME: Which function should we call here to read photo resistors? **/ // Read photoresistors and map to 0-100 based on calibration
//  if (led_val == 0)
//    led_val = 1;
//  else if (led_val == 1)
//    led_val = 0;
//  setLeds(led_val);
  ReadPhotoResistors();
  /**FIX ME: Which function should we call here to print out our values? **/ // Print values to serial monitor
  Print();
}

// ************************************************************************************************* //
// function to read photo resistors
//void setLeds(int x) {
//  for (int i = 0; i < numLEDs; i++)
//    digitalWrite(led_Pins[i], x);
//}

void ReadPhotoResistors() {
  for (int i = 0; i < totalPhotoResistors; i++) {

    LDR[i] = (float)analogRead(LDR_Pin[i]);
    delay(20);
  }
}

// ************************************************************************************************* //
// function to print values of interest
void Print() {
  for (int i = 0; i < totalPhotoResistors; i++) {
    // Printing the photo resistor reading values one by one
    Serial.print(LDR[i]);
    Serial.print(" ");
  }
  Serial.println(); // This just prints a new line, allowing the next set of readings to be on a new line

  delay(200); //just here to slow down the output for easier reading if desired
}
