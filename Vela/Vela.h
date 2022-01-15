
#include "Reloj.h"


class Vela {

  Reloj hora_subida;
  Reloj hora_bajada;
  bool bajar;

  public: //Miembros públicos
    void setHora_subida(Reloj h_subida); //Método Set
    void setHora_bajada(Reloj h_bajada);
    void setBajar(bool b); //Método Set
    unsigned long getHora_subida();
    unsigned long getHora_bajada();
    bool getBajar();
};

void Vela::setHora_subida(Reloj h_subida){
	hora_subida = h_subida;
}

void Vela::setHora_bajada(Reloj h_bajada){
	hora_bajada = h_bajada;
}

void Vela::setBajar(bool b){
	bajar = b;
}

unsigned long Vela::getHora_subida(){
  return hora_subida.conv_a_mili();
}

unsigned long Vela::getHora_bajada(){
  return hora_bajada.conv_a_mili();
}
bool Vela::getBajar(){
  return bajar;
}
