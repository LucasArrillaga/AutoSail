#include <SoftwareSerial.h>
#include <Stepper.h>
Stepper motor1(2048, 8, 10, 9, 11);
int vueltas_bajar = 2;
int vueltas_subir = 3;
bool baja;
int  contador = 0;
int cont = 1;
long tiempo_subida = 1;
long tiempo_bajada = 1;
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

if (miBT.available()>0) {      // si hay informacion disponible desde modulo
// lee Bluetooth y envia a monitor serial de Arduino
dato = miBT.read();    // almacena en DATO el caracter recibido desde modulo
data.concat(dato);
if (dato == 'X')
       {
           Serial.println("Received: ");
           Serial.println(data);
           if(data=="AX"){
               Serial.println("Subir vela");
               activar_motor_subir(1);
               data="";
             }
             if(data=="BX"){
               Serial.println("Bajar vela");
               activar_motor_bajar(1);
               data="";
             }
           data="";
         }
   if(dato == 'S'){
       Serial.println("Tiempo Subida: ");
       Serial.println(data);
       String subida=data.substring(0, data.length() - 1);
       tiempo_subida=subida.toInt();
       Serial.println(tiempo_subida);
       //alarma_subida(tiempo_subida+millis());
       data="";
     }
    if(dato == 'B'){

       Serial.println("Tiempo Bajada: ");
       Serial.println(data);
       String bajada=data.substring(0, data.length() - 1);
       tiempo_bajada=bajada.toInt();
       Serial.println(tiempo_bajada);
       //alarma_bajada(tiempo_bajada+millis());
       data="";

     }

      if(dato == 'C'){


      if(tiempo_subida>15000){

         Serial.println("Tiempo Subida: ");
         Serial.println(tiempo_subida);
         alarma_subida(tiempo_subida);
      
        if(tiempo_bajada>50000){
           Serial.println("Tiempo Bajada: ");
           Serial.println(tiempo_bajada);
           alarma_bajada(tiempo_bajada);
       }
       else
         Serial.println("Error en el tiempo de bajada");
     }else
       Serial.println("Error en el tiempo de subida");
      
  data="";
}

}
}
void alarma_subida(unsigned long hora_alarma) {

 Serial.println("se activo la alarma subida");
 unsigned long hora = hora_alarma;
 Serial.println(hora);
 Serial.println(millis());
 int i=0;
 while(i<1){

   if (millis() == hora) {

     Serial.println(hora);
     activar_motor_subir(vueltas_subir);
     i++;

   }

 }


}


void alarma_bajada(unsigned long hora_alarma) {

  unsigned long hora = hora_alarma;
  Serial.println(hora);
  Serial.println(millis());
  int i=0;
  while(i<1){
   if (millis() == hora) {
     Serial.println("se activo la alarma bajada");
     activar_motor_bajar(vueltas_bajar);
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
  apagado_bobinas();

}

void vuelta_motor_negativa() {

 motor1.step(-2048);
 apagado_bobinas();

}


void apagado_bobinas() {

 digitalWrite(8, LOW); // detiene por 5 seg.
 digitalWrite(9, LOW);
 digitalWrite(10, LOW);
 digitalWrite(11, LOW);

}
