#include <stdio.h>
#include "../sdl_custom_header.h"

#define ROUND(a) ((int) (a + 0.5))

void drawFunc(SDL_Renderer *renderer, int points[]){
    // points[4] = {h,k,a,b}
    int h = points[0];
    int k = points[1];
    int a = points[2];
    int b = points[3];
    int a2 = a * a;
    int b2 = b * b;
    int twoA2 = 2 * a2, twoB2 = 2 * b2;
    int p;
    int x = 0;
    int y = b;
    int px = 0;
    int py = twoA2 * y;
    void ellipsePlotPoints(SDL_Renderer *, int, int, int, int);

    ellipsePlotPoints(renderer, h, k, x, y);

    /*Region 1*/
    p = ROUND (b2 - (a2 * b) + (0.25 * a2));
    while (px < py){
        x++;
        px += twoB2;
        if(p < 0)
            p += b2 + px;
        else{
            y--;
            py -= twoA2;
            p += b2 + px - py;
        }
        ellipsePlotPoints(renderer, h, k, x, y);
        SDL_Delay(10);
        SDL_RenderPresent(renderer);
    }

    /*Region 2*/
    
}

void ellipsePlotPoints(SDL_Renderer *renderer, int h, int k, int x, int y){

    SDL_RenderDrawPoint(renderer, h + x, k + y);
    SDL_RenderDrawPoint(renderer, h - x, k + y);
    SDL_RenderDrawPoint(renderer, h + x, k - y);
    SDL_RenderDrawPoint(renderer, h - x, k - y);
}

int main(){
    int h, k, a, b;
    printf("Enter the coordinates of ellipse's center (h,k) : ");
    scanf("%d %d", &h, &k);
    printf("Enter the x and y radius of ellipse (a, b) : ");
    scanf("%d %d", &a, &b);

    int points[4] = {h,k,a,b};

    SDL_Start(points);
}