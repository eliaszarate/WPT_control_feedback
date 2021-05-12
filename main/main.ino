
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
  voltageOut = map(freq, 600, 1900, 0, 162);
  float volt = (voltageOut * 5.0) / 255.0; 
  Serial.print(F("Voltage: "));
  Serial.println(volt);

  // Break if voltage is greater than 3.2V
  if(voltageOut > 162){Serial.print(F("Warning ")); for (;;) {}} 
  
 // Test to make sure voltage is correct
  analogWrite(pinOut,voltageOut); //output voltage on pinOut from 0V to 5V. 
}
