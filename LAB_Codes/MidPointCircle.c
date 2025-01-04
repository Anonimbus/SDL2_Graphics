#include <stdio.h>
#include "../sdl_custom_header.h"

void drawFunc(SDL_Renderer *renderer, int points[]){
    int x = 0;
    int h = points[0];
    int k = points[1];
    int rad = points[2];
    int p = 1 - rad;
    void circlePlotPoints (SDL_Renderer *renderer, int, int, int, int);

    //plot first set of points
    circlePlotPoints(renderer, h, k, x, rad);
    SDL_RenderDrawPoint(renderer, h, k);    //center

    while ( x < rad ){
        x++;
        if (p < 0)
            p += 2 * x + 1;
        else{
            rad--;
            p += 2 * (x - rad) + 1;
        }
        circlePlotPoints(renderer, h, k, x, rad);
        SDL_Delay(10);  //adding delay of 10 ms for drawing each pixel
        SDL_RenderPresent(renderer);    //updates the window
    }
}

void circlePlotPoints(SDL_Renderer *renderer, int h, int k, int x, int rad){


    SDL_RenderDrawPoint(renderer, h + x, k + rad);
    SDL_RenderDrawPoint(renderer, h - x, k + rad);
    SDL_RenderDrawPoint(renderer, h + x, k - rad);
    SDL_RenderDrawPoint(renderer, h - x, k - rad);

    SDL_RenderDrawPoint(renderer, h + rad, k + x);
    SDL_RenderDrawPoint(renderer, h - rad, k + x);
    SDL_RenderDrawPoint(renderer, h + rad, k - x);
    SDL_RenderDrawPoint(renderer, h - rad, k - x);

}

int main(){
    int h,k,r;
    printf("Enter the coordinates of circle's center (h,k) : ");
    scanf("%d %d", &h, &k);
    printf("Enter the radius of circle : ");
    scanf("%d", &r);

    int points[3] = {h,k,r};

    SDL_Start(points);
}