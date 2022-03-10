#ifndef PADRE_H_INCLUDED
#define PADRE_H_INCLUDED

#include "Auxiliar.h"


class Padre{

   int x,y;
   int dy;  //INCREMENTO.

   public:

       Padre(int _x,int _y,int _dy);
       int X(){return x;}
       int Y(){return y;}
       void dibujar();
       void mover();
       void borrar();
       void dialogoPadre();
       void dialogoPadreBorrar();
        //CONTROLO LA VELOCIDAD USANDO COMO CRITERIO EL MODULO DEL PUNTAJE.
};

Padre::Padre(int _x,int _y,int _dy):x(_x),y(_y),dy(_dy){}  //ARRANCARA SIEMPRE DE UNA POSICION FIJA.

void Padre::dibujar(){

     //CABEZA
     Auxiliar::gotoxy(x,y);printf("%c",124);
     Auxiliar::gotoxy(x,y+1);printf("%c",124);
     Auxiliar::gotoxy(x,y+2);printf("%c",124);
     Auxiliar::gotoxy(x+4,y);printf("%c",124);
     Auxiliar::gotoxy(x+4,y+1);printf("%c",124);
     Auxiliar::gotoxy(x+1,y-1);printf("%c",196);
     Auxiliar::gotoxy(x+2,y-1);printf("%c",196);
     Auxiliar::gotoxy(x+3,y-1);printf("%c",196);
     Auxiliar::gotoxy(x,y-1);printf("%c",218);
     Auxiliar::gotoxy(x+4,y-1);printf("%c",191);
     Auxiliar::gotoxy(x,y+2);printf("%c",192);
     Auxiliar::gotoxy(x+1,y+2);printf("%c",196);
     Auxiliar::gotoxy(x+2,y+2);printf("%c",196);
     Auxiliar::gotoxy(x+3,y+2);printf("%c",196);
     Auxiliar::gotoxy(x+4,y+2);printf("%c",217);


     //BOCA
     Auxiliar::gotoxy(x+2,y+1);printf("%c",196);
     Auxiliar::gotoxy(x+1,y+1);printf("%c",218);
     Auxiliar::gotoxy(x+3,y+1);printf("%c",191);

     //OJOS
     Auxiliar::gotoxy(x+1,y);printf("%c",126);
     Auxiliar::gotoxy(x+3,y);printf("%c",126);


     //CUERPO
     Auxiliar::gotoxy(x+2,y+3);printf("%c",193);

     //PIES
     Auxiliar::gotoxy(x+1,y+3);printf("%c",218);
     Auxiliar::gotoxy(x+3,y+3);printf("%c",191);

     //RUEDAS
     Auxiliar::gotoxy(x+1,y+4);printf("%c",184);
     Auxiliar::gotoxy(x+2,y+4);printf("%c",184);
     Auxiliar::gotoxy(x-1,y+3);printf("%c",184);
     Auxiliar::gotoxy(x,y+4);printf("%c",184);
     Auxiliar::gotoxy(x+3,y+4);printf("%c",184);
     Auxiliar::gotoxy(x+4,y+4);printf("%c",184);
     Auxiliar::gotoxy(x+5,y+3);printf("%c",184);

}

void Padre::mover(){

    borrar();
    y+=dy;   //AL VALOR ACTUAL DE LA COORDENADA y LE SUMO EL INCREMENTO DADO EN EL CONSTRUCTOR.
    dibujar();

    if(y+dy == 7 || y+dy == SCREEN_HEIGHT - 8){

        dy = -dy;
     }

}


void Padre::borrar(){

     //CABEZA
     Auxiliar::gotoxy(x,y);printf(" ");
     Auxiliar::gotoxy(x,y+1);printf(" ");
     Auxiliar::gotoxy(x,y+2);printf(" ");
     Auxiliar::gotoxy(x+4,y);printf(" ");
     Auxiliar::gotoxy(x+4,y+1);printf(" ");
     Auxiliar::gotoxy(x+1,y-1);printf(" ");
     Auxiliar::gotoxy(x+2,y-1);printf(" ");
     Auxiliar::gotoxy(x+3,y-1);printf(" ");
     Auxiliar::gotoxy(x,y-1);printf(" ");
     Auxiliar::gotoxy(x+4,y-1);printf(" ");
     Auxiliar::gotoxy(x,y+2);printf(" ");
     Auxiliar::gotoxy(x+1,y+2);printf(" ");
     Auxiliar::gotoxy(x+2,y+2);printf(" ");
     Auxiliar::gotoxy(x+3,y+2);printf(" ");
     Auxiliar::gotoxy(x+4,y+2);printf(" ");


     //BOCA
     Auxiliar::gotoxy(x+2,y+1);printf(" ");
     Auxiliar::gotoxy(x+1,y+1);printf(" ");
     Auxiliar::gotoxy(x+3,y+1);printf(" ");

     //OJOS
     Auxiliar::gotoxy(x+1,y);printf(" ");
     Auxiliar::gotoxy(x+3,y);printf(" ");


     //CUERPO
     Auxiliar::gotoxy(x+2,y+3);printf(" ");

     //PIES
     Auxiliar::gotoxy(x+1,y+3);printf(" ");
     Auxiliar::gotoxy(x+3,y+3);printf(" ");

     //RUEDAS
     Auxiliar::gotoxy(x+1,y+4);printf(" ");
     Auxiliar::gotoxy(x+2,y+4);printf(" ");
     Auxiliar::gotoxy(x-1,y+3);printf(" ");
     Auxiliar::gotoxy(x,y+4);printf(" ");
     Auxiliar::gotoxy(x+3,y+4);printf(" ");
     Auxiliar::gotoxy(x+4,y+4);printf(" ");
     Auxiliar::gotoxy(x+5,y+3);printf(" ");


}


void Padre::dialogoPadre(){

     Auxiliar::gotoxy(x - 1,y-3);printf("DEJA ESE CELULAR!!!");
}


void Padre::dialogoPadreBorrar(){

     Auxiliar::gotoxy(x - 1,y-3);printf("                   ");
}




#endif // PADRE_H_INCLUDED
