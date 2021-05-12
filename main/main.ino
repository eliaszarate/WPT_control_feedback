
/*
 * Arduino .ino file for DSP
 * feedback testing
 */

// Input to the Arduino (freq),  
// Place on pin 49 of the DSP
byte PWM_PIN = 3; 

// Output of the Arduino (volt).
// Place on analog pin 15 of DSP
byte pinOut = 10;

// Globals
int pwm_value;
int voltageOut;
int freq;


void setup() {
  pinMode(PWM_PIN, INPUT);
  Serial.begin(115200);
}

void loop() {
  // Calculate frequency from PWM input
  pwm_value = pulseIn(PWM_PIN, HIGH);
  freq = (1/(pwm_value * pow(10, -6)))/2;
  //freq = 600;

   // Saturate, avoid negative values
  if(freq < 600){
    freq = 600;
  } else if (freq > 1900){
    freq = 1900;    
  }
  Serial.print(F("Freq: "));
  Serial.println(freq);

  // Map voltage ouput with input frequency
<<<<<<< HEAD
  voltageOut = map(freq, 600, 1900, 162, 0);
  float volt = (voltageOut * 5.0) / 255.0; 
=======
  voltageOut = map(freq, 1600, 2500, 167, 0);
  float volt = (160 * 5) / 1023; 
  voltageOut = map((int)freq, 1600, 2500, 0, 169);
>>>>>>> f7629dc752326b1dd139aadd3f09854f72e90e16
  Serial.print(F("Voltage: "));
  Serial.println(volt);

  // Break if voltage is greater than 3.2V
  if(voltageOut > 162){Serial.print(F("Warning ")); for (;;) {}} 
  
 // Test to make sure voltage is correct
  analogWrite(pinOut,voltageOut); //output voltage on pinOut from 0V to 5V. 
}
