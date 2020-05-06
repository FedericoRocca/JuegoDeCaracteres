#ifndef MENUES_H_INCLUDED
#define MENUES_H_INCLUDED

void PintarBordes();
int Menu_Principal();

int Menu_Principal()
{
    system("cls");
    PintarBordes();
    HANDLE hStdout;

    COORD Coordenadas;

    hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

    Coordenadas.X = 20;
    Coordenadas.Y = 5;

    SetConsoleCursorPosition (hStdout, Coordenadas);

    cout<<"Bienvenidos a SIMKLOSTER SHOOTER";


    Coordenadas.X = 20;
    Coordenadas.Y = 8;
    SetConsoleCursorPosition (hStdout, Coordenadas);

    cout<<"Elija la dificultad:";
    Coordenadas.X = 20;
    Coordenadas.Y = 9;
    SetConsoleCursorPosition (hStdout, Coordenadas);
    cout<<"1 - Claudio Fernandez";
    Coordenadas.X = 20;
    Coordenadas.Y = 10;
    SetConsoleCursorPosition (hStdout, Coordenadas);
    cout<<"2 - Angel Simon";
    Coordenadas.X = 20;
    Coordenadas.Y = 11;
    SetConsoleCursorPosition (hStdout, Coordenadas);
    cout<<"3 - Diego Spagnolo";Coordenadas.X = 20;
    Coordenadas.Y = 12;
    SetConsoleCursorPosition (hStdout, Coordenadas);
    cout<<"4 - Daniel Kloster";
    Coordenadas.X = 20;
    Coordenadas.Y = 13;
    SetConsoleCursorPosition (hStdout, Coordenadas);
    cout<<"5 - Pepe (DIOS)";
    Coordenadas.X = 20;
    Coordenadas.Y = 14;
    SetConsoleCursorPosition (hStdout, Coordenadas);
    cout<<"Opcion: ";

    char Opcion;
    cin>>Opcion;

    switch( Opcion )
    {
    case '1':
        return 3;
        break;
    case '2':
        return 6;
        break;
    case '3':
        return 12;
        break;
    case '4':
        return 24;
        break;
    case '5':
        return 48;
        break;
    default:
        return 0;
        break;
    }

    system("pause >NUL");
    system("cls");


}

void PintarBordes()
{
    int i;
    for( i=0; i<80; i++ )
    {
        if( i==0 )
        {
            cout<<char(201);
        }

        if( i==79 )
        {
            cout<<char(187);
        }

        if( i != 0 && i != 79 )
        {
            cout<<char(205);
        }
    }
int a;
    for( a=0; a<25;a++ )
    {
        cout<<endl;
        for( i=0; i<80; i++ )
        {
            if( i==0 )
            {
                cout<<char(186);
            }

            if( i==79 )
            {
                cout<<char(186);
            }

            if( i != 0 && i != 79 )
            {
                cout<<" ";
            }
        }
    }
    cout<<endl;
    for( i=0; i<80; i++ )
    {
        if( i == 0 )
        {
            cout<<char(204);
        }

        if( i ==79 )
        {
            cout<<char(185);
        }

        if( i != 0 && i != 79 )
        {
            cout<<char(205);
        }
    }
    cout<<endl;
    for( a=0; a<2; a++ )
    {
        for( i=0; i<80; i++ )
        {
            if( i==0 )
            {
                cout<<char(186);
            }

            if( i == 79 )
            {
                cout<<char(186);
            }

            if( i != 0 && i != 79 )
            {
                cout<<" ";
            }
        }
        cout<<endl;
    }
    for( i=0; i<80; i++ )
        {
            if( i==0 )
            {
                cout<<char(200);
            }

            if( i == 79 )
            {
                cout<<char(188);
            }

            if( i != 0 && i != 79 )
            {
                cout<<char(205);
            }
        }









}

#endif // MENUES_H_INCLUDED
