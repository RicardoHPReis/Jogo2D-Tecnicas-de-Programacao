#include "stdafx.h"
#include "Jogo.h"


int main()
{
    srand(static_cast<unsigned>(time(NULL)));
    Jogo jogo;

    while (jogo.rodando())
    {
        //jogo.rodar_menu();
        //if()
        jogo.update();
    }

    return EXIT_SUCCESS;
}