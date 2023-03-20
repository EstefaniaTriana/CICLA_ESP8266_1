#include <ESP8266WiFi.h>
#include <Arduino.h> // Agregamos la librería Arduino.h

int led_izquierda = 3;  
int led_derecha = 4; 
int led_freno = 2;
//Botones 
int BotonDerecha = 13;//5 
int BotonIzquierda = 12;
int BotonFreno = 5;
//Estados de los botones 1(derecha) 2(izquierda) 3(freno)
int EstadoActual1 = 0;
int EstadoActual2 = 0;
int EstadoActual3 = 0;
//Ultimo Estado
int UltimoEstado1 = 0; 
int UltimoEstado2 = 0;
int UltimoEstado3 = 0;
//Estado botones 
bool EstadoPresionado1 = false;
bool EstadoPresionado2 = false;
bool EstadoPresionado3 = false;

void setup() {
  //Leds
  pinMode(led_izquierda, OUTPUT);
  pinMode(led_derecha, OUTPUT);
  pinMode(led_freno, OUTPUT);

  //Botones
  pinMode(BotonDerecha, INPUT);
  pinMode(BotonIzquierda, INPUT);
  pinMode(BotonFreno, INPUT);
}

void loop() {
  // Botón derecha
  EstadoActual1 = digitalRead(BotonDerecha);
  if (EstadoActual1 != UltimoEstado1) {
    if (digitalRead(BotonDerecha) == HIGH) {
      if (!EstadoPresionado1) {
        EstadoPresionado1 = !EstadoPresionado1;
        digitalWrite(led_derecha, HIGH);
        digitalWrite(led_izquierda, LOW);
        digitalWrite(led_freno, LOW);
        EstadoPresionado2 = false;
        EstadoPresionado3 = false;
        
      } else {
        EstadoPresionado1 = false;
        digitalWrite(led_derecha, LOW);
      }
    }
  }
  UltimoEstado1 = EstadoActual1;

  // Botón izquierda
  EstadoActual2 = digitalRead(BotonIzquierda);
  if (EstadoActual2 != UltimoEstado2) {
    if (digitalRead(BotonIzquierda) == HIGH) {
      if (!EstadoPresionado2) {
        EstadoPresionado2 = !EstadoPresionado2;
        digitalWrite(led_izquierda, HIGH);
        /*if(digitalRead(BotonDerecha) == HIGH){
          EstadoActual1 = digitalRead(BotonDerecha);
          digitalWrite(led_derecha, LOW);

          EstadoPresionado1 = !EstadoPresionado1;
          UltimoEstado1 = EstadoActual1;
        }
        if(digitalRead(BotonFreno) == HIGH){
          EstadoActual3 = digitalRead(BotonFreno);
          digitalWrite(led_freno, LOW);
          EstadoPresionado3 = !EstadoPresionado3;
          UltimoEstado3 = EstadoActual3;
        }*/
        digitalWrite(led_derecha, LOW);
        digitalWrite(led_freno, LOW);
        EstadoPresionado1 = false;
        EstadoPresionado3 = false;
      } else {
        EstadoPresionado2 = false;
        digitalWrite(led_izquierda, LOW);
      }
    }
  }
  UltimoEstado2 = EstadoActual2;


//Freno
EstadoActual3 = digitalRead(BotonFreno);
  if (EstadoActual3 != UltimoEstado3) {
    if (digitalRead(BotonFreno) == HIGH) {
      if (!EstadoPresionado3) {
        EstadoPresionado3 = !EstadoPresionado3;
        digitalWrite(led_freno, HIGH);
        /*if(digitalRead(BotonIzquierda) == HIGH){
          digitalWrite(led_izquierda, LOW);
          EstadoPresionado2 = !EstadoPresionado2;
          UltimoEstado2 = EstadoActual2;
        }
        if(digitalRead(BotonDerecha) == HIGH){
          digitalWrite(led_derecha, LOW);
          EstadoPresionado1 = !EstadoPresionado1;
          UltimoEstado1 = EstadoActual1;
        }*/
        digitalWrite(led_derecha, LOW);
        digitalWrite(led_izquierda, LOW);
        EstadoPresionado1 = false;
        EstadoPresionado2 = false;
      } else {
        EstadoPresionado3 = false;
        digitalWrite(led_freno, LOW);
      }
    }
  }
  UltimoEstado3 = EstadoActual3;
}
