#include <TimeLib.h>

#include <SoftwareSerial.h>
#include <Stepper.h>

unsigned long previousTime = 0;
Stepper motor1(2048, 8, 10, 9, 11);
time_t nowTime = 0;
int hora = 1;
int minuto = 1;
int segundo = 1;
int dia = 1;
int mes = 1;
int ano = 1;
int vueltas_bajar = 3;
int vueltas_subir = 3;
bool subida = false;
bool bajada = false;
int  contador = 0;
int cont = 1;
long tiempo_subida = 1;
long tiempo_bajada = 1;

int hora_subida;
int min_subida;
int dia_subida;

int hora_bajada;
int min_bajada;
int dia_bajada;

unsigned long tiempo = 0;
SoftwareSerial miBT(7, 6);
char dato;
String data = "";

void setup() {

Serial.begin(9600);    // comunicacion de monitor serial a 9600 bps
Serial.println("Listo");  // escribe Listo en el monitor
miBT.begin(38400);    // comunicacion serie entre Arduino y el modulo a 38400 bps
motor1.setSpeed(3);
tiempo = millis(); //se asigna a la variable el tiempo en ms
Serial.begin(9600);
Serial.println("Sistema activo");


}

void loop() {

  actualizar_reloj();


if (miBT.available()>0) {      // si hay informacion disponible desde modulo
// lee Bluetooth y envia a monitor serial de Arduino
  dato = miBT.read();    // almacena en DATO el caracter recibido desde modulo
  data.concat(dato);


  if(data=="A"){
      Serial.println("Subir vela");
      activar_motor_subir(3);
      data="";
  }
  if(data=="B"){
      Serial.println("Bajar vela");
      activar_motor_bajar(3);
      data="";
  }


  if(dato == 'E'){ //hora subida
       Serial.println("Hora subida: ");
       Serial.println(data);
       String subida=data.substring(0, data.length() - 1);
       hora_subida=subida.toInt();
       data="";
     }

  if(dato == 'F'){ //min subida
      Serial.println("Minutos subida: ");
      String subida=data.substring(0, data.length() - 1);
      min_subida=subida.toInt();
      data="";
  }

  if(dato == 'G'){ //dia subida
       Serial.println("Dia subida: ");
       String subida=data.substring(0, data.length() - 1);
       dia_subida=subida.toInt();
       data="";
     }

  if(dato == 'I'){ //hora bajada
          Serial.println("Hora bajada: ");
          String bajada=data.substring(0, data.length() - 1);
          hora_bajada=bajada.toInt();
          data="";
        }
  if(dato == 'J'){ //min bajada
             Serial.println("Minutos bajada: ");
             String bajada=data.substring(0, data.length() - 1);
             min_bajada=bajada.toInt();
             data="";
           }
  if(dato == 'K'){ //Dia bajada
                Serial.println("Dia bajada: ");
                String bajada=data.substring(0, data.length() - 1);
                dia_bajada=bajada.toInt();
                data="";
              }


  if(dato == 'C'){




         Serial.println("Tiempo Subida: ");
         Serial.println(dia_subida);
         Serial.println(hora_subida);
         Serial.println(min_subida);
         alarma_subida(dia_subida,hora_subida,min_subida);


           Serial.println("Tiempo Bajada: ");
           Serial.println(dia_bajada);
           Serial.println(hora_bajada);
           Serial.println(min_bajada);
           alarma_bajada(dia_bajada,hora_bajada,min_bajada);




  data="";
}
  if(dato == 'h'){

      String hora_h=data.substring(0, data.length() - 1);
      hora = hora_h.toInt();
      setTime(hora,minuto,segundo,dia,mes,ano);
      Serial.println(hour(nowTime));
      Serial.println(minute(nowTime));
      Serial.println(second(nowTime));

      data="";

    }
  if(dato=='m'){

      String hora_m=data.substring(0, data.length() - 1);
      minuto = hora_m.toInt();
      setTime(hora,minuto,segundo,dia,mes,ano);
      Serial.println(hour(nowTime));
      Serial.println(minute(nowTime));
      Serial.println(second(nowTime));

      data="";


    }
  if(dato=='s'){

      String hora_s=data.substring(0, data.length() - 1);
      segundo = hora_s.toInt();
      setTime(hora,minuto,segundo,dia,mes,ano);
      Serial.println(hour(nowTime));
      Serial.println(minute(nowTime));
      Serial.println(second(nowTime));

      data="";


    }
  if(dato=='D'){

      String hora_d=data.substring(0, data.length() - 1);
      dia = hora_d.toInt();
      setTime(hora,minuto,segundo,dia,mes,ano);
      Serial.println(hour(nowTime));
      Serial.println(minute(nowTime));
      Serial.println(second(nowTime));

      data="";


    }
  if(dato=='M'){
        String hora_M=data.substring(0, data.length() - 1);
      mes = hora_M.toInt();
      setTime(hora,minuto,segundo,dia,mes,ano);
      Serial.println(hour(nowTime));
      Serial.println(minute(nowTime));
      Serial.println(second(nowTime));

      data="";

    }
  if(dato=='Y'){
      String hora_Y=data.substring(0, data.length() - 1);
      ano = hora_Y.toInt();
      setTime(hora,minuto,segundo,dia,mes,ano);
      Serial.println(hour(nowTime));
      Serial.println(minute(nowTime));
      Serial.println(second(nowTime));

      data="";

    }

  actualizar_reloj();
}


}

