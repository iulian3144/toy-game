#include <stdbool.h>

#include <raylib.h>

#include "game.h"
#include "main_menu.h"



static struct {
    bool enabled;
    int fps;
    float frameTimeMs;
} statsHUD = {true, 0, 0.0f};



/* Private declarations */
static void HUD_Update(float delta_in_seconds);
static void HUD_Render(void);



int main(int argc, char *argv[])
{
    if (argc > 1) {
        SetAssetsPath(argv[1]);
    }
    /* --- Initialization --------------------------------------------------- */
    Game_Init();
    MainMenu_Init();

    float delta_in_seconds;
    /* Main game loop */
    while (GameInstance.running)
    {
        delta_in_seconds = GetFrameTime();

        /* --- Update ------------------------------------------------------- */
        Game_Update(delta_in_seconds);
        MainMenu_Update(delta_in_seconds);
        HUD_Update(delta_in_seconds);

        /* toggle FPS display if ALT+F key is pressed */
        if (IsKeyDown(KEY_LEFT_ALT) && IsKeyPressed(KEY_F)) {
            statsHUD.enabled = !statsHUD.enabled;
        }

        /* --- Draw --------------------------------------------------------- */
        BeginDrawing();

        ClearBackground(RAYWHITE);

        HUD_Render();
        MainMenu_Render(delta_in_seconds);

        EndDrawing();
    }

    Game_DeInit();

    return 0;
}



static void HUD_Update(float delta_in_seconds) {
    if (!statsHUD.enabled) return;

    statsHUD.fps = GetFPS();
    statsHUD.frameTimeMs = delta_in_seconds * 1e3;
}



static void HUD_Render() {
    static const Color bg_color = {0, 0, 0, 100};
    static const Color font_color = WHITE;
    static const int font_size = 10, x = 5, y = 5;

    if (statsHUD.enabled) {
        /* Display FPS and frame time */
        DrawRectangle(0, 0, 50, 35, bg_color);
        DrawText(TextFormat("%d FPS", statsHUD.fps), x, y, font_size, font_color);
        DrawText(TextFormat("%.1f ms", statsHUD.frameTimeMs), x, y+15, font_size, font_color);
    }
}
