#ifndef FUNCIONESVARIAS_H_INCLUDED
#define FUNCIONESVARIAS_H_INCLUDED
#include <iostream>
#include "rlutil.h"
#include<time.h>
#include <string.h>

using namespace std;
void mostrarTirada(int dados[]) {
    for(int i = 0; i<=5; i++){
        cout << dados[i] << " ";
    }
     cout << endl;
}

void tiradaDados(int *dados){
     srand(time(NULL));
    // PASO 1 - Se llena VECTOR `dados` con numeros ALEATORIOS
    for (int i = 0; i <= 5; i++)
    {
        dados[i] = 1 + rand() % (7 - 1);
    }

}

int puntajeDados(int* dados, int* vectorPuntos)
{
    int vectorCopia[6] = {};
    // PASO 2 -  Se llena el vectorCopia con los datos de vectorPuntos
    for (int j = 0; j <= 5; j++)
    {
        vectorCopia[j] = dados[j];
    }


    // PASO 3 - Lo recorro con los ciclos for, sumando en vectorpuntos un +1 en el indice valor de dados - 1 y poniendo en la copia de vector un -1
    for (int h = 0; h < 6; h++)
    {
        for (int u = 5; u >= 0; u--)
        {
            if (h != u)
            {
                if ((dados[h] == vectorCopia[u]) && (vectorCopia[u] > 0))
                {
                    vectorPuntos[dados[h] - 1] += 1;
                    vectorCopia[u] = -1;
                }
            }
        }
    }


    return 0;
}

int calcularJugada(int *vectorPuntos, int *dados)
{
    int sumaDados = 0, trioX = 0, sexteto = 0;
    bool  escalera = true;

    for (int i = 0; i <= 5; i++)
    {
         if (vectorPuntos[i] == 6 && dados[i] == 6){
            escalera = false;
            cout<<"ES UN SEXTETO DE 6!,PERDES LOS PUNTOS DE ESTA RONDA !" << endl;
            return -1;
        }
         else if (vectorPuntos[i] == 6 && dados[i] != 6)
        {
            escalera = false;
            sexteto = dados[i] * 50;
            cout<<"ES UN SEXTETO!" << endl;
            cout<<"Puntos por jugada  "<< sexteto << endl;
            return sexteto;
        }else if (vectorPuntos[i] >= 3 && vectorPuntos[i] <= 5){
            escalera = false;
            if(i+1 >= trioX){
                trioX = (i+1);
            }


        }else if (vectorPuntos[i] == 2){
            escalera = false;
            sumaDados = dados[0] + dados[1] + dados[2] + dados[3] + dados[4] + dados[5];
            cout<<"SUMA DE DADOS! " << endl;
            cout<<"Puntos por jugada  "<< sumaDados << endl;

            return sumaDados;
        }
}
        if(escalera == true){
        cout << "FELICIDADES!! , ESCALERA!! GANASTE EL JUEGO!. " << endl;
        return 1;

        }
            cout<<"ES UN TRIO! " << endl;
            trioX = trioX * 10;
            cout<<"Puntos por jugada  "<< trioX << endl;
            return trioX;

}


int partidaUnJugador(char nombreJugador[])
{
    cout << "INGRESE  NOMBRE DEL JUGADOR" << endl;
    cin >> nombreJugador;
    int contador=1,puntos = 0;
    bool escalera = false;
    int dados[6]={};
    int dados2[6]={1,2,3,4,5,6};
    int tiradas = 0;
    int maxPuntosRonda=0;
    string stop;

    while(puntos<=500){
        int puntosRonda=0;
        /* LANZAMIENTOS*/
        cout << "NOMBRE: " << nombreJugador << " | " <<  "RONDA: " << contador << " | " << "PUNTAJE TOTAL: "<< puntos << endl;
        cout << endl;
        if(tiradas <= 3){
        int puntosTirada =0;
        int vectorPuntosJugador1[6]={};
            cout << "LANZAMIENTO NUMERO " << tiradas + 1 << endl;
            cout << "MAXIMO PUNTAJE DE LA RONDA " << maxPuntosRonda << endl;
            cout << "LANZAR DADOS... " << endl;
            rlutil::msleep(1000);
            tiradaDados(dados);
            cout << "DADOS " << endl;

            mostrarTirada(dados);
            puntajeDados(dados,vectorPuntosJugador1);
            puntosTirada = calcularJugada(vectorPuntosJugador1,dados);

            puntosRonda += puntosTirada;
            if(puntosTirada>maxPuntosRonda){
                maxPuntosRonda = puntosTirada;
            }

            // Escalera
            if(puntosTirada == 1){
    puntos = 500;
    cout << "FELICIDADES!" << nombreJugador << " , GANASTE!." << endl;
    cout << "ACUMULASTE " << puntos << endl;
    cout << "INGRESE CUALQUIER TEXTO PARA CONTINUAR " << endl;
    cin >> stop;
    system("cls");

    return puntos;
            }
            if(puntosTirada == -1){
                puntosRonda = 0;
                tiradas = -1 ;
                contador ++;
            }


            tiradas ++;
        }
            if(tiradas == 3){
                puntos += maxPuntosRonda;
                tiradas = 0;
                maxPuntosRonda = 0;
                contador++;
            }

        cout << "INGRESE CUALQUIER TEXTO PARA CONTINUAR" << endl;
        cin >> stop;
        cout << endl;
    }

    cout << "FELICIDADES!" << nombreJugador << ", GANASTE!." << endl;
    cout << "TU PUNTUACION EN ESTA PARTIDA " << puntos << endl;
    cout << "INGRESE CUALQUIER TEXTO PARA CONTINUAR" << endl;
    cin >> stop;
    system("cls");
    return puntos;
}



