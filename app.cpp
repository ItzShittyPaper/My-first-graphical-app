#ifdef WIN32
#include "SDL/include/SDL.h"
#undef main
#include "SDL/SDL_mixer.h"
#include "SDL/SDL_image.h"
#endif
#ifndef WIN32
#include "SDL2/SDL.h"
#include "SDL2/SDL_mixer.h"
#include "SDL2/SDL_image.h"
#else
#include "Windows.h"
#endif

#define SOUND_PATH "Caramelldansen.wav"

int SCREEN_WIDTH = 640;
int SCREEN_HEIGHT = 480;

int main( int argc, char* args[] )
{

    //define windows
    SDL_Window* window = NULL;
    SDL_Surface* screenSurface  = NULL;

    //define mixer
    Mix_OpenAudio(44100, AUDIO_S16SYS, 2, 2048);
    Mix_Music* music = Mix_LoadMUS("Caramelldansen.wav");

    if ( SDL_Init ( SDL_INIT_VIDEO | SDL_INIT_AUDIO ) < 0 ) {
        printf("O CHOLIBKA! Cos tu nie dziala :C");
    }
    else {

        //play caramelldansen
        Mix_PlayMusic(music, -1);

        //create window
        window = SDL_CreateWindow("WTF IS THIS SHIT", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

        if(window == NULL) {
            printf("O CHOLIBKA! GDZIE SIE OKNO PODZIALO?");
        }
        else {

        //init visuals
        for( ; ; ) {
            screenSurface = SDL_GetWindowSurface( window );
            SDL_FillRect(screenSurface, NULL, SDL_MapRGB( screenSurface->format, 0xFF, 0xFF, 0xFF) );
            SDL_UpdateWindowSurface(window);
            SDL_Delay(2000);
            screenSurface = SDL_GetWindowSurface( window );
            SDL_FillRect(screenSurface, NULL, SDL_MapRGB( screenSurface->format, 178, 34, 34) );
            SDL_UpdateWindowSurface(window);
            SDL_Delay(2000);
            screenSurface = SDL_GetWindowSurface( window );
            SDL_FillRect(screenSurface, NULL, SDL_MapRGB( screenSurface->format, 30, 144, 255) );
            SDL_UpdateWindowSurface(window);
            SDL_Delay(2000);
            screenSurface = SDL_GetWindowSurface( window );
            SDL_FillRect(screenSurface, NULL, SDL_MapRGB( screenSurface->format, 255, 140, 0) );
            SDL_UpdateWindowSurface(window);
            SDL_Delay(2000);
            }
        }
    }
}