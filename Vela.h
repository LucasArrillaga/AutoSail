
#include "Reloj.h"
#include <iostream>

class Vela {

  Reloj hora_subida;
  Reloj hora_bajada;
  bool bajar;

  public: //Miembros públicos
    void setHora_subida(Reloj h_subida); //Método Set
    void Vela::setHora_bajada(Reloj h_bajada);
    void Vela::setBajar(bool b); //Método Set
    unsigned long Vela::getHora_subida();
    unsigned long Vela::getHora_bajada();
    bool Vela::getBajar();
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

