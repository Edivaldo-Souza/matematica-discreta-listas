#pragma once
#include <SDL.h>
#include <SDL_ttf.h>
#include <string>

// Classe das TEXTURAS
class LTextura
{
public:

	// função que atribui os valores inicias as variáveis da classe
	LTextura();

	// função que redefine os valores das variáveis da classe para como iniciamente foram definidas em LTextura()
	~LTextura();

	// função que recebe uma string correspondente ao caminho(nome_da_pasta/imagem.png) da imagem a ser definida como textura 
	bool loadFromFile(std::string path, Uint32 r, Uint32 g, Uint32 b);

	bool carregarTexto(std::string textoTextura, SDL_Color corDoTexto,TTF_Font* font);

	// função que apaga a textura mas recente carregada, e redifine suas dimensões para o valor de 0 
	void free();

	// funçao para realizar a modulação das cores de uma textura 
	void setColor(Uint8 r, Uint8 g, Uint8 b);

	void setBlendMode(SDL_BlendMode blending);

	void setAlpha(Uint8 alpha);

	// função que renderiza uma textura na janela recebendo sua posição(x,y), um SDL_Rect para o caso
	// de ser necessário renderizar apenas uma parcela da imagem carregada, um ângulo de rotação,
	// um SDL_Point para definir um ponto de referência para a rotação, e um SDL_RendererFlip para
	// espelhar sua posição na vertical e horizontal.
	void renderizar(int x, int y, SDL_Rect* clip = NULL, double angulo = 0.0, SDL_Point* centro = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE);

	// função que retorna a variável mLargura;
	int getLargura();

	// função que retorna a variável mAltura;
	int getAltura();

private:

	// Variável que recebe a textura para os objetos da classe LTextura
	SDL_Texture* mTextura;

	// inteiro que recebe a largura da textura
	int mLargura;

	// inteiro que recebe a altura da textura
	int mAltura;
};

class Elemento
{
public:
	static const int tamContainer = 40;

	Elemento() {
		x_pos = 0;
		y_pos = 0;
	}

	void setAtributos(int x, int y, int valor,TTF_Font* font) {
		x_pos = x;
		y_pos = y;
		valorDoConjunto = valor;
		std::string valorTexto = std::to_string(valor);
		textura.carregarTexto(valorTexto, {0,0,0,255}, font);
		container.x = x;
		container.y = y;
		if (valor <= 9) { container.w = 20; }
		else { container.w = tamContainer; }
		container.h = tamContainer;
	}

	void renderizar() {
		textura.renderizar(x_pos, y_pos);
	}

	SDL_Rect* getContainer() {
		return &container;
	}

	int getCentroX() {
		int c = (x_pos + tamContainer / 2);
		return c;
	}

	int getCentroY() {
		int c = (y_pos + tamContainer / 2);
		return c;
	}

	int getValor() {
		return valorDoConjunto;
	}

private:
	int x_pos;
	int y_pos;
	int valorDoConjunto;
	LTextura textura;
	SDL_Rect container;
};
