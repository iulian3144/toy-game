#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include <raylib.h>

#include "game.h"



Game GameInstance = {0};
static char assets_path[128] = "./assets";



void Game_Init() {
    const int screenWidth = 800;
    const int screenHeight = 450;

    GameInstance.running = true;
    TextCopy(GameInstance.title, GAME_TITLE);

    SetTraceLogLevel(LOG_INFO);

    SetTargetFPS(GAME_FPS);
    SetConfigFlags(FLAG_VSYNC_HINT);

    InitWindow(screenWidth, screenHeight, GameInstance.title);
    /* need to do this after InitWindow so that the default font gets loaded (LoadFontDefault()) */

    InitAudioDevice();

    /* load sounds */
    char path[128];
    snprintf(path, 128, "%s/select.wav", GetAssetsPath());
    Sound sound = LoadSound(path);
    GameInstance.sounds[0] = &sound;
}



void Game_DeInit(void) {
    CloseAudioDevice();

    /* Close window and OpenGL context */
    CloseWindow();
}



void Game_Update(float delta_in_seconds) {
    (void)delta_in_seconds;
    if (WindowShouldClose() && !IsKeyPressed(KEY_ESCAPE)) {
        GameInstance.running = false;
    }
}



void Game_Start() {
    printf("Starting game...\n");
}



void Game_Settings() {
    printf("Settings\n");
}



void Game_Quit() {
    printf("Shutting down...\n");
    GameInstance.running = false;
}



char *GetAssetsPath(void) {
    return assets_path;
}



void SetAssetsPath(char *path) {
    TextCopy(assets_path, path);
}
