
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
};

void Reloj::setHoras(int hora_reloj)
{
	horas = hora_reloj;
}

void Reloj::setMinutos(int minuto_reloj)
{
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
