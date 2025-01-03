// To run the code from terminal, type : gcc -o app main.c -lSDL2

#include "sdl_custom_header.h"
#include <stdio.h>

void drawFunc(SDL_Renderer *renderer, float points[]){

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