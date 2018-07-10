#include <Servo.h>

// Configuración de pines
#define SONAR_TRIGGER_PIN 8
#define SONAR_ECHO_PIN 9
#define SERVO_HORIZONTAL 10
#define SERVO_VERTICAL 11
#define BOTON_BLANCO 12
#define BOTON_ROJO 13

#define SONAR_DISTANCIA_MAXIMA 200 // centímetros

Servo Horizontal;
Servo Vertical;

int posHorizontal;
int posVertical;
bool vueltaHorizontal = false;
bool vueltaVertical = false;

void setup() {
  pinMode(BOTON_ROJO, INPUT);
  pinMode(BOTON_BLANCO, INPUT);

  Horizontal.attach(SERVO_HORIZONTAL);
  Vertical.attach(SERVO_VERTICAL);

  posHorizontal = Horizontal.read();
  posVertical = Vertical.read();
}

void loop() {
  if (digitalRead(BOTON_ROJO)) {
    mueveServo(Horizontal, posHorizontal, vueltaHorizontal);
    delay(15);
  }
  if (digitalRead(BOTON_BLANCO)) {
    mueveServo(Vertical, posVertical, vueltaVertical);
    delay(15);
  }
}

void mueveServo(Servo servo, int &posicion, bool &vuelta) {
  if (posicion == 0 || posicion == 180) {
    vuelta = posicion == 0;
    delay(500);
  }
  if (vuelta) {
    posicion++;
  } else {
    posicion--;
  }
  servo.write(posicion);
}

