#ifndef _GAME_H_
#define _GAME_H_

#include <stdbool.h>

#include <raylib.h>



#define GAME_FPS 60
#define GAME_TITLE "Game"
#define GAME_VERSION "0.1.0"



typedef struct {
    bool running;
    char title[64];
} Game;



extern Game GameInstance;



void Game_DeInit(void);
void Game_Init(void);
void Game_Quit(void);
void Game_Settings(void);
void Game_Start(void);
void Game_Update(float delta_in_seconds);

char *GetAssetsPath(void);
void SetAssetsPath(char *);

#endif /* _GAME_H_ */
