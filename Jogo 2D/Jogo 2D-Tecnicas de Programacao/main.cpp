#include "stdafx.h"
#include "Jogo.h"


int main()
{
    //init srand
    srand(static_cast<unsigned>(time(NULL)));

    //declara jogo

    Jogo jogo;

    //come�a a classe jogo

    while (jogo.rodando() == 1)
    {
        //update

        jogo.update();

    }

    //fim
    return EXIT_SUCCESS;
}