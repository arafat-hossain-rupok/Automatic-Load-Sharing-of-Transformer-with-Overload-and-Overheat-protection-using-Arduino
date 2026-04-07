#include <Wire.h>
#include <Adafruit_INA219.h>
#include <LiquidCrystal_I2C.h>
#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS 2

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);
LiquidCrystal_I2C lcd(0x3F, 16, 2);
Adafruit_INA219 ina219;

#define L1      3
#define L2      4
#define L3      5
#define L4      6

#define S1      7
#define S2      8
#define S3      9
#define S4      10

#define RR1     11
#define RR2     12

int last1 = 0, last2 = 0, last3 = 0, last4 = 0;
int L1_S = 1, L2_S = 1, L3_S = 1, L4_S = 1;
int count = 0, load4 = 0;

// Define analog input
#define ANALOG_IN_PIN A0

float adc_voltage = 0.0;
float in_voltage = 0.0;

float R1 = 100000.0;
float R2 = 10000.0;

float ref_voltage = 3.3;
int adc_value = 0;

#define ANALOG_IN_PIN1 A1

float adc_voltage1 = 0.0;
float in_voltage1 = 0.0;

int adc_value1 = 0;

unsigned long previousMillis = 0;
const long interval = 5000;

void setup() {
  lcd.init();
  lcd.backlight();

  Serial.begin(9600);
  pinMode(S1, INPUT);
  pinMode(S2, INPUT);
  pinMode(S3, INPUT);
  pinMode(S4, INPUT);

  pinMode(L1, OUTPUT);
  pinMode(L2, OUTPUT);
  pinMode(L3, OUTPUT);
  pinMode(L4, OUTPUT);

  pinMode(RR1, OUTPUT);
  pinMode(RR2, OUTPUT);

  digitalWrite(L1, L1_S);
  digitalWrite(L2, L2_S);
  digitalWrite(L3, L3_S);
  digitalWrite(L4, L4_S);

  digitalWrite(RR1, LOW);
  digitalWrite(RR2, HIGH);

  ina219.begin();
  sensors.begin();
}

void loop() {
  sensors.requestTemperatures();
  float tempC = sensors.getTempCByIndex(0);
  adc_value = analogRead(ANALOG_IN_PIN);
  adc_voltage  = (adc_value * ref_voltage) / 1024.0;
  in_voltage = adc_voltage / (R2 / (R1 + R2)) ;


  adc_value1 = analogRead(ANALOG_IN_PIN1);
  adc_voltage1  = (adc_value1 * ref_voltage) / 1024.0;
  in_voltage1 = adc_voltage1 / (R2 / (R1 + R2)) ;


  int V_S1 = digitalRead(S1);
  int V_S2 = digitalRead(S2);
  int V_S3 = digitalRead(S3);
  int V_S4 = digitalRead(S4);

  int power = 1;
  if (in_voltage <= 5 && in_voltage1 <= 5) {
    power = 0;
  }
  else {
    power = 1;
  }


  digitalWrite(L1, L1_S);
  digitalWrite(L2, L2_S);
  digitalWrite(L3, L3_S);
  digitalWrite(L4, L4_S);


  lcd.setCursor(0, 0);
  lcd.print("T : ");
  lcd.print(tempC);
  lcd.print((char)223);
  lcd.print("C ");
  lcd.setCursor(0, 1);
  if (power == 0) {
    lcd.print("No Power        ");
  }
  else if (count == 3) {
    lcd.print("Power Sharing   ");
  }
  else if (count == 4) {
    lcd.print("Over load       ");
  }
  else if (tempC >= 40) {
    lcd.print("Temperature HIGH");
  }
  else {
    lcd.print("                ");
  }

  if (tempC >= 40) {
    digitalWrite(RR1, HIGH);
    digitalWrite(RR2, HIGH);
  }
  else {
    digitalWrite(RR1, LOW);
    digitalWrite(RR2, LOW);
  }
  delay(1000);
}
