#include <VirtualWire.h>

char *data;
char input;

void setup()
{
  pinMode(5, OUTPUT);  // Pin 5 for controlling motor direction
  pinMode(6, OUTPUT);  // Pin 6 for controlling motor direction
  pinMode(10, OUTPUT); // Pin 10 for controlling motor direction
  pinMode(11, OUTPUT); // Pin 11 for controlling motor direction

  Serial.begin(9600);  // Initialize serial communication with a baud rate of 9600
  vw_set_tx_pin(3);    // Set pin 3 as the transmit pin for VirtualWire library
  vw_setup(2000);      // Set the transmission speed to 2000 bits per second

  pinMode(5, LOW);     // Set initial state of pin 5 to LOW (motor direction control)
  pinMode(6, LOW);     // Set initial state of pin 6 to LOW (motor direction control)
  pinMode(10, LOW);    // Set initial state of pin 10 to LOW (motor direction control)
  pinMode(11, LOW);    // Set initial state of pin 11 to LOW (motor direction control)
}

void loop()
{
  while (Serial.available())
  {
    input = Serial.read();  // Read the incoming serial data
    Serial.println(input);  // Print the received input to the serial monitor

    if (input == 'F')  // If input is 'F' (forward command received)
    {
      data = "f";  // Set the data to be transmitted as "f"
      vw_send((uint8_t *)data, strlen(data));  // Send the data wirelessly
      vw_wait_tx();  // Wait for the transmission to complete
      left();  // Call the left() function to control motor direction
    }
    else if (input == 'R')  // If input is 'R' (right command received)
    {
      data = "r";  // Set the data to be transmitted as "r"
      vw_send((uint8_t *)data, strlen(data));  // Send the data wirelessly
      vw_wait_tx();  // Wait for the transmission to complete
      forward();  // Call the forward() function to control motor direction
    }
    else if (input == 'L')  // If input is 'L' (left command received)
    {
      data = "l";  // Set the data to be transmitted as "l"
      vw_send((uint8_t *)data, strlen(data));  // Send the data wirelessly
      vw_wait_tx();  // Wait for the transmission to complete
      backward();  // Call the backward() function to control motor direction
    }
    else if (input == 'G')  // If input is 'G' (go command received)
    {
      data = "g";  // Set the data to be transmitted as "g"
      vw_send((uint8_t *)data, strlen(data));  // Send the data wirelessly
      vw_wait_tx();  // Wait for the transmission to complete
      right();  // Call the right() function to control motor direction
    }
    else if (input == 'S')  // If input is 'S' (stop command received)
    {
      data = "s";  // Set the data to be transmitted as "s"
      vw_send((uint8_t *)data, strlen(data));  // Send the data wirelessly
      vw_wait_tx();  // Wait for the transmission to complete
      stop();  // Call the stop() function to stop all motors
    }
  }
}

void forward()
{
  digitalWrite(5, LOW);
  digitalWrite(6, HIGH);
  digitalWrite(10, LOW);
  digitalWrite(11, HIGH);
}

void backward()
  {
  digitalWrite(5, HIGH);
  digitalWrite(6, LOW);
  digitalWrite(10, HIGH);
  digitalWrite(11, LOW);
}

void stop()
{
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
}


void right()
{
  digitalWrite(5, LOW);
  digitalWrite(6, HIGH);
  digitalWrite(10, HIGH);
  digitalWrite(11, LOW);
}

void left()
{
  digitalWrite(6, LOW);
  digitalWrite(5, HIGH);
  digitalWrite(10, LOW);
  digitalWrite(11, HIGH);
}