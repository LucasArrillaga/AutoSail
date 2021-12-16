#ifndef _RELOJ
#define _RELOJ
class Reloj {

  int horas;
  int minutos;
  int segundos;

  public: //Miembros públicos 
  	void setHoras(int hora_reloj); //Método Set
    void setMinutos(int minuto_reloj); //Método Set
    void setSegundos(int segundo_reloj); //Método Set
  	int getHoras(void); //Método Get
    int getMinutos(void); //Método Get
    int getSegundos(void); //Método Get
    unsigned long conv_a_mili(void); // metodo para convertir a milisegundos
};
#include  ″Reloj.c″
#endif






void Reloj::setHoras(int hora_reloj){
	horas = hora_reloj;
}

void Reloj::setMinutos(int minuto_reloj){
    minutos = minuto_reloj;
}

void Reloj::setSegundos(int segundo_reloj) {
  segundos = segundo_reloj;
}

int Reloj::getHoras() {
  return horas;
}

int Reloj::getMinutos() {
  return minutos;
}

int Reloj::getSegundos() {
  return segundos;
}

unsigned long Reloj::conv_a_mili(){
//convertir la hora a milisegundos
  unsigned long hora_mili;
  hora_mili=horas* 3.6e+6;

  //convertir minutos a milis
  unsigned long min_mili;
  min_mili=minutos*60000;

//convertir segundos en milisegundos
unsigned long seg_mili;
seg_mili=segundos*1000;

//sumar hora, minutos y segundos en milisegundos
unsigned long total_mili;
total_mili = hora_mili+min_mili+seg_mili;

return total_mili;


}
