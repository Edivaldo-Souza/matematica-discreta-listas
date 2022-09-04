#pragma once
#include <SDL.h>;
#include<SDL_ttf.h>

// Declaração da largura da janela;
const int larJanela = 600;

// Declaração da altura da janela;
const int altJanela = 600;

// Declaração da Janela
SDL_Window* gJanela = NULL;

// Declaração do Renderizador
SDL_Renderer* gRenderizador = NULL;

TTF_Font* gFonte = NULL;
