#include <iostream>
#include "rlutil.h"

/* TIRADA DE DADOS( CARGA VECTOR )*/
/* int tiradaDados(int* dados){
     srand(time(NULL));
    // PASO 1 - Se llena VECTOR `dados` con numeros ALEATORIOS
    for (int i = 0; i <= 5; i++)
    {
        dados[i] = 1 + rand() % (7 - 1);
    }
}
/* TIRADA DE DADOS( CARGA VECTOR )*/

/* int puntajeDados(int* dados[],int* vectorPuntos[]){
        int vectorCopia[6] = {};
// PASO 2 -  Se llena el vectorCopia con los datos de vectorPuntos
    for (int j = 0; j <= 5; j++)
    {
        vectorCopia[j] = dados[j];
    }

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

}
