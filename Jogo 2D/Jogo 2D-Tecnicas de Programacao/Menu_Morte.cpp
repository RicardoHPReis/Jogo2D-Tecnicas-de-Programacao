/*#include "Menu_Morte.h"

Menu_Morte::Menu_Morte(int i) :
	Menu(i)
{
	voltar = false;

	fonte.loadFromFile("../../Fontes/Font.otf");
	imagem.loadFromFile("../../Texturas/Cenario/Pause.jpg");
	fundo.setTexture(imagem);

	textos.resize(3);
	escrita = { "A Floresta","Continuar","Sair" };
	coordenadas = { { 610,200 }, { 610,650 }, { 610,750 } };
	tamanhos = { 100,50,50 };

	for (int i = 0; i < textos.size(); i++)
	{
		textos[i].setFont(fonte);
		textos[i].setString(escrita[i]);
		textos[i].setCharacterSize(tamanhos[i]);
		textos[i].setOutlineColor(Color::Red);
		textos[i].setPosition(coordenadas[i]);
	}
	textos[1].setOutlineThickness(4);
}

Menu_Morte::~Menu_Morte()
{
}

void Menu_Morte::executar()
{
	bool clique = false;
	while (clique == false)
	{
		if ((Keyboard::isKeyPressed(Keyboard::Up) || Keyboard::isKeyPressed(Keyboard::W)) && delay == 0)
		{
			delay++;
			if (escolha != 1 && apertou == false)
			{
				cout << "contiuou!" << endl;
				escolha = 1;
				textos[escolha].setOutlineThickness(4);
				textos[escolha + 1].setOutlineThickness(0);
				selecao = false;
				apertou = false;
			}
		}
		if ((Keyboard::isKeyPressed(Keyboard::Down) || Keyboard::isKeyPressed(Keyboard::S)) && delay == 0)
		{
			delay++;
			if (escolha != 2 && apertou == false)
			{
				cout << "voltou!" << endl;
				escolha = 2;
				textos[escolha].setOutlineThickness(4);
				textos[escolha - 1].setOutlineThickness(0);
				selecao = false;
				apertou = false;
			}
		}
		if (Keyboard::isKeyPressed(Keyboard::Enter) && !selecao)
		{
			selecao = true;
			if (escolha == 1) //RODA JOGO
			{
				clique = true;
				rodando_menu = false;
			}
			else if (escolha == 2) //Volta para o menu
			{
				clique = true;
				rodando_menu = false;
				voltar = true;
			}
		}

		if (delay > 0)
		{
			delay += 1;
			if (delay >= tempoDelay)
				delay = 0;
		}
		imprimir();
	}
}

void Menu_Morte::imprimir()
{
	Gerenciador_Grafico::getInstancia_Grafico()->limpar();
	Gerenciador_Grafico::getInstancia_Grafico()->desenharSprite(fundo);
	Gerenciador_Grafico::getInstancia_Grafico()->desenharTexto(textos[0]);
	Gerenciador_Grafico::getInstancia_Grafico()->desenharTexto(textos[1]);
	Gerenciador_Grafico::getInstancia_Grafico()->desenharTexto(textos[2]);
	Gerenciador_Grafico::getInstancia_Grafico()->mostrar();
}

const bool Menu_Morte::getVoltarMenu() const
{
	return voltar;
}*/