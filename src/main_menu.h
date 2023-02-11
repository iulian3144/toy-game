#ifndef _MAIN_MENU_H_
#define _MAIN_MENU_H_

#include <raylib.h>

typedef enum {
    BUTTON_BEGIN,
    BUTTON_PLAY = 0,
    BUTTON_SETTINGS,
    BUTTON_QUIT,
    BUTTON_END = BUTTON_QUIT
} ENUM_ROW_SELECTOR;

typedef void (*menuitem_cb)();

typedef struct {
    char *title;
    int posX;
    int posY;
    menuitem_cb callback;
    int fontSize;
    Color color;
} menuitem_t;

void MainMenu_Init();
void MainMenu_Update(float delta_in_seconds);
void MainMenu_Render();

#endif
