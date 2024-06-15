#include <SDL2/SDL.h>
#include <SDL2/SDL_stdinc.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_opengl.h>
#include <SDL2/SDL_video.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_image.h>

const struct SDL_Color white = {
    .a = 255,
    .r = 255,
    .g = 255,
    .b = 255
};

int main() {
    if (SDL_Init(SDL_INIT_VIDEO)) {
        puts("Failed to initialize SDL");
        return 1;
    }

    struct SDL_Window* window;
    if ((window = SDL_CreateWindow("ur gay", 0, 0, 512, 512, SDL_WINDOW_OPENGL)) == NULL) {
        puts("Failed to create window");
        goto exit;
    }

    struct SDL_Renderer* renderer; 
    if ((renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED)) == NULL) {
        puts("Failed to create renderer");
        goto exit;
    }

    if (!IMG_Init(IMG_INIT_PNG)) {
        puts("Failed to initialize SDL Image");
        goto exit;
    }

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    struct SDL_Vertex vertices[] = {
        {{100, 100}, white, {1, 1}},
        {{200, 100}, white, {1, 1}},
        {{100, 200}, white, {1, 1}},
    };

    SDL_RenderGeometry(renderer, NULL, vertices, 3, NULL, 0);
    SDL_RenderPresent(renderer);

    SDL_Delay(5000);

exit:
    SDL_Quit();
    return 0;
}
