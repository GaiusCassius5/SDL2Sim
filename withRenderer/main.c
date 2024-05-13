#include <stdio.h>
#include <SDL2/SDL.h>
#include <stdbool.h>
#include "function.c"

//draw random points, positions colors

void draw_random_points(int numberPoints, bool randomizeColor,SDL_Renderer* renderer ){
    for(int i = 0; i < numberPoints; ++i){
        if(randomizeColor){
            SDL_SetRenderDrawColor(renderer, randomColor(), randomColor(), randomColor(), 255);
        }
        SDL_RenderDrawPoint(renderer, randomNumber(0, 800), randomNumber(0, 600));
    }
}

//draw random lines with random positions and colors
void draw_random_lines(int numberPoints, bool randomizeColor,SDL_Renderer* renderer ){
    for(int i = 0; i < numberPoints; ++i){
        if(randomizeColor){
            SDL_SetRenderDrawColor(renderer, randomColor(), randomColor(), randomColor(), 255);
        }
        SDL_RenderDrawLine(renderer, randomNumber(0, 800), randomNumber(0, 600), randomNumber(0, 800), randomNumber(0, 600));
    }
}

int main(int argc, int argv[])
{
    //initialize
    SDL_Init(SDL_INIT_VIDEO);
    //create a window

    SDL_Window* window = NULL;
     window = SDL_CreateWindow( "OKNO",
                                SDL_WINDOWPOS_CENTERED,
                                SDL_WINDOWPOS_CENTERED,
                                800, //add constants
                                600, //add constants
                                SDL_WINDOW_OPENGL); 

    // create renderer accelerated and synced with display refresh rate
    SDL_Renderer* renderer = NULL;
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
   
    int running = false;
    SDL_Event event;
    while(!running){
        //process events (quitting)
        while(SDL_PollEvent(&event) != 0){
            switch(event.type){
                case SDL_QUIT:
                    running = true;
                break;
            }
        }
    //draw background to black
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    
    //clear screen
    SDL_RenderClear(renderer);

    //draw a point
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    //draw_random_points(500, true, renderer);
    //draw_random_lines(500, true, renderer);

    //draw a rectangle
    SDL_Rect rectangle = {200,200, 400, 300};
    SDL_RenderFillRect(renderer, &rectangle);
    
    
    //update screen
    SDL_RenderPresent(renderer);

        //clear the screen
    }

   

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
