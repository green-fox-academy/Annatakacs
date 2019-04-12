#include <iostream>
#include <SDL.h>

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

//Draws geometry on the canvas
void drawFirstTriangle();

void drawSecondTriangle();

void drawThirdTriangle(float i);

//Starts up SDL and creates window
bool init();

//Frees media and shuts down SDL
void close();


//The window we'll be rendering to
SDL_Window *gWindow = nullptr;

//The window renderer
SDL_Renderer *gRenderer = nullptr;

void drawFirstTriangle() {

    SDL_SetRenderDrawColor(gRenderer, 0x00 /*R*/, 0x00 /*G*/, 0x00 /*B*/, 0xFF /*A*/);
    SDL_RenderDrawLine(gRenderer, 0, 0, SCREEN_WIDTH, 0);

    SDL_RenderDrawLine(gRenderer, 0, 0, (SCREEN_WIDTH / 2), SCREEN_HEIGHT);

    SDL_RenderDrawLine(gRenderer, SCREEN_WIDTH, 0, (SCREEN_WIDTH / 2), SCREEN_HEIGHT);

    drawSecondTriangle();
}

void drawSecondTriangle() {

    float i = 0.5;

    SDL_SetRenderDrawColor(gRenderer, 0x00 /*R*/, 0x00 /*G*/, 0x00 /*B*/, 0xFF /*A*/);
    SDL_RenderDrawLine(gRenderer, (SCREEN_WIDTH / 4), (SCREEN_HEIGHT / 2), ((SCREEN_WIDTH * 3) / 4),
                       (SCREEN_HEIGHT / 2));

    SDL_RenderDrawLine(gRenderer, (SCREEN_WIDTH / 4), (SCREEN_HEIGHT / 2), (SCREEN_WIDTH / 2), 0);

    SDL_RenderDrawLine(gRenderer, ((SCREEN_WIDTH * 3) / 4), (SCREEN_HEIGHT / 2), (SCREEN_WIDTH / 2), 0);

    drawThirdTriangle(i);

    drawThirdTriangle(i/2);

    drawThirdTriangle(i/4);

    drawThirdTriangle(i/8);
}

void drawThirdTriangle(float i) {

    if (i < (i/12)) {
        return;
    } else {

        SDL_SetRenderDrawColor(gRenderer, 0x00 /*R*/, 0x00 /*G*/, 0x00 /*B*/, 0xFF /*A*/);
        SDL_RenderDrawLine(gRenderer, (SCREEN_WIDTH / 4) * i, (SCREEN_HEIGHT / 2) * i, ((SCREEN_WIDTH * 3) / 4) * i,
                           (SCREEN_HEIGHT / 2) * i);

        SDL_RenderDrawLine(gRenderer, (SCREEN_WIDTH / 4) * i, (SCREEN_HEIGHT / 2) * i, (SCREEN_WIDTH / 2) * i, 0 * i);

        SDL_RenderDrawLine(gRenderer, ((SCREEN_WIDTH * 3) / 4) * i, (SCREEN_HEIGHT / 2) * i, (SCREEN_WIDTH / 2) * i,
                           0 * i);

        ;

    }

}


bool init() {
    //Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout << "SDL could not initialize! SDL Error: " << SDL_GetError() << std::endl;
        return false;
    }

    //Create window
    gWindow = SDL_CreateWindow("To the center", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,
                               SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (gWindow == nullptr) {
        std::cout << "Window could not be created! SDL Error: " << SDL_GetError() << std::endl;
        return false;
    }

    //Create renderer for window
    gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
    if (gRenderer == nullptr) {
        std::cout << "Renderer could not be created! SDL Error: " << SDL_GetError() << std::endl;
        return false;
    }

    //Initialize renderer color
    SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

    return true;
}

void close() {
    //Destroy window
    SDL_DestroyRenderer(gRenderer);
    SDL_DestroyWindow(gWindow);
    gWindow = nullptr;
    gRenderer = nullptr;

    SDL_Quit();
}

int main(int argc, char *args[]) {
    //Start up SDL and create window
    if (!init()) {
        std::cout << "Failed to initialize!" << std::endl;
        close();
        return -1;
    }

    //Main loop flag
    bool quit = false;

    //Event handler
    SDL_Event e;

    //While application is running
    while (!quit) {
        //Handle events on queue
        while (SDL_PollEvent(&e) != 0) {
            //User requests quit
            if (e.type == SDL_QUIT) {
                quit = true;
            }
        }

        //Clear screen
        SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
        SDL_RenderClear(gRenderer);

        drawFirstTriangle();

        //Update screen
        SDL_RenderPresent(gRenderer);
    }

    //Free resources and close SDL
    close();

    return 0;
}