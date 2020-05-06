#ifndef ARCHIVOS_H_INCLUDED
#define ARCHIVOS_H_INCLUDED

struct Puntajes
{
    char Nombre[20];
    int Puntaje;
};

void Guardar_Puntaje(int);
void Ordenar_Archivo();

void Guardar_Puntaje(int Puntaje)
{

    system("cls");
    Puntajes Registro;
    Registro.Puntaje = Puntaje;
    cout<<"Pone tu nombre, para guardar esta verguenza de puntaje: ";
    cin.get( Registro.Nombre, 21 );

    FILE* Puntero = fopen( "Puntajes.dat", "ab" );
    if( Puntero == NULL ) exit(2);
    fwrite( &Registro, sizeof Registro, 1, Puntero );
    fclose( Puntero );
}

void Ordenar_Archivo()
{
    FILE* Puntero = fopen( "Puntajes.dat", "rb" );
    if( Puntero == NULL ) exit(2);

    Puntajes Mayor, Medio, Menor, Registro;

    int Cantidad_Registros = 0;

    while( fread( &Registro, sizeof Registro, 1, Puntero ) )
    {
        Cantidad_Registros++;

        if( Cantidad_Registros == 1 )
        {
            Mayor = Registro;
        }

        if( Registro.Puntaje > Mayor.Puntaje )
        {
            Medio = Mayor;
            Mayor = Registro;
        }

    }

}

#endif // ARCHIVOS_H_INCLUDED
