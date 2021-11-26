#include <Stepper.h>

Stepper motor1(2048, 8, 10, 9, 11);

int  contador= 0;
unsigned long tiempo = 0;

void setup() {

  motor1.setSpeed(3);
  tiempo = millis(); //se asigna a la variable el tiempo en ms
  Serial.begin(9600);
  Serial.println("Sistema activo");
      
}

void loop() {

  alarma_subida(20000);

}

void alarma_subida(unsigned long hora_alarma){
    unsigned long hora = hora_alarma;
    if(millis() == hora){
      Serial.println("se activo la alarma subida");
      activar_motor_subir();
    }

}

void activar_motor_subir(){

    Serial.println("el motor empieza a subir");
    while(contador<2){  //Controla la cantidad de vueltas

      tiempo = millis();

      vuelta_motor();

      contador++;
      Serial.println("vuelta numero:");
      Serial.println(contador);
      Serial.println("tiempo trancurrido:");
      Serial.println(millis()/1000);

    }
    contador=12;
    Serial.println("el motor termina de subir");
    
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

  digitalWrite(8, LOW); 
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
  
}
  
