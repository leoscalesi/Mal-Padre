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



#endif // BALA_H_INCLUDED
