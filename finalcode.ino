#include <Servo.h>
#include <Stepper.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define STEPS 2048
Stepper stepperMotor(STEPS, 8, 10, 9, 11);

Servo bras;

LiquidCrystal_I2C lcd(0x27, 16, 2);

#define IR 2

#define S0 4
#define S1 5
#define S2 6
#define S3 7
#define OUT 3

#define LED_R 12
#define LED_G 11
#define LED_B 13

int redValue, greenValue, blueValue;

void setup() {
  pinMode(LED_R, OUTPUT);
  pinMode(LED_G, OUTPUT);
  pinMode(LED_B, OUTPUT);

  digitalWrite(LED_R, LOW);
  digitalWrite(LED_G, LOW);
  digitalWrite(LED_B, LOW);

  pinMode(IR, INPUT);

  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(OUT, INPUT);

  digitalWrite(S0, HIGH);
  digitalWrite(S1, LOW);

  bras.attach(13);
  bras.write(90);

  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("System Ready");

  stepperMotor.setSpeed(10);
}

void loop() {

  stepperMotor.step(10);

  if (digitalRead(IR) == HIGH) {

    delay(500);

    readColor();

    lcd.clear();

    if (redValue < greenValue && redValue < blueValue) {
      lcd.print("ROUGE -> Bac A");
      trierObjet(30);
    }

    else if (greenValue < redValue && greenValue < blueValue) {
      lcd.print("VERT -> Bac B");
      trierObjet(90);
    }

    else {
      lcd.print("BLEU -> Bac C");
      trierObjet(150);
    }

    delay(500);


    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("En attente...");
  }
}

void trierObjet(int angle) {

  bras.write(angle);
  delay(1000);

  bras.write(90);
  delay(500);
}

void readColor() {

  digitalWrite(S2, LOW);
  digitalWrite(S3, LOW);
  redValue = pulseIn(OUT, LOW);

  digitalWrite(S2, HIGH);
  digitalWrite(S3, HIGH);
  greenValue = pulseIn(OUT, LOW);

  digitalWrite(S2, LOW);
  digitalWrite(S3, HIGH);
  blueValue = pulseIn(OUT, LOW);
}
