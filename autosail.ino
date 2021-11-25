int  contado= 0;
unsigned long tiempo = 0;

int IN1 = 8;      // pin digital 8 de Arduino a IN1 de modulo controlador
int IN2 = 9;      // pin digital 9 de Arduino a IN2 de modulo controlador
int IN3 = 10;     // pin digital 10 de Arduino a IN3 de modulo controlador
int IN4 = 11;     // pin digital 11 de Arduino a IN4 de modulo controlador
int demora = 11;      // demora entre pasos, no debe ser menor a 10 ms.
// paso completo con maximo torque
int paso [4][4] =   // matriz (array bidimensional) con la secuencia de pasos
{
  {1, 1, 0, 0},
  {0, 1, 1, 0},
  {0, 0, 1, 1},
  {1, 0, 0, 1}
};

void setup() {

 tiempo = millis(); //se asigna a la variable el tiempo en ms

 pinMode(IN1, OUTPUT);    // todos los pines como salida
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

    Serial.begin(9600);
      Serial.println("Sistema activo
      

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
    while(contador<10){  //Controla la cantidad de vueltas

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

   for (int i = 0; i < 512; i++)  // 512*4 = 2048 pasos
  {
    for (int i = 0; i < 4; i++)   // bucle recorre la matriz de a una fila por vez
    {         // para obtener los valores logicos a aplicar
      digitalWrite(IN1, paso[i][0]);  // a IN1, IN2, IN3 e IN4
      digitalWrite(IN2, paso[i][1]);
      digitalWrite(IN3, paso[i][2]);
      digitalWrite(IN4, paso[i][3]);
      delay(demora);
    }
  }

  digitalWrite(IN1, LOW); // detiene por 5 seg.
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  //delay(1000);

  }
