#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include <cstdlib>
#include "Juego.h"


class Menu{

  public:

    //LA CLASE MENU NO NECESITA CONSERVAR NINGUN ESTADO INTERNO, DE MANERA QUE NO NECESITO INSTANCIAR OBJETOS DE DICHA CLASE, POR ESO USO static SUS METODOS.
    static void mostrar();

};


void Menu::mostrar(){

    bool salir=0;
    int opc;

   while(salir==0){

      cout << " ---------------------------- " << endl;
      cout << " MAL PADREEEEEEEE!!!!!! " << endl << endl;
      cout << endl << endl << endl << endl << endl;
      cout << " 1 - JUGAR " << endl;
      cout  << endl << endl;
      cout << " 0 - SALIR DEL PROGRAMA " << endl << endl << endl;
      cout << " ---------------------------- " << endl;
      cout << " INGRESE OPCION: ";
      cin >> opc;

      system("cls");

      switch(opc){

      case 1:

        Juego::jugar();

      break;

      case 0:

        salir = 1;

      break;

      }
    }
}



#endif // MENU_H_INCLUDED
