byte PWM_PIN = 3;
int pwm_value;
int freq;
void setup() {
  pinMode(PWM_PIN, INPUT);
  Serial.begin(115200);
}
void loop() {
  pwm_value = pulseIn(PWM_PIN, HIGH);
  freq = (1/(pwm_value * pow(10, -6)))/2;
  // Should show 2.5khz
  Serial.println(freq);
  voltageOut = map(freq, 1600, 2500, 255, 0);
 // analogWrite(pinOut,voltageOut) //output voltage on pinOut from 0V to 5V. 
}
