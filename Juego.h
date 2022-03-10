#ifndef JUEGO_H_INCLUDED
#define JUEGO_H_INCLUDED

#include <cstdlib>
#include <ctime>
#include <list>
#include "rlutil.h"
#include "Celular.h"
#include "Auxiliar.h"
#include "Padre.h"
#include "Hijo.h"
#include "Bala.h"


class Juego{

public:

    static void jugar();

};

void Juego::jugar(){

    Auxiliar::ocultarCursor();
    Auxiliar::pintarLimites();
    bool gameover = false;

    srand(time( NULL ));  //SEMILLA PARA QUE EL CELULAR ARRANQUE EN LUGARES DISTINTOS CADA VEZ QUE EMPIEZA NUEVAMENTE EL JUEGO.



    //CREO UN OBJETO LISTA PARA LAS BALAS, CON PUNTEROS A BALA,PARA FACILITAR LA CREACION DE OBJETOS CON EL OPERADOR new.
    list<Bala*> Balas;
    //CREO UN ITERADOR PARA RECORRER LA LISTA.
    list<Bala*>::iterator it;


    //DE LA MISMA MANERA QUE PARA LAS BALAS,CREO UNA LISTA PARA LOS CELULARES.
    list<Celular*> Celulares;
    //CREO UN ITERADOR PARA RECORRER LA LISTA.
    list<Celular*>::iterator cit;


    Padre padre(10,10,1);
    padre.dibujar();

    int puntaje = 0;

    Hijo hijo(SCREEN_WIDTH/2,SCREEN_HEIGHT/2,0);
    hijo.dibujar();
    hijo.pintarPuntaje(puntaje,80,2);

    Bala bala(15,15);

    int cont = 0;
    int aumento = 10;


    while(!gameover){


          hijo.mover();

          if(cont%7 == 0 && cont%3 == 0){ // MEJORAR ESTA CONDICION PARA QUE SEA AL AZAR EL DISPARO.

               Balas.push_back(new Bala(padre.X() + 6,padre.Y() + 4));  //AGREGA UNA BALA A LA LISTA, EN LA MISMA POSICION EN LA QUE ESTA EL PADRE EN ESE MOMENTO, SUMANDO EN X 2 PARA QUE SALGA DEL MEDIO DE LA NAVE, Y RESTANDO 1 EN Y PARA QUE PAREZCA QUE LA BALA SALE DE LA NAVE).

           }




          //RECORREMOS LA LISTA DESDE EL PRINCIPIO HASTA EL FINAL MOVIENDO A CADA BALA, DEBIDO QUE PASO PUNTEROS A OBJETOS, DEBO LLAMAR AL METODO CON EL OPERADOR FLECHA, Y COMO QUIERO EL CONTENIDO DERREFERENCIO EL PUNTERO AL LLAMAR AL METODO.
          //***********************************************************************************************************************************

          for(it = Balas.begin();it != Balas.end();it++){


               (*it)->mover();

               //AHORA CONTROLO SI LA BALA LLEGO AL LIMITE SUPERIOR

               if((*it)->detectaLimiteDerechoBala()){    //SI DA true DEBO ELIMINAR LA BALA SEGUN LA CONDICION DENTRO DE ESTE METODO.

                    //BORRO LA BALA PRIMERO SITUANDOME EN LAS COORDENADAS DE LA BALA.

                    gotoxy((*it)->X(),(*it)->Y()); printf(" ");  //LA BALA ATRAVIESA EL LIMITE, DERECHO Y SE ROMPE EL JUEGO, PORQUE DEBO ELIMINAR FISICAMENTE DE LA LISTA A LA BALA.
                    delete(*it);  //SI DEJO SOLO EL delete EL ITERADOR DE LA LISTA SE INVALIDA, Y ROMPE EL JUEGO
                    //ENTONCES DEBO USAR EL METODO erase DE list(QUE SE ENCARGA DE RETORNAR UN PUNTERO A LA NUEVA LOCACION DEL ELEMENTO QUE SIGUE AL ULTIMO ELEMENTO BORRADO EN LA LISTA) YA SI NO PERDER EL HILO DE LA ITERACION.
                    it = Balas.erase(it);
               }

          }
          //***********************************************************************************************************************************






          //APARICION CELULARES Y COLISION HIJO. DIALOGO PADRE HIJO.
          //------------------------------------------------------------------------------------------------------------------------------------



          if(cont == 1){   //PARA QUE APAREZCA EL PRIMER CELU APENAS ARRANCA EL JUEGO.

              Celulares.push_back(new Celular(rand()% (SCREEN_WIDTH - 23 - 2) + 23,rand()% (SCREEN_HEIGHT - 7 - 6) + 7));
          }




          for(cit = Celulares.begin();cit != Celulares.end();cit++){

               (*cit)->dibujar();

               if((*cit)->colisionoHijo(hijo)){  //SI EL HIJO AGARRA EL CELU, LO ELIMINO DE LA LISTA, Y CREO OTRO QUE DEBERA APARECER INMEDIATAMENTE.

                    puntaje += 5;
                    hijo.actualizarPuntaje(puntaje,80,2);
                    (*cit)->borrar();
                    delete(*cit);
                    cit = Celulares.erase(cit);

                    Celulares.push_back(new Celular(rand()% (SCREEN_WIDTH - 23 - 2) + 23,rand()% (SCREEN_HEIGHT - 7 - 6) + 7));

                    if(cont%2 == 0){  // PARA QUE NO SIEMPRE DIALOGUEN.
                        padre.dialogoPadre();
                        hijo.dialogoHijo();
                        hijo.dibujar();    // PONGO ESTE METODO PORQUE SE BORRA EL HIJO AL AGARRAR EL CELU Y HACER EL Sleep.
                        Sleep(1000);
                        hijo.dibujar();
                        padre.dialogoPadreBorrar();
                        hijo.dialogoHijoBorrar();
                    }

                }
          }

          //------------------------------------------------------------------------------------------------------------------------------------





          //CONTROL VELOCIDAD PADRE.
          //***************************************************************
          if(cont%3 == 0){

            padre.mover();


          }

          cont ++;

          Sleep(20);    //FUNDAMENTAL PARA CONTROL DE VELOCIDAD.




          //****************************************************************





          //DETECCION SI LA BALA TOCA AL PERSONAJE - SE ELIMINA LA BALA.
          //---------------------------------------------------------------------------------------------------------------------------------


          for(it = Balas.begin();it != Balas.end();it++){

                if((*it)->X() == hijo.X() && ((*it)->Y() == hijo.Y() || (*it)->Y() == hijo.Y() + 1 || (*it)->Y() == hijo.Y() + 2)){  // EN ESTA CONDICION ES CLAVE EVALUAR TAMBIEN EL EJE y, YA QUE SI SOLO EVALUO LA CONDICION EN x LA BALA DESAPARECE
                                                                                                                                     //AL LLEGAR A LA POSICION DEL PERSONAJE SIN IMPORTAR SI CHOCA O NO.

                    gotoxy((*it)->X(),(*it)->Y());printf(" ");
                    delete(*it);
                    it = Balas.erase(it);

                    hijo.morir();

                    gameover = true;
                    break;

                }
          }

          //---------------------------------------------------------------------------------------------------------------------------------


    }//FIN while


    Sleep(3000);
    system("cls");

    Auxiliar::gotoxy(SCREEN_WIDTH/2,SCREEN_HEIGHT/2); printf("JUEGO TERMINADO");

    Sleep(3000);

    system("cls");

}



#endif // JUEGO_H_INCLUDED
