#pragma once
#include<SDL.h>
#include<SDL_image.h>
#include<iostream>
#include"ClassDeclaracao.h"
#include"FuncaoDeclaracao.h"
#include"constantes.h"
#include"Objetos.h"

// função que atribui os valores inicias as variáveis da classe
LTextura::LTextura()
{
	mTextura = NULL;
	mLargura = 0;
	mAltura = 0;
}

// função que redefine os valores das variáveis da classe para como iniciamente foram definidas em LTextura()
LTextura::~LTextura()
{
	free();
}
// função que recebe uma string correspondente ao caminho(nome_da_pasta/imagem.png) da imagem a ser utilizada como textura
bool LTextura::loadFromFile(std::string path, Uint32 r, Uint32 g, Uint32 b)
{
	// free() apaga qualquer definição de mTextura e suas dimensões antes de carregar uma nova imagem
	free();

	// novaTextura é uma SDL_Texture que está apenas no escopo dessa função para criar a textura
	// e retornar seu valor para a variável da classe mTextura
	SDL_Texture* novaTextura = NULL;

	// loadSurface é a SDL_Surface onde se é carregada a imagem correspondente ao caminho passado no parâmetro da função
	SDL_Surface* loadSuperficie = IMG_Load(path.c_str());

	// SDL_ColorKey torna certa tonalidade de pixels transparentes de uma SDL_Surface
	SDL_SetColorKey(loadSuperficie, SDL_TRUE, SDL_MapRGB(loadSuperficie->format, r, g, b));

	// novaTextura cria recebe o valor da criação de uma textura a partir de loadSuperficie
	novaTextura = SDL_CreateTextureFromSurface(gRenderizador, loadSuperficie);

	// mLargura recebe a largura de loadSuperficie
	mLargura = loadSuperficie->w;

	// mAltura recebe a altura de loadSuperficie
	mAltura = loadSuperficie->h;

	// Apaga a imagem carregada em loadSuperficie
	SDL_FreeSurface(loadSuperficie);

	// mTextura recebe a textura de novaTextura
	mTextura = novaTextura;

	// a função retorna true quando mTextura armazenar alguma coisa  
	return mTextura != NULL;
}

bool LTextura::carregarTexto(std::string textoTextura, SDL_Color corDoTexto,TTF_Font* font)
{
	free();
	SDL_Surface* superficie_Texto = TTF_RenderText_Solid(font, textoTextura.c_str(), corDoTexto);
	if (superficie_Texto == NULL)
	{
		std::cout << TTF_GetError();
	}
	else
	{
		mTextura = SDL_CreateTextureFromSurface(gRenderizador, superficie_Texto);
		mLargura = superficie_Texto->w;
		mAltura = superficie_Texto->h;
		SDL_FreeSurface(superficie_Texto);
	}
	return mTextura != NULL;
}

// função que apaga a textura mas recente carregada, e redifine suas dimensões para o valor de 0
void LTextura::free()
{
	// Caso mTextura não esteja vazio, o que este armazena e suas dimensões serão redefinidas
	if (mTextura != NULL)
	{
		SDL_DestroyTexture(mTextura);
		mTextura = NULL;
		mLargura = 0;
		mAltura = 0;
	}
}

// funçao para realizar a modulação das cores de uma textura 
void LTextura::setColor(Uint8 r, Uint8 g, Uint8 b)
{
	SDL_SetTextureColorMod(mTextura, r, g, b);
}

void LTextura::setBlendMode(SDL_BlendMode blending)
{
	SDL_SetTextureBlendMode(mTextura, blending);
}

void LTextura::setAlpha(Uint8 alpha)
{
	SDL_SetTextureAlphaMod(mTextura, alpha);
}


// função que renderiza uma textura na janela recebendo sua posição(x,y), um SDL_Rect para o caso
// de ser necessário renderizar apenas uma parcela da imagem carregada, um ângulo de rotação,
// um SDL_Point para definir um ponto de referência para a rotação, e um SDL_RendererFlip para
// espelhar sua posição na vertical e horizontal.
void LTextura::renderizar(int x, int y, SDL_Rect* clip, double angulo, SDL_Point* centro, SDL_RendererFlip flip)
{
	// Como a variável clip representa a SDL_Rect em que será armazenada a parcela da textura,
	// a variável renderQuad é utilizada para especificar a posição x,y e as dimensões de tal
	// parcela.
	SDL_Rect renderQuad = { x,y,mLargura,mAltura };
	// Caso o parâmetro clip esteja preenchido com o endereço de algum SDL_Rect...
	if (clip != NULL)
	{
		// A largura de renderQuad recebe o valor da largura de clip
		renderQuad.w = clip->w;
		// A altura de renderQuad recebe o valor da altura de clip
		renderQuad.h = clip->h;
		// Dessa maneira só é necessário preencher os valores das dimensões da SDL_Rect que for
		// definir o parâmetro clip 
	}
	SDL_RenderCopyEx(gRenderizador, mTextura, clip, &renderQuad, angulo, centro, flip);
}

// função que retorna a variável mLargura;
int LTextura::getLargura()
{
	return mLargura;
}

// função que retorna a variável mAltura;
int LTextura::getAltura()
{
	return mAltura;
}