void actualizar_reloj(){

  if (millis() >= (previousTime))
  {
     previousTime = previousTime + 1000;  // use 100000 for uS
     segundo = segundo +1;
     if (segundo == 60)
     {
      Serial.println("HORA:");
  Serial.println(hour(nowTime));
  Serial.println("MIN");
  Serial.println(minute(nowTime));
  Serial.println("SEG");
  Serial.println(second(nowTime));

        segundo = 0;
        minuto = minuto +1;
     }
     if (minuto == 60)
     {
        minuto = 0;
        hora = hora +1;
     }
     if (hora == 24)
     {
       hora = 0;
       dia+1;
     }

  }
setTime(hora,minuto,segundo,dia,mes,ano);
}

void alarma_subida(int dia_subida,int hora_subida, int min_subida) {

  if(dia_subida==day(nowTime)&&hora_subida==hour(nowTime)&&min_subida==minute(nowTime)){

    Serial.println("se activo la alarma subida");

    int i=0;
    while(i<1){

      activar_motor_subir(vueltas_subir);
      i++;
    }
  }
}

void alarma_bajada(int dia_bajada,int hora_bajada, int min_bajada) {

  if(dia_bajada==day(nowTime)&&hora_bajada==hour(nowTime)&&min_bajada==minute(nowTime)){

    Serial.println("se activo la alarma bajada");

    int i=0;
    while(i<1){

      activar_motor_subir(vueltas_bajar);
      i++;
    }
  }
}



void activar_motor_subir(int vueltas) {
 int num_vueltas = vueltas;
 contador = 0;
 Serial.println("el motor empieza a subir");
 while (contador < num_vueltas) { //Controla la cantidad de vueltas

   tiempo = millis();
   vuelta_motor();
   contador++;
   Serial.println("vuelta numero:");
   Serial.println(contador);
   Serial.println("tiempo trancurrido:");
   Serial.println(millis() / 1000);

 }

 Serial.println("el motor termina de subir");

}

void activar_motor_bajar(int vueltas) {

 contador = 0;
 int num_vueltas = vueltas;
 Serial.println("el motor empieza a bajar");
 while (contador < num_vueltas) { //Controla la cantidad de vueltas

   tiempo = millis();
   vuelta_motor_negativa();
   contador++;
   Serial.println("vuelta numero:");
   Serial.println(contador);
   Serial.println("tiempo trancurrido:");
   Serial.println(millis() / 1000);

 }

 Serial.println("el motor termina de bajar");

}

void vuelta_motor() {

  motor1.step(2048);
  actualizar_reloj();
    apagado_bobinas();

}

void vuelta_motor_negativa() {

 motor1.step(-2048);
 actualizar_reloj();
 apagado_bobinas();

}


void apagado_bobinas() {

 digitalWrite(8, LOW); // detiene por 5 seg.
 digitalWrite(9, LOW);
 digitalWrite(10, LOW);
 digitalWrite(11, LOW);

}
