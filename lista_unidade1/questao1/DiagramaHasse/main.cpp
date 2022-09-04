#include"ClassDefinicao.h"
#include"FuncaoDefinicao.h"


int main(int argc, char* args[]) {
	
	init();
	loadMedia();
	bool sair = false;

	SDL_Color cor = {0,0,0,255};
	SDL_Event e;

	Elemento memConjunto[8];
	memConjunto[0].setAtributos(200, 450, 2, gFonte);
	memConjunto[1].setAtributos(300, 150, 3, gFonte);
	memConjunto[2].setAtributos(300, 450, 4, gFonte);
	memConjunto[3].setAtributos(100, 250, 5, gFonte);
	memConjunto[4].setAtributos(100, 350, 8, gFonte);
	memConjunto[5].setAtributos(400, 350, 12, gFonte);
	memConjunto[6].setAtributos(400, 250, 24, gFonte);
	memConjunto[7].setAtributos(200, 150, 25, gFonte);

	const SDL_Rect* exe = memConjunto[0].getContainer();


	
	while (!sair) {
		while (SDL_PollEvent(&e)!=0) {
			if (e.type == SDL_QUIT) {
				sair = true;
			}
			else if (e.key.keysym.sym == SDLK_ESCAPE) {
				sair = true;
			}
		}

		SDL_SetRenderDrawColor(gRenderizador, 23, 128, 67, 255);
		SDL_RenderClear(gRenderizador);

		for (int i = 0; i < 8; i++) {
			
			SDL_SetRenderDrawColor(gRenderizador, 255, 0, 0, 255);
			for (int j = 0; j < 8; j++) {
				if (memConjunto[i].getValor() % memConjunto[j].getValor() == 0){
					
					SDL_RenderDrawLine(gRenderizador,
						memConjunto[i].getCentroX(),
						memConjunto[i].getCentroY(),
						memConjunto[j].getCentroX(),
						memConjunto[j].getCentroY());
				}
			}

		}

		SDL_SetRenderDrawColor(gRenderizador, 23, 128, 67, 255);
		for (int j = 0; j < 8; j++) {
			SDL_RenderFillRect(gRenderizador, memConjunto[j].getContainer());
			memConjunto[j].renderizar();
		}

		SDL_RenderPresent(gRenderizador);
	}
	close();
	return 0;
}