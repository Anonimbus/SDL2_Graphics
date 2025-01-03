#include "../sdl_custom_header.h"
#include <stdio.h>
#include <math.h>

void drawFunc(SDL_Renderer *renderer, float points[]){
    int xa=points[0],ya=points[1],xb=points[2],yb=points[3];

    int dx = abs(xa -xb), dy = abs(ya -yb);
    int p = 2 * dy - dx;
    int twoDy = 2*dy, twoDyDx = 2*(dy-dx);
    int x, y, xEnd;

    if (xa > xb){
        x = xb;
        y = yb;
        xEnd = xa;
    }
    else{
        x = xa;
        y = ya;
        xEnd = xb;
    }
    SDL_RenderDrawPoint(renderer, x, y);
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);  // Set the color

    while (x < xEnd){
        x++;
        if (p < 0)
            p += twoDy;
        else{
            y++;
            p += twoDyDx;
        }
        SDL_RenderDrawPoint(renderer, x, y);
        SDL_Delay(10);  //adding delay of 10 ms for drawing each pixel
        SDL_RenderPresent(renderer);    //updates the window
    }
}

int main(){
    int x1,y1,x2,y2;

    printf("Enter the start coordinates (x1,y1) :\n");
    scanf("%d %d",&x1,&y1);

    printf("\nEnter the end coordinates (x2,y2) :\n");
    scanf("%d %d",&x2,&y2);

    float points[4] = {x1,y1,x2,y2};
    SDL_Start(points);
    return 0;
}