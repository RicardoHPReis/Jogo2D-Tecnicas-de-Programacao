#pragma once
#include "Menu.h"

class Menu_Pause : public Menu
{
private:
	bool voltar;

public:
	Menu_Pause(int i = 5);
	~Menu_Pause();

	void executar();
	void imprimir();
	const bool getVoltarMenu() const;
};