#include <iostream>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <list>

#define ARRIBA 72
#define ABAJO 80
#define IZQUIERDA 75
#define DERECHA 77

using namespace std;


double PCFreq = 0.0;
__int64 CounterStart = 0;

void StartCounter()
{
    LARGE_INTEGER li;
    if(!QueryPerformanceFrequency(&li))
	cout << "QueryPerformanceFrequency failed!\n";

    PCFreq = double(li.QuadPart)/1000.0;

    QueryPerformanceCounter(&li);
    CounterStart = li.QuadPart;
}
double GetCounter()
{
    LARGE_INTEGER li;
    QueryPerformanceCounter(&li);
    return double(li.QuadPart-CounterStart)/PCFreq;
}

#include "Headers/Archivos.h"
#include "Headers/Clases.h"
#include "Headers/Menues.h"

int main()
{
    HANDLE Hcon;
    Hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO Cursor;
    Cursor.bVisible = false;
    Cursor.dwSize = 50;
    SetConsoleCursorInfo(Hcon,&Cursor);

    system("cls");
    StartCounter();

    int Dificultad = 0;
    while( Dificultad == 0 )
    {
        Dificultad = Menu_Principal();
    }


    system("cls");



    StartCounter();
    PintarBordes();

    bool Juego = true;
    Nave Jugador;
    char Press;
    GUI Vision;

    list<Bala*> Disparo;
    list<Bala*>::iterator Iterador;

    list<Asteroide*> Enemigo;
    list<Asteroide*>::iterator Iterador_Enemigo;

    for( int i=0; i<Dificultad; i++ )
    {
        Enemigo.push_back( new Asteroide( rand() % 75 + 2 , rand() % 5 + 2) );
    }

    Jugador.ImprimirNave();

    HANDLE hStdout;
    hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    while( Juego == true )
    {
        Jugador.ImprimirNave();

        if( kbhit() )
        {
            Press = getch();
            if( Press == 'd' )
            {
                Disparo.push_back( new Bala( Jugador.GetCPunta().X, Jugador.GetCPunta().Y - 1 ) );
            }
        }

        for( Iterador = Disparo.begin(); Iterador != Disparo.end(); Iterador++ )
        {
            (*Iterador)->Mover();
            if( (*Iterador)->Fuera() == true )
            {

                SetConsoleCursorPosition (hStdout, (*Iterador)-> GetCoordenadas());
                cout<<" ";
                delete(*Iterador);
                Iterador = Disparo.erase( Iterador );
            }
        }

        for(Iterador_Enemigo = Enemigo.begin(); Iterador_Enemigo != Enemigo.end(); Iterador_Enemigo++ )
        {
            (*Iterador_Enemigo)->Mover();
            (*Iterador_Enemigo)->Colision(Jugador, Vision);
        }

        for(Iterador_Enemigo = Enemigo.begin(); Iterador_Enemigo != Enemigo.end(); Iterador_Enemigo++ )
        {
            for( Iterador = Disparo.begin(); Iterador != Disparo.end(); Iterador++ )
            {
                if( (*Iterador_Enemigo)->GetCoordenadas().X == (*Iterador)->GetCoordenadas().X )
                {
                    if( (*Iterador_Enemigo)->GetCoordenadas().Y == (*Iterador)->GetCoordenadas().Y || ( (*Iterador_Enemigo)->GetCoordenadas().Y +1 == (*Iterador)->GetCoordenadas().Y ))
                    {
                        SetConsoleCursorPosition (hStdout, (*Iterador)-> GetCoordenadas());
                        cout<<" ";
                        delete(*Iterador);
                        Iterador = Disparo.erase( Iterador );

                        SetConsoleCursorPosition (hStdout, (*Iterador_Enemigo)-> GetCoordenadas());
                        cout<<" ";
                        delete(*Iterador_Enemigo);
                        Iterador_Enemigo = Enemigo.erase( Iterador_Enemigo );

                        Enemigo.push_back( new Asteroide( rand() % 75 + 2 , rand() % 5 + 2) );

                        Vision.AumPuntaje();
                    }
                }
            }
        }


        Jugador.Mover();
        Vision.ImprimirGUI(Jugador);

        switch( Dificultad )
        {
        case 3:
            Sleep(50);
            break;
        case 6:
            Sleep(40);
            break;
        case 12:
            Sleep(35);
            break;
        case 24:
            Sleep(30);
            break;
        case 48:
            Sleep(25);
            break;
        default:
            Sleep(30);
            break;
        }

    }
    return 0;
}
