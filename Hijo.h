#ifndef HIJO_H_INCLUDED
#define HIJO_H_INCLUDED


#include "Auxiliar.h"
#include <conio.h>    //AQUI SE ENCUENTRA kbhit()


//MACROS QUE DEFINEN QUE NUMERO LE CORRESPONDE A CADA TECLA

#define ARRIBA 72
#define IZQUIERDA 75
#define DERECHA 77
#define ABAJO 80



class Hijo{

   int x,y;
   int puntos;

   public:

       Hijo(int _x,int _y,int _puntos);
       int X(){return x;}
       int Y(){return y;}
       void dibujar();
       void mover();
       void borrar();
       void morir();
       void pintarPuntaje(int,int,int);
       void actualizarPuntaje(int,int,int);
       void dialogoHijo();
       void dialogoHijoBorrar();

};

Hijo::Hijo(int _x,int _y,int _puntos):x(_x),y(_y),puntos(_puntos){}  //ARRANCARA SIEMPRE DE UNA POSICION FIJA.

void Hijo::dibujar(){

     //CUERPO
     Auxiliar::gotoxy(x,y);printf("%c",178);

     //CABEZA
     Auxiliar::gotoxy(x,y-1);printf("%c",1);

     //PIERNA
     Auxiliar::gotoxy(x,y+1);printf("%c",94);

     Auxiliar::gotoxy(x-1,y);printf("%c",174);
     Auxiliar::gotoxy(x+1,y);printf("%c",175);


}


void Hijo::borrar(){

      //CUERPO
     Auxiliar::gotoxy(x,y);printf(" ");

     //CABEZA
     Auxiliar::gotoxy(x,y-1);printf(" ");

     //PIERNA
     Auxiliar::gotoxy(x,y+1);printf(" ");

     Auxiliar::gotoxy(x-1,y);printf(" ");
     Auxiliar::gotoxy(x+1,y);printf(" ");

}



void Hijo::mover(){


      if(kbhit()){   //DETECTA SI SE PRESIONO ALGUNA TECLA CUALQUIERA DEL TECLADO.

            char tecla = getch();   //ME DICE Y GUARDA QUE TECLA SE PRESIONO.
            borrar();
            if(tecla == IZQUIERDA && x > 20) x--;   //QUE NO SE MUEVA A LA IZQUIERDA TAN CERCA DEL PADRE, TENERLO EN CUENTA PARA LA APARICION AL AZAR DE LOS CELULARES.
            if(tecla == DERECHA && x < SCREEN_WIDTH - 3) x++;
            if(tecla == ARRIBA && y > 5) y--;
            if(tecla == ABAJO && y < SCREEN_HEIGHT - 6) y++;

            dibujar();
      }
}


//ACA ESTA LA ANIMACION DE LA MUERTE.

void Hijo::morir(){

     borrar();
     Sleep(300);
     Auxiliar::gotoxy(x - 8,y - 3);printf("MAL PADRRREEEEE!!!");

     //CUERPO
     Auxiliar::gotoxy(x,y);printf("%c",35);

     //CABEZA
     Auxiliar::gotoxy(x,y-1);printf("%c",42);

     //PIERNA
     Auxiliar::gotoxy(x,y+1);printf("%c",35);


     Sleep(300);


    //CUERPO
     Auxiliar::gotoxy(x,y);printf(" ");

    //CABEZA
     Auxiliar::gotoxy(x,y-1);printf(" ");

     //PIERNA
     Auxiliar::gotoxy(x,y+1);printf(" ");

     dibujar();
}


void Hijo::pintarPuntaje(int p,int x,int y){

     Auxiliar::gotoxy(x,y); printf("Puntaje %d",p);
}



void Hijo::actualizarPuntaje(int p,int x,int y){

    pintarPuntaje(p,x,y);
}


void Hijo::dialogoHijo(){

   Auxiliar::gotoxy(x - 2,y-3);printf("NO!!!");
}


void Hijo::dialogoHijoBorrar(){

   Auxiliar::gotoxy(x - 2,y-3);printf("     ");
}


#endif // HIJO_H_INCLUDED
