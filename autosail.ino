
#include <Vela.h>
#include <Stepper.h>
Stepper motor1(2048, 8, 10, 9, 11);
Reloj r_subida;
Reloj r_bajada;
Vela vela1;
int vueltas_bajar=2;
int vueltas_subir=3;
int  contador= 0;
long tiempo_subida=3001;
long tiempo_bajada=90000;
unsigned long tiempo = 0;




void setup() {

  motor1.setSpeed(3);
  tiempo = millis(); //se asigna a la variable el tiempo en ms
  Serial.begin(9600);
  Serial.println("Sistema activo");
  r_subida.setHoras(0);
  r_subida.setMinutos(1);
  r_subida.setSegundos(0);

  r_bajada.setHoras(0);
  r_bajada.setMinutos(5);
  r_bajada.setSegundos(0);

  vela1.setHora_subida(r_subida);
  vela1.setHora_bajada(r_bajada);


}

void loop() {


  tiempo_subida=vela1.getHora_subida();
  tiempo_bajada=vela1.getHora_bajada();

  alarma_subida(tiempo_subida);

  alarma_bajada(tiempo_bajada);

}

void alarma_subida(unsigned long hora_alarma){
    unsigned long hora = hora_alarma;
    if(millis() == hora){
      Serial.println("se activo la alarma subida");
      Serial.println(hora);
      activar_motor_subir(vueltas_subir);
    }

}

void alarma_bajada(unsigned long hora_alarma){
    unsigned long hora = hora_alarma;
    if(millis() == hora){
      Serial.println("se activo la alarma bajada");
      activar_motor_bajar(vueltas_bajar);
    }

}

void activar_motor_subir(int vueltas){
    int num_vueltas=vueltas;
    contador=0;
    Serial.println("el motor empieza a subir");
    while(contador<num_vueltas){  //Controla la cantidad de vueltas

      tiempo = millis();

      vuelta_motor();

      contador++;
      Serial.println("vuelta numero:");
      Serial.println(contador);
      Serial.println("tiempo trancurrido:");
      Serial.println(millis()/1000);

    }
    //contador=num_vueltas+1;
    Serial.println("el motor termina de subir");


}

void activar_motor_bajar(int vueltas){

    contador=0;

    int num_vueltas=vueltas;

    Serial.println("el motor empieza a bajar");
    while(contador<num_vueltas){  //Controla la cantidad de vueltas

      tiempo = millis();

      vuelta_motor_negativa();

      contador++;
      Serial.println("vuelta numero:");
      Serial.println(contador);
      Serial.println("tiempo trancurrido:");
      Serial.println(millis()/1000);

    }
    //contador=num_vueltas+1;
    Serial.println("el motor termina de bajar");


}

void vuelta_motor(){

  motor1.step(2048);
  apagado_bobinas();

}

void vuelta_motor_negativa(){

    motor1.step(-2048);
    apagado_bobinas();

}

void apagado_bobinas(){

  digitalWrite(8, LOW); // detiene por 5 seg.
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);

}
