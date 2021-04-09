
/*
 * Arduino .ino file for DSP
 * feedback testing
 */

byte PWM_PIN = 3;
byte pinOut = 10;
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
  Serial.print(F("Freq: "));
  Serial.println(freq);

  // Saturate, avoid negative values
  if(freq < 1600){
    freq = 1600;
  } else if (freq > 2500){
    freq = 2500;    
  }

  // Map voltage ouput with input frequency
  voltageOut = map((int)freq, 1600, 2500, 0, 169);
  Serial.print(F("Voltage: "));
  Serial.println(voltageOut);

  // Break if voltage is greater than 3.2V
  if(voltageOut > 163){Serial.print(F("Warning ")); for (;;) {}} 
  
 // Test to make sure voltage is correct
 // analogWrite(pinOut,voltageOut) //output voltage on pinOut from 0V to 5V. 
}
