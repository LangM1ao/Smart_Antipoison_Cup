#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Servo.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_I2C_ADDRESS 0x3C 

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

const int pH_PIN = A0;
const int SERVO_PIN = 6;
Servo myServo;

const int LED_PIN = 7;

void setup() {
  Serial.begin(9600);

  // 初始化OLED屏幕
  if (!display.begin(SSD1306_SWITCHCAPVCC, OLED_I2C_ADDRESS)) { // 使用显式定义的I2C地址
    Serial.println(F("OLED initialization failed"));
    while (true); // 如果初始化失败，保持在此处
  }

  // 初始化舵机
  myServo.attach(SERVO_PIN);
  myServo.write(0); // 初始位置设为0度

  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW); 

  display.clearDisplay();
  display.display();
}

void loop() {
  int analogValue = analogRead(pH_PIN);
  float voltage = analogValue * (5.0 / 1024.0);
  Serial.print("Analog Value: ");
  Serial.println(voltage);

  float pHValue = 7 + ((2.5 - voltage) / 0.167);
  Serial.print("pH Value: ");
  Serial.println(pHValue);

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println("pH Sensor Reading:");
  display.setTextSize(2);
  display.setCursor(0, 20);
  display.print("pH: ");
  display.println(pHValue, 2); // 保留两位小数
  display.display();

  if (pHValue > 9 || pHValue < 5) {
    myServo.write(120);
    unsigned long startTime = millis();
    while (millis() - startTime < 20000) {
      analogValue = analogRead(pH_PIN);
      voltage = analogValue * (5.0 / 1024.0);
      pHValue = 7 + ((2.5 - voltage) / 0.167);

      display.clearDisplay();
      display.setTextSize(1);
      display.setTextColor(SSD1306_WHITE);
      display.setCursor(0, 0);
      display.println("pH Sensor Reading:");
      display.setTextSize(2);
      display.setCursor(0, 20);
      display.print("pH: ");
      display.println(pHValue, 2);
      display.display();

      digitalWrite(LED_PIN, HIGH);
      delay(250);
      digitalWrite(LED_PIN, LOW);
      delay(250); 
    }
    myServo.write(0);

    unsigned long secondStartTime = millis();
    while (millis() - secondStartTime < 100000) {
      analogValue = analogRead(pH_PIN);
      voltage = analogValue * (5.0 / 1024.0);
      pHValue = 7 + ((2.5 - voltage) / 0.167) ;

      display.clearDisplay();
      display.setTextSize(1);
      display.setTextColor(SSD1306_WHITE);
      display.setCursor(0, 0);
      display.println("pH Sensor Reading:");
      display.setTextSize(2);
      display.setCursor(0, 20);
      display.print("pH: ");
      display.println(pHValue, 2);
      display.display();

      delay(500);

      digitalWrite(LED_PIN, HIGH);
      delay(250);
      digitalWrite(LED_PIN, LOW);
      delay(250);
    }
  } else {
    digitalWrite(LED_PIN, LOW);
  }

  delay(1000); 
}
