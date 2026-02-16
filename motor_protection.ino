// Industrial Motor Protection System Using Arduino
// Monitors temperature and current
// Cuts off motor using relay if limits exceeded

// Pin Definitions
const int tempSensorPin = A0;     // LM35 connected to A0
const int currentSensorPin = A1;  // Current sensor to A1
const int relayPin = 7;           // Relay module
const int buzzerPin = 8;          // Buzzer

// Threshold Values
float maxTemperature = 50.0;   // Maximum allowed temperature (°C)
float maxCurrent = 3.0;        // Maximum allowed current (Amps)

// Variables
float temperature = 0.0;
float current = 0.0;

void setup() {
  Serial.begin(9600);

  pinMode(relayPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);

  digitalWrite(relayPin, HIGH);  // Motor ON (relay active)
  digitalWrite(buzzerPin, LOW);

  Serial.println("Industrial Motor Protection System Started");
}

void loop() {

  // Read Temperature from LM35
  int tempValue = analogRead(tempSensorPin);
  float voltage = tempValue * (5.0 / 1023.0);
  temperature = voltage * 100;   // LM35 conversion

  // Read Current Sensor (Simulation)
  int currentValue = analogRead(currentSensorPin);
  float currentVoltage = currentValue * (5.0 / 1023.0);
  current = currentVoltage * 5;  // Adjust multiplier as per sensor

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print(" °C | Current: ");
  Serial.print(current);
  Serial.println(" A");

  // Protection Logic
  if (temperature > maxTemperature || current > maxCurrent) {
    
    digitalWrite(relayPin, LOW);   // Turn OFF motor
    digitalWrite(buzzerPin, HIGH); // Activate alarm
    
    Serial.println("FAULT DETECTED! Motor Turned OFF.");
  }
  else {
    digitalWrite(relayPin, HIGH);  // Motor ON
    digitalWrite(buzzerPin, LOW);  // Alarm OFF
  }

  delay(1000);
}
