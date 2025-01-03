#include <SDL2/SDL.h>   //equivalent to graphics.h
#include <SDL2/SDL_render.h>

// Wait for a key press or a quit event to close the window
void SDL_Getch(){
    SDL_Event event;
    int quit = 0;

    while (!quit) {
        if (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = 1;  // Quit on window close
            }
            if (event.type == SDL_KEYDOWN) {
                quit = 1;  // Quit on any key press
            }
        }
    }
}

// Clean up and close
void SDL_Close(SDL_Renderer *renderer, SDL_Window *window){
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void drawFunc(SDL_Renderer *renderer, float points[]);

int SDL_Start(float coords[]){
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        SDL_Log("SDL_Init Error: %s", SDL_GetError());
        return 1;
    }

    // Create a window
    SDL_Window *window = SDL_CreateWindow("SDL2 Window",
                                          SDL_WINDOWPOS_CENTERED,
                                          SDL_WINDOWPOS_CENTERED,
                                          1000, 600,    // set the required window resolution here
                                          SDL_WINDOW_SHOWN);
    if (window == NULL) {
        SDL_Log("SDL_CreateWindow Error: %s", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    // Create a renderer
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL) {
        SDL_Log("SDL_CreateRenderer Error: %s", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    // Set the background color (black)
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer); // Clear the window with the background color

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);  // Set the default draw color white
    
    drawFunc(renderer, coords);

    // Present the renderer to display the pixel(s)
    // Uncomment only if you haven't used it in your source code
    // SDL_RenderPresent(renderer); //don't call consequently

    SDL_Getch();

    // Wait for x millisecond(s) before closing the window
    SDL_Delay(1000);

    SDL_Close(renderer, window);
}