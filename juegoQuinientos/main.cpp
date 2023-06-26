#include <iostream>
#include "rlutil.h"
#include"funcionesVarias.h"

using namespace std;

int pintarMenu();

int main()
{
    rlutil::hidecursor();
    rlutil::setConsoleTitle("QUINIENTOS");

    int finalizarMenu=0;

    pintarMenu();

    return 0;
}
/* PARTIDA 1 JUGADOR */
