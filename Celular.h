#ifndef CELULAR_H_INCLUDED
#define CELULAR_H_INCLUDED

#include "Auxiliar.h"
#include "Hijo.h"


class Celular{

      int x,y;


    public:

      Celular(int _x,int _y);
      int X(){return x;}
      int Y(){return y;}
      void dibujar();
      void borrar();
      bool colisionoHijo(Hijo&);

};


Celular::Celular(int _x,int _y):x(_x),y(_y){}


void Celular::dibujar(){


    Auxiliar::gotoxy(x,y);printf("%c",219);
    Auxiliar::gotoxy(x-1,y);printf("%c",179);
    Auxiliar::gotoxy(x-1,y-1);printf("%c",218);
    Auxiliar::gotoxy(x-1,y+1);printf("%c",192);
    Auxiliar::gotoxy(x+1,y);printf("%c",179);
    Auxiliar::gotoxy(x+1,y-1);printf("%c",191);
    Auxiliar::gotoxy(x+1,y+1);printf("%c",217);
    Auxiliar::gotoxy(x,y+1);printf("%c",167);
    Auxiliar::gotoxy(x,y-1);printf("%c",196);

}


void Celular::borrar(){

    Auxiliar::gotoxy(x,y);printf("   ");  //PONGO TANTOS CARACTERES EN BLANCO NECESITE PARA CUBRIR EL ANCHO QUE QUIERO BORRAR(EL ANCHO DE LA NAVE).
    Auxiliar::gotoxy(x-1,y-1);printf("   ");
    Auxiliar::gotoxy(x-1,y+1);printf("   ");
    Auxiliar::gotoxy(x-1,y);printf("   ");
}



bool Celular::colisionoHijo(Hijo& hijo){


    if((x == hijo.X() + 1 && y == hijo.Y()) || (x == hijo.X() - 1 && y == hijo.Y()) || (x == hijo.X() && y == hijo.Y() + 1) || (x == hijo.X() && y == hijo.Y() - 1)){

        //Sleep(1000);
        return true;

    }

    return false;
}



#endif // CELULAR_H_INCLUDED
