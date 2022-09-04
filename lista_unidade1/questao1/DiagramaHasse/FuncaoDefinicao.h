#pragma once
#include<iostream>
#include<cstdio>
#include<SDL.h>
#include<SDL_image.h>
#include"constantes.h"
#include"FuncaoDeclaracao.h"

// Função responsável pela inicialização da biblioteca SDL
bool init()
{
	// Inicialização da biblioteca SDL
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
	// Criação da Janela
	gJanela = SDL_CreateWindow("Diagrama", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, larJanela, altJanela, SDL_WINDOW_SHOWN);
	// Criação do renderizador
	gRenderizador = SDL_CreateRenderer(gJanela, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	IMG_Init(IMG_INIT_PNG);
	TTF_Init();
	return 0;
}

bool loadMedia()
{
	gFonte = TTF_OpenFont("fontes/arial_bold.TTF", 40);
	return 0;
}

void close() {
	SDL_DestroyWindow(gJanela);
	gJanela = NULL;
	SDL_DestroyRenderer(gRenderizador);
	gRenderizador = NULL;
	SDL_Quit();
}

