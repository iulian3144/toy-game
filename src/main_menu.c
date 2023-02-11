#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <raylib.h>

#include "game.h"
#include "main_menu.h"



/* Private declarations */
static void draw_element(menuitem_t *e);
static int interpolate_position(int current, int target, float delta);



static menuitem_t elements[] = {
    [BUTTON_PLAY] = {
        .title    = "Play",
        .posX     = 200,
        .posY     = 80,
        .callback = Game_Start,
        .fontSize = 20,
        .color    = BLACK
    },
    [BUTTON_SETTINGS] = {
        .title    = "Settings",
        .posX     = 200,
        .posY     = 120,
        .callback = Game_Settings,
        .fontSize = 20,
        .color    = BLACK
    },
    [BUTTON_QUIT] =  {
        .title    = "Quit",
        .posX     = 200,
        .posY     = 160,
        .callback = Game_Quit,
        .fontSize = 20,
        .color    = BLACK
    }
};
static menuitem_t *selected_element = &elements[0];


menuitem_t selector = {
    .title = ">",
    .posX  = 0,
    .posY  = 0,
    .callback = NULL,
    .fontSize = 20,
    .color = BLUE
};



void MainMenu_Init() {
    selector.posY = selected_element->posY;
}



void MainMenu_Update(float delta_in_seconds) {
    static menuitem_t *last_element = NULL;
    static double last_selection_change = -1;
    double current_time = GetTime();
    int target_pos;

    /* handle repeated key presses separately from continously pressed keys */
    if (IsKeyPressed(KEY_UP) || IsKeyPressed(KEY_DOWN)) {
        last_selection_change = current_time;
        if (IsKeyPressed(KEY_UP)) { selected_element--; }
        else                      { selected_element++; }
    } else if (current_time - last_selection_change > 0.2f) {
        last_selection_change = current_time;
        if (IsKeyDown(KEY_UP))    { selected_element--; }
        if (IsKeyDown(KEY_DOWN))  { selected_element++; }
    }

    if (selected_element > &elements[BUTTON_END]) {
        selected_element = &elements[BUTTON_BEGIN];
    }

    if (selected_element < &elements[BUTTON_BEGIN]) {
        selected_element = &elements[BUTTON_END];
    }

    if (last_element != selected_element && last_element) {
        last_element->color = BLACK;
        PlaySound(*GameInstance.sounds[0]);
    }

    /* calculate button selector position */
    selector.posX = selected_element->posX - 20;
    target_pos = selected_element->posY;
    selector.posY = interpolate_position(selector.posY, target_pos, delta_in_seconds);

    if (IsKeyPressed(KEY_ENTER) && selected_element->callback) {
        selected_element->callback();
    }

    int cmp = memcmp(&selected_element->color, &WHITE, sizeof(Color));
    if (cmp && selector.posY == target_pos) {
        selected_element->color = WHITE;
    }
    last_element = selected_element;
}



void MainMenu_Render() {
    draw_element(&selector);
    DrawRectangle(selected_element->posX-3, selector.posY - 3, 200, selector.fontSize+6, RED);

    for (size_t i = 0; i <= BUTTON_END; i++) {
        draw_element(&elements[i]);
    }
}



static void draw_element(menuitem_t *e) {
    DrawText(TextFormat("%s", e->title), e->posX, e->posY, e->fontSize, e->color);
}



static int interpolate_position(int current, int target, float delta) {
    int ret = current;
    int speed_pps = 1200;

    /* return target if we're close */
    if (abs(target-current) < (int)(delta * speed_pps)) return target;

    if (current < target) {
        ret = current + delta * speed_pps;
    }

    if (current > target) {
        ret = current - delta * speed_pps;
    }

    return ret;
}
