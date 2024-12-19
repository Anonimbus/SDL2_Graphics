#include <SDL2/SDL.h>   //equivalent to graphics.h
#include <stdio.h>

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

void drawLine(SDL_Renderer *renderer, float points[]){

    float x1=points[0],y1=points[1],x2=points[2],y2=points[3];
    int i,dx,dy,step;
    float xn,yn;

    dx = x2-x1;
    dy = y2-y1;
    
    if (abs(dx)>abs(dy)){
        step = abs(dx);
    }
    else {
        step = abs(dy);
    }

    xn = (float)dx/step;
    yn = (float)dy/step;

    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);  // Set the color

    for (i=1;i<=step;i++){
        SDL_RenderDrawPoint(renderer, (int)x1, (int)y1);           // Draw the pixel
        x1 = x1+xn;
        y1 = y1+yn;

        //animating the creation of the line
        SDL_Delay(10);  //adding delay of 10 ms for drawing each pixel
        SDL_RenderPresent(renderer);    //updates the window
    }
}

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

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);  // Set the default draw color white

    drawLine(renderer, coords);

    // Present the renderer to display the pixel(s)
    // SDL_RenderPresent(renderer);     //if called again it cleared the screen

    SDL_Getch();

    // Wait for x millisecond(s) before closing the window
    SDL_Delay(1000);

    SDL_Close(renderer, window);
}

int main() {
    int x1,y1,x2,y2;

    printf("Enter the start coordinates (x1,y1) :\n");
    scanf("%d %d",&x1,&y1);

    printf("\nEnter the end coordinates (x2,y2) :\n");
    scanf("%d %d",&x2,&y2);

    float points[4] = {x1,y1,x2,y2};

    SDL_Start(points);

    return 0;
}