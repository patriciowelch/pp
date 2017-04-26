#include <DCMotor.h>
#include <NewPing.h>
#include <Servo.h>

//robogroup

DCMotor motor_izq(M0_EN, M0_D0, M0_D1);
DCMotor motor_der(M1_EN, M1_D0, M1_D1);

//robot line 2016

/*DCMotor motor_izq (6, 28, 29);
 DCMotor motor_der (5, 30, 31);*/

NewPing ultra(17,17,200);
Servo myservo;

//estados

#define seguidor 1

#define izq 0
#define der 1

//pines

#define PIN_S_DEL 1
#define PIN_S_DER 2
#define PIN_S_IZQ 3

//variables de calibracion

int IZQ_N;
int DER_N;
int DEL_N;

int estado = seguidor;
int mariano;

//prioridad

int prioridad = izq;

////////////////////////////////////////////////////////////

void setup()
{

}

void loop()
{
  if(estado == seguidor)
  {
    seguir_linea();
  }
}

void calibrador()
{
  int s_izq = analogRead(PIN_S_IZQ);
  int s_der = analogRead(PIN_S_DER);
  int s_del = analogRead(PIN_S_DEL);

  IZQ_N = abs((s_izq + s_del)/2);
  DER_N = abs((s_der + s_del)/2);
  DEL_N = abs((s_izq + s_der + s_del)/3);
}

void motores(int vel1, int vel2)
{
  motor_izq.setSpeed(vel1);
  motor_der.setSpeed(vel2);
}

//que onda
