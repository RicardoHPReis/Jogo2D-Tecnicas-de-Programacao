#pragma once
#include "Ente.h"

class Pause : public Ente
{
private:
	int delay, tempoDelay;
	
	int escolha;
	bool apertou, selecao;
	bool rodando_pause;
	bool voltar;

	Font fonte;
	Texture imagem;
	Sprite fundo;

	vector<string> escrita;
	vector<Vector2f> coordenadas;
	vector<Text> textos;
	vector<size_t> tamanhos;

	void inicVariaveis();

public:
	Pause(int i = 5);
	~Pause();

	void executar();
	void imprimir();
	const bool getRodandoPause() const;
	void setRodandoPause(const bool rodP);
	const bool getVoltarMenu() const;
};