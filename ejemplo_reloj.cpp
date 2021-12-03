
#include <iostream>
#include "Vela.h"
using namespace std;
#include <sstream>



int main(){

  Reloj r_subida;
  Reloj r_bajada;
  Vela vela;

  r_subida.setHoras(0);
  r_subida.setMinutos(1);
  r_subida.setSegundos(1);

  r_bajada.setHoras(5);
  r_bajada.setMinutos(30);
  r_bajada.setSegundos(0);

  vela.setHora_subida(r_subida);
  vela.setHora_bajada(r_bajada);

  unsigned long n=vela.getHora_subida(); //number to be converted
    stringstream temp_str;
    temp_str<<n; //passing number to the stream
 
    char const *number_array = temp_str.str().c_str();//converting to char array
 
    cout<<"Number converted to char array is: ";
    cout<<number_array[0];
    cout<<number_array[1];
    cout<<number_array[2];
    cout<<number_array[3];
    cout<<number_array[4];
    cout<<number_array[5];
    cout<<number_array[6];

return 0;

}
