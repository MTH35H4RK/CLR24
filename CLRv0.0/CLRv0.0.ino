// Motor pins
const int MOTOR_A_ENA = 11; // this is right motor
const int MOTOR_A_IN1 = 10;
const int MOTOR_A_IN2 = 9;
const int MOTOR_B_IN3 = 6;
const int MOTOR_B_IN4 = 5;
const int MOTOR_B_ENB = 3; // this is left motor


// Define the pins for the TCRT5000L sensor
int sensorPin1 = A4;
int sensorPin2 = A3;
int sensorPin3 = A2;
int sensorPin4 = A1;
int sensorPin5 = A0;

// Define the threshold values for the sensors
int threshold = 500;
void move(int speed1, int speed2) {
  if (speed2 > 0) {
    analogWrite(MOTOR_A_ENA, speed2);
    digitalWrite(MOTOR_A_IN1, LOW);
    digitalWrite(MOTOR_A_IN2, HIGH);
  } else {
    analogWrite(MOTOR_A_ENA, -speed2);
    digitalWrite(MOTOR_A_IN1, HIGH);
    digitalWrite(MOTOR_A_IN2, LOW);
  }
  if (speed1 > 0) {
    analogWrite(MOTOR_B_ENB, speed1);
    digitalWrite(MOTOR_B_IN3, LOW);
    digitalWrite(MOTOR_B_IN4, HIGH);
  } else {
    analogWrite(MOTOR_B_ENB, -speed1);
    digitalWrite(MOTOR_B_IN3, HIGH);
    digitalWrite(MOTOR_B_IN4, LOW);
  }
}


void right() {
  // Read the sensor values
  int sensorValue1 = analogRead(sensorPin1);
  int sensorValue2 = analogRead(sensorPin2);
  int sensorValue3 = analogRead(sensorPin3);
  int sensorValue4 = analogRead(sensorPin4);
  int sensorValue5 = analogRead(sensorPin5);
  //move()
  // Check if the robot is on the line
  if (sensorValue1 < threshold && sensorValue2 < threshold && sensorValue3 < threshold && sensorValue4 < threshold && sensorValue5 < threshold) {
    // Stop the robot
    move(80, 0);
  }
  if (sensorValue1 > threshold && sensorValue2 > threshold && sensorValue3 > threshold && sensorValue4 > threshold && sensorValue5 > threshold) {
    // Stop the robot
    move(90, -50); //turn Dleft slightly
  }
  else {
    // Calculate the position of the robot on the line

    int position = 0;


    if (sensorValue3 < threshold) {
      position = 3;
    }
    if (sensorValue4 < threshold) {
      position = 4;
    }
    if (sensorValue5 < threshold) {
      position = 5;
    }
    if (sensorValue2 < threshold) {
      position = 2;
    }

    if (sensorValue1 < threshold) {
      position = 1;
    }

    // Adjust the motor speed and direction based on the position
    if (position == 1) {
      // Turn Dleft
      move(-60, 60);

    } else if (position == 2) {
      move(0, 60);
    } else if (position == 3) {
      // Go straight
      move(60, 60);
    } else if (position == 4) {
      // Turn Dright slightly
      move(60, 0);
    } else if (position == 5) {

      // Turn Dright
      move(75, -60);


    }
  }
}

void left() {
  // Read the sensor values
  int sensorValue1 = analogRead(sensorPin1);
  int sensorValue2 = analogRead(sensorPin2);
  int sensorValue3 = analogRead(sensorPin3);
  int sensorValue4 = analogRead(sensorPin4);
  int sensorValue5 = analogRead(sensorPin5);
  // Check if the robot is on the line
  if (sensorValue1 < threshold && sensorValue2 < threshold && sensorValue3 < threshold && sensorValue4 < threshold && sensorValue5 < threshold) {

    move(70, 0);


    move(70, 0);
  }
  if (sensorValue1 > threshold && sensorValue2 > threshold && sensorValue3 > threshold && sensorValue4 > threshold && sensorValue5 > threshold) {
    move(70, 0);
    //    turn(255, 100); //turn Dleft slightly
  }
  else {
    // Calculate the position of the robot on the line

    int position = 0;


    if (sensorValue3 < threshold) {
      position = 3;
    }
    if (sensorValue2 < threshold) {
      position = 2;
    }

    if (sensorValue1 < threshold) {
      position = 1;
    }
    if (sensorValue4 < threshold) {
      position = 4;
    }
    if (sensorValue5 < threshold) {
      position = 5;
    }


    if (position == 1) {
      // Turn Dleft
      move(-60, 65);

    } else if (position == 2) {
      move(0, 65);
    } else if (position == 3) {
      // Go straight
      move(65, 65);
    } else if (position == 4) {
      // Turn Dright slightly
      move(65, 0);
    } else if (position == 5) {

      // Turn Dright
      move(65, -80);


    }
  }
}

void setup() {
  Serial.begin(115200);
  // Set the motor pins as output
  pinMode(MOTOR_A_ENA, OUTPUT);
  pinMode(MOTOR_A_IN1, OUTPUT);
  pinMode(MOTOR_A_IN2, OUTPUT);
  pinMode(MOTOR_B_ENB, OUTPUT);
  pinMode(MOTOR_B_IN3, OUTPUT);
  pinMode(MOTOR_B_IN4, OUTPUT);

  // Set the sensor pins as input
  pinMode(sensorPin1, INPUT);
  pinMode(sensorPin2, INPUT);
  pinMode(sensorPin3, INPUT);
  pinMode(sensorPin4, INPUT);
  pinMode(sensorPin5, INPUT);
}

void loop() {
  move(255, 0);


}
