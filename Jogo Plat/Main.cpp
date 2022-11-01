#include "stdafx.h"
#include "Jogo.h"
#include "menu.h"

int main()
{
    //init srand
    srand(static_cast<unsigned>(time(NULL)));

    //começa a classe menu

    Menu* menu = new Menu();

    menu->run_menu();

    delete menu;

    menu = nullptr;

    //fim
    return EXIT_SUCCESS;
}