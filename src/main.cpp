#include <SDL2/SDL.h>
#include <stdio.h>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

int main(int argc, char* args[]) {
    SDL_Window* window = NULL;
    SDL_Surface* surface = NULL;
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        fprintf(stderr, "could not initialize sdl2: %s\n", SDL_GetError());
        return 1;
    }
    window = SDL_CreateWindow(
                            "SDL2 Event loop",
                            SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                            SCREEN_WIDTH, SCREEN_HEIGHT,
                            SDL_WINDOW_SHOWN
                            );
    if (window == NULL) {
        fprintf(stderr, "could not create window: %s\n", SDL_GetError());
        return 1;
    }
    surface = SDL_GetWindowSurface(window);
    SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, 0xFF, 0xFF, 0xFF));

    SDL_Event ev;
    while( SDL_WaitEvent(&ev) ) {
        switch(ev.type){
        case SDL_QUIT:
            printf("QUIT\n");
            SDL_DestroyWindow(window);
            SDL_Quit();
            break;
        case SDL_KEYDOWN:
            printf("KeyDonw\n");
            break;
        case SDL_MOUSEBUTTONDOWN:
            printf("MouseDown\n");
            break;
        case SDL_TEXTINPUT:
            printf("SDL_TEXTINPUT: %s\n", ev.text.text);
            break;
        case SDL_TEXTEDITING:
            printf("SDL_TEXTINPUT: %s\n", ev.text.text);
            break;
        default:
            break;
        }
        SDL_UpdateWindowSurface(window);
    }
    return 0;
}
