#include "stdafx.h"
#include "Jogo.h"
#include "menu.h"
/*
int main()
{
    //init srand
    srand(static_cast<unsigned>(time(NULL)));

    //começa a classe menu

    Menu* menu = new Menu();

    menu->run_menu();

    delete menu;

    menu = nullptr;
    //loop do jogo

    //fim
    return EXIT_SUCCESS;
}*/

int main()
{
    //init srand
    srand(static_cast<unsigned>(time(NULL)));

    //começa a classe jogo

    Jogo jogo;

    
    //loop do jogo

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