int pintarMenu()
{
    int y=0;
    int finalizarMenu = 0;
    int puntuacionMasAlta =0;
    int puntuacion =0;
    char nombreJugador[10];
    char nombreJugadorMejorPuntaje[10];
    do
    {
        rlutil::locate(56,10);
        cout << "MENU" << endl;
        rlutil::locate(50,11);
        cout << "PARTIDA UN JUGADOR" << endl;
        rlutil::locate(50,12);
        cout << "PARTIDA DOS JUGADORES" << endl;
        rlutil::locate(50,13);
        cout << "PUNTUACION MAS ALTA" << endl;
        rlutil::locate(50,14);
        cout << "REGLAS" << endl;
        rlutil::locate(56,15);
        cout << "SALIR" << endl;
        rlutil::locate(48,11+ y);
        cout << (char)175 << endl;



        switch(rlutil::getkey())
        {
        case 14: // up
            rlutil::locate(48,11+ y);
            cout << " " << endl;
            y--;
            if(y == -1)
            {
                y = 4;
            }

            break;

//down
        case 15:
            rlutil::locate(48,11+ y);
            cout << " " << endl;
            y++;
            if(y > 4)
            {
                y = 4;
            }
            break;


        // DECISION DE OPCION ELEGIDA
       case 1:
            switch(y){
            case 0:
            system("cls");
           puntuacion = partidaUnJugador(nombreJugador);
           if(puntuacion > puntuacionMasAlta){
            strcpy(nombreJugadorMejorPuntaje,nombreJugador);
            puntuacionMasAlta = puntuacion;
           }
            break;
            case 1:
                system("cls");
                cout << "No funciona todavia";
            break;
            case 2:
                system("cls");
                cout << "LA PUNTUACION MAS ALTA FUE DE, "<< nombreJugador << " CON UNA PUNTUACION DE "<< puntuacionMasAlta << " ";
            break;
            case 3:
                system("cls");
                cout << "No funciona todavia";
            break;
            case 4:
                system("cls");
               finalizarMenu = 1;
            break;
            }

        }
    }
    while( finalizarMenu!= 1);

    return 0;
}



/* PARTIDA 1 JUGADOR */

// int main()
// {
//     int num, x;
//     int dados[6];
//     int vectorPuntos[6] = {};
//     int vectorCopia[6] = {};




// // PASO 2 -  Se llena el vectorCopia con los datos de vectorPuntos

//     for (int j = 0; j <= 5; j++)
//     {
//         vectorCopia[j] = dados[j];
//     }


//     for (int h = 0; h < 6; h++)
//     {
//         for (int u = 5; u >= 0; u--)
//         {
//             if (h != u)
//             {
//                 if ((dados[h] == vectorCopia[u]) && (vectorCopia[u] > 0))
//                 {
//                     vectorPuntos[dados[h] - 1] += 1;
//                     vectorCopia[u] = -1;
//                 }
//             }
//         }
//     }

//      for (int n = 0; n < 6; n++)
//     {
//         cout << "El " << n + 1 << " Se repite " << vectorPuntos[n] << endl;
//     }
//     return 0;
// }

#endif // FUNCIONESVARIAS_H_INCLUDED
