#include "stdafx.h"
#include "Jogo.h"


int main()
{
    //init srand
    srand(static_cast<unsigned>(time(NULL)));

    //declara jogo

    Jogo jogo;

    //come�a a classe jogo

    while (jogo.rodando())
    {
        //update

        jogo.update();
        //render

        jogo.render();
    }

    //fim
    return EXIT_SUCCESS;
}