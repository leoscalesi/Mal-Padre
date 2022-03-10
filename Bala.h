#ifndef BALA_H_INCLUDED
#define BALA_H_INCLUDED


#include "Hijo.h"


class Bala{

    int x,y;

  public:

      Bala(int _x,int _y);
      int X(){ return x;}   //PARA ACCEDER A ESTOS ATRIBUTOS DESDE EL PADRE.
      int Y(){ return y;}
      void mover();
      bool detectaLimiteDerechoBala();
      //void colision(Hijo&);
      //void aumentaVelocidad(); //CONTROLO LA VELOCIDAD USANDO COMO CRITERIO EL MODULO DEL PUNTAJE.
      //void mover(int);

};


Bala::Bala(int _x,int _y): x(_x),y(_y){}


void Bala::mover(){

      gotoxy(x,y); printf(" ");   //LO PRIMERO QUE HAGO ES BORRAR

      //if(y > 4) y--;    //PERMITO QUE SIGA SUBIENDO SI NO SOBREPASA EL LIMITE SUPERIOR
      //PERO AL AGREGAR EL METODO detectaLimiteSuperiorBala() SE PUEDE OMITIR ESE if Y QUEDARIA SOLO:

      x++;

      //DIBUJO LA BALA
      gotoxy(x,y); printf("%c",223);

}


//DETECTA SI LA BALA LLEGO O NO AL LIMITE SUPERIOR
bool Bala::detectaLimiteDerechoBala(){

     if(x == SCREEN_WIDTH - 2)return true;
     return false;
}

/*
void Bala::colision(Hijo& hijo){



    if(x == hijo.X()){    //CONDICION QUE EVALUA TENIENDO EN CUENTA EL TAMAÑO DE LA NAVE CUANDO HAY COLISION CON EL ASTEROIDE

          //Sleep(2000);
          hijo.morir();

    }



}

*/

/*
void Bala::aumentaVelocidad(){


      gotoxy(x,y); printf(" ");   //LO PRIMERO QUE HAGO ES BORRAR

      //if(y > 4) y--;    //PERMITO QUE SIGA SUBIENDO SI NO SOBREPASA EL LIMITE SUPERIOR
      //PERO AL AGREGAR EL METODO detectaLimiteSuperiorBala() SE PUEDE OMITIR ESE if Y QUEDARIA SOLO:

      x = x*2;

      //DIBUJO LA BALA
      gotoxy(x,y); printf("%c",223);

}
*/
/*
void Bala::mover(int aumento){

      gotoxy(x,y); printf(" ");   //LO PRIMERO QUE HAGO ES BORRAR

      //if(y > 4) y--;    //PERMITO QUE SIGA SUBIENDO SI NO SOBREPASA EL LIMITE SUPERIOR
      //PERO AL AGREGAR EL METODO detectaLimiteSuperiorBala() SE PUEDE OMITIR ESE if Y QUEDARIA SOLO:

      x += aumento;

      //DIBUJO LA BALA
      gotoxy(x,y); printf("%c",223);

}
*/

#endif // BALA_H_INCLUDED
