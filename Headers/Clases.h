#ifndef CLASES_H_INCLUDED
#define CLASES_H_INCLUDED

void gotoxy(int, int);

void gotoxy(int x, int y)
{
    COORD Pos;

    Pos.X = x;
    Pos.Y = y;

    SetConsoleCursorPosition (GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

class A
{
private:
	int x;
	char y [20];
    COORD Coordenadas;
public:
	void cargar( int );
	void ordenar();
	void listar();
	void guardar();
};

void A::guardar()
{
	FILE *p;
	p = fopen("archivo.dat", "ab" );
	if ( p == NULL )
	{
		cout << "Error de archivo." << endl;
		system( "pause" );
		return;
	}
	fwrite( this, sizeof( A ), 1, p );
	fclose( p );
}

void A::ordenar()
{
	FILE *p;
	int i, j, tam;
	p = fopen("archivo.dat", "rb+" );
	if ( p == NULL )
	{
		cout << "Error de archivo." << endl;
		system( "pause" );
		return;
	}
	fseek( p, 0, SEEK_END );
	tam = ftell( p ) / sizeof( A );
	A Aaux, *Avec;
	Avec = new A [tam];
	if ( Avec == NULL )
	{
		fclose( p );
		return;
	}
	fseek( p, 0, SEEK_SET );
	fread( Avec, sizeof( A ), tam, p );
	for ( i = 0; i < ( tam - 1 ); i++ )
	{
		for ( j = i + 1; j < tam; j++ )
		{
			if ( Avec [j].x > Avec [i].x )
			{
				/// aux = vec[j] ;
				//aux.idAutor=vec[j].idAutor;
				//strcpy(aux.apellido,vec[j].apellido);
				Aaux.x = Avec [j].x;
				strcpy( Aaux.y, Avec [j].y );

				/// vec[j] = vec[i] ;
				Avec [j].x = Avec [i].x;
				strcpy( Avec [j].y, Avec [i].y );

				/// vec[i] = aux ;
				Avec [i].x = Aaux.x;
				strcpy( Avec [i].y, Aaux.y );
			}
		}
	}



	fseek( p, 0, SEEK_SET );

	if( tam >= 3 )
    {
        fclose(p);
        p=fopen( "archivo.dat" , "wb" );
        for( i = 0; i<3; i++ )
        {
            fwrite( &Avec[i], sizeof( A ), 1, p );
        }
    }
    else fwrite( Avec, sizeof( A ), tam, p );
	delete []Avec;
	fclose( p );



}

void A::cargar( int b )
{
	x = b;
	cout << "Mete tu nombre, vieja: ";
	cin.ignore();
	cin.get( y, 21 );
	guardar();
	ordenar();
}

void A::listar()
{
	FILE *p;
	p = fopen("archivo.dat", "rb" );
	if ( p == NULL )
	{
		cout << "Error de archivo." << endl;
		system( "pause" );
		return;
	}

    int X = 30;
    int Y = 10;
	while(  fread( this, sizeof( A ), 1, p ) )
    {
        gotoxy(X,Y);
        cout<<"Puntaje: "<<x;
        Y ++;
        gotoxy(X,Y);
        cout<<"Nombre: "<<y;
        Y += 2;
        gotoxy(X,Y);
    }
	fclose( p );
}

class Bala
{
private:
    COORD Coordenadas;
    HANDLE hStdout;
public:

    COORD GetCoordenadas()
    {
        return Coordenadas;
    }

    bool Fuera()
    {
        if( Coordenadas.Y < 2 )
        {
            return true;
        }
        return false;
    }

    void Mover()
     {
         SetConsoleCursorPosition (hStdout, Coordenadas);
         cout<<" ";
         if( Fuera() == false )
         {
             Coordenadas.Y--;
             SetConsoleCursorPosition (hStdout, Coordenadas);
             cout<<char(127);
         }
     }

    Bala(int X, int Y)
    {
        hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
        Coordenadas.Y = Y;
        Coordenadas.X = X;
    }

};

class Nave
{
    private:
        COORD CPunta;
        COORD CMedio;
        COORD CBase;
        HANDLE hStdout;
    public:

        void Explotar()
        {
            BorrarNave();
            CPunta.Y += - 2;
            SetConsoleCursorPosition (hStdout, CPunta);
            cout<<"  * *  ";
            CPunta.Y++;
            SetConsoleCursorPosition (hStdout, CPunta);
            cout<<"   *   ";
            CPunta.Y++;
            SetConsoleCursorPosition (hStdout, CPunta);
            cout<<"   *   ";
            CPunta.Y++;
            SetConsoleCursorPosition (hStdout, CPunta);
            cout<<"   *   ";
            CPunta.Y++;
            SetConsoleCursorPosition (hStdout, CPunta);
            cout<<"  * *  ";
            CPunta.Y += - 4;
            Sleep(100);



            SetConsoleCursorPosition (hStdout, CPunta);
            cout<<"  * ** ";
            CPunta.Y++;
            SetConsoleCursorPosition (hStdout, CPunta);
            cout<<"   **  ";
            CPunta.Y++;
            SetConsoleCursorPosition (hStdout, CPunta);
            cout<<"  ***  ";
            CPunta.Y++;
            SetConsoleCursorPosition (hStdout, CPunta);
            cout<<"  **   ";
            CPunta.Y++;
            SetConsoleCursorPosition (hStdout, CPunta);
            cout<<" ** *  ";
            CPunta.Y += - 4;
            Sleep(100);


            SetConsoleCursorPosition (hStdout, CPunta);
            cout<<" ** ** ";
            CPunta.Y++;
            SetConsoleCursorPosition (hStdout, CPunta);
            cout<<"* **  ";
            CPunta.Y++;
            SetConsoleCursorPosition (hStdout, CPunta);
            cout<<"  * *  ";
            CPunta.Y++;
            SetConsoleCursorPosition (hStdout, CPunta);
            cout<<"  * ** ";
            CPunta.Y++;
            SetConsoleCursorPosition (hStdout, CPunta);
            cout<<" ** ** ";
            CPunta.Y += - 4;
            Sleep(100);

            SetConsoleCursorPosition (hStdout, CPunta);
            cout<<"       ";
            CPunta.Y++;
            SetConsoleCursorPosition (hStdout, CPunta);
            cout<<"       ";
            CPunta.Y++;
            SetConsoleCursorPosition (hStdout, CPunta);
            cout<<"       ";
            CPunta.Y++;
            SetConsoleCursorPosition (hStdout, CPunta);
            cout<<"       ";
            CPunta.Y++;
            SetConsoleCursorPosition (hStdout, CPunta);
            cout<<"       ";
            CPunta.Y += - 4;
            Sleep(100);

        }

        COORD GetCPunta(){ return CPunta; }
        COORD GetCMedio(){ return CMedio; }
        COORD GetCBase(){ return CBase; }
        void Mover()
        {
            char Press;
            if( kbhit() )
            {
                BorrarNave();
                Press = getch();
                if( Press == IZQUIERDA )
                {
                    if( CBase.X > 1)
                    {
                        CPunta.X--;
                        CMedio.X--;
                        CBase.X--;
                    }
                }

            if( Press == DERECHA )
                {
                    if(CBase.X < 76 )
                    {
                        CPunta.X++;
                        CMedio.X++;
                        CBase.X++;
                    }
                }
            if( Press == ABAJO )
                {
                    if( CBase.Y < 25)
                    {
                        CPunta.Y++;
                        CMedio.Y++;
                        CBase.Y++;
                    }
                }
            if( Press == ARRIBA )
                {
                    if( CPunta.Y < 24 && CPunta.Y > 1 )
                    {
                        CPunta.Y--;
                        CMedio.Y--;
                        CBase.Y--;
                    }
                }
            ImprimirNave();
            }

        }

        void ImprimirNave()
        {
            SetConsoleCursorPosition (hStdout, CPunta);
            cout<<char(173);
            SetConsoleCursorPosition (hStdout, CMedio);
            cout<<char(201)<<char(202)<<char(187);
            SetConsoleCursorPosition (hStdout, CBase);
            cout<<char(178)<<char(178)<<char(178);
        }

        void BorrarNave()
        {
            SetConsoleCursorPosition (hStdout, CPunta);
            cout<<" ";
            SetConsoleCursorPosition (hStdout, CMedio);
            cout<<" "<<" "<<" ";
            SetConsoleCursorPosition (hStdout, CBase);
            cout<<" "<<" "<<" ";
        }

        Nave()
        {
            CPunta.X = 40;
            CPunta.Y = 23;

            CMedio.X = CPunta.X - 1;
            CMedio.Y = CPunta.Y + 1;

            CBase.X = CMedio.X;
            CBase.Y = CMedio.Y + 1;

            hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
        }

};

class GUI
{
private:
    int Vidas;
    int Puntaje;
    float Hull;
public:

    int GetVida()
    {
        return Vidas;
    }

    void RedVidas()
    {
        Vidas--;
    }

    int GetPuntaje()
    {
        return Puntaje;
    }

    void AumPuntaje()
    {
        srand (time(NULL));
        Puntaje += rand() % 100;
    }

    float GetHull()
    {
        return Hull;
    }

    void RedHull()
    {
        srand (time(NULL));
        Hull -= rand() % 10;

        if( Hull <= 0 )
        {
            Hull = 100;
            Vidas--;
        }

    }

    GUI()
    {
        Vidas = 3;
        Puntaje = 0;
        Hull = 100;
    }

    void ImprimirGUI(class Nave &Jugador)
    {
        HANDLE hStdout;
        hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
        COORD Coordenadas;
        Coordenadas.X = 20;
        Coordenadas.Y = 27;
        SetConsoleCursorPosition (hStdout, Coordenadas);

        if( Vidas <= 0 )
        {
            Jugador.Explotar();
            system("cls");
            cout<<endl;
            cout<<endl;
            cout<<endl;
            cout<<endl;
            cout<<endl;
            cout<<endl;
            cout<<endl;
            cout<<endl;
            cout<<endl;
            cout<<endl;
            cout<<endl;
            cout<<"                   Perdiste, sos muy manco..."<<endl;
            cout<<endl;
            cout<<endl;
            cout<<endl;
            cout<<endl;
            cout<<endl;
            cout<<endl;
            cout<<endl;
            cout<<endl;
            cout<<endl;
            cout<<endl;
            cout<<endl;
            cout<<endl;
            cout<<endl;
            system("pause");

            A Registro;

            Registro.cargar( Puntaje );
            system("cls");
            while(true)
            {
                system("cls");
                Registro.listar();
                system("color 0f");
                Sleep(10);
                system("color 1e");
                Sleep(10);
                system("color 2d");
                Sleep(10);
                system("color 3c");
                Sleep(10);
                system("color 4b");
                Sleep(10);
                system("color 5a");
                Sleep(10);
                system("color 69");
                Sleep(10);
                system("color 78");
                Sleep(10);
                system("color 87");
                Sleep(10);
                system("color 96");
                Sleep(10);
                system("color a5");
                Sleep(10);
                system("color b4");
                Sleep(10);
                system("color c3");
                Sleep(10);
                system("color b2");
                Sleep(10);
                system("color a1");
                Sleep(10);
            }


            system("pause >NUL");
            exit(1);

        }

        cout<<"Vidas: ";

        if( Vidas == 1 )
        {
            cout<<char(03);
            cout<<"     ";
        }

        if( Vidas == 2 )
        {
            cout<<char(03);
            cout<<char(03);
            cout<<"    ";
        }

        if( Vidas == 3 )
        {
            cout<<char(03);
            cout<<char(03);
            cout<<char(03);
            cout<<"   ";
        }
        if( Hull < 100 )
        {
            cout<<"Hull: "<<Hull;
            cout<<"    ";
        }else
        {
            cout<<"Hull: "<<Hull;
        cout<<"   ";
        }
        cout<<"                    ";
        gotoxy(Coordenadas.X+25, Coordenadas.Y);
        cout<<"Puntaje: "<<Puntaje;

    }

    void BorrarGUI()
    {
        HANDLE hStdout;
        hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
        COORD Coordenadas;
        Coordenadas.X = 20;
        Coordenadas.Y = 27;
        SetConsoleCursorPosition (hStdout, Coordenadas);
        cout<<"                                       "<<endl;
    }

};

class Asteroide
{
    private:
        COORD Coordenadas;
    public:

        COORD GetCoordenadas()
        {
            return Coordenadas;
        }

        void Colision( class Nave &Jugador, class GUI &Vision )
        {
            if
                (
                    ( Coordenadas.X >= Jugador.GetCPunta().X -1 && Coordenadas.X <= Jugador.GetCPunta().X + 1 ) &&
                    ( Coordenadas.X >= Jugador.GetCMedio().X && Coordenadas.X <= Jugador.GetCMedio().X + 2) &&
                    ( Coordenadas.X >= Jugador.GetCBase().X && Coordenadas.X <= Jugador.GetCBase().X + 2) &&
                    ( Coordenadas.Y >= Jugador.GetCPunta().Y && Coordenadas.Y <= Jugador.GetCPunta().Y + 2) &&
                    ( Coordenadas.X >= Jugador.GetCPunta().X -1 && Coordenadas.X <= Jugador.GetCPunta().X + 1 )
                 )
            {
                Vision.RedHull();
            }
        }

        Asteroide(int PosX, int PosY)
        {
            Coordenadas.X = PosX;
            Coordenadas.Y = PosY;
        }

        void Mostrar()
        {
            HANDLE hStdout;
            hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleCursorPosition (hStdout, Coordenadas);
            cout<<char(04);
        }

        void Mover()
        {
            HANDLE hStdout;
            hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleCursorPosition (hStdout, Coordenadas);
            cout<<" ";
            Coordenadas.Y++;
            if( Coordenadas.Y >= 26 )
            {
                Coordenadas.X = rand() % 77 + 2;
                Coordenadas.Y = 2;
            }

            Mostrar();
        }
};

#endif // CLASES_H_INCLUDED
