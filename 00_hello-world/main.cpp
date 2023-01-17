#include <SDL.h>

constexpr Uint16 WINDOW_WIDTH = 800;
constexpr Uint16 WINDOW_HEIGHT = 600;

SDL_Window* gWindow = nullptr;
SDL_Renderer* gRenderer = nullptr;

int main(int argc, char* argv[]) {
	// Init SDL
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS);

	// Create window and renderer
	gWindow = SDL_CreateWindow("Hello world!", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN | SDL_WINDOW_ALLOW_HIGHDPI);
	gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);

	// Set draw color to white and fill the whole render target
	SDL_SetRenderDrawColor(gRenderer, 255, 255, 255, 255);
	SDL_RenderClear(gRenderer);

	// Set draw color to black and draw a filled rectangle
	SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, 255);
	SDL_Rect rect = { 100, 100, 300, 300 };
	SDL_RenderFillRect(gRenderer, &rect);

	// Present the rendered buffer to the screen
	SDL_RenderPresent(gRenderer);

	// Detect for quit event
	SDL_Event e;
	while (true) {
		SDL_PollEvent(&e);
		if (e.type == SDL_QUIT) {
			break;
		}
	}

	// Free the memory used and quit SDL
	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(gWindow);
	SDL_Quit();

	return 0;
}
