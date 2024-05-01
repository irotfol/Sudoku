#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
#include <raylib.h>
#include "potentional.h"

bool print_table(Vector2* mouse_pos, short *grid) {
    short pos_x = 0;
    short pos_y = 0;
    static short rect_size = 55;
    const short con_x = (rect_size / 2);
    static short betw_cells_thickness = 5;
    static short betw_subg_thickness = 3;
    short i = 0;
    short j = 0;
    KeyboardKey key = 0;
    Color rect_color = RAYWHITE;
    char *digit = malloc(2 * sizeof(char));
    pos_y = rect_size - 5;
    for (i = 0; i < 9; i++) {
        j = 0;
        pos_x = con_x;
        for (j = 0; j < 9; j++) {
            if ((mouse_pos->x != 0) && (mouse_pos->y != 0)) {
                if ((mouse_pos->x >= pos_x) && (mouse_pos->x <= (pos_x + rect_size)) && (mouse_pos->y >= pos_y) && (mouse_pos->y <= (pos_y + rect_size))) {
                    rect_color = BLUE;
                    key = GetKeyPressed();
                    switch (key)
                    {
                    case KEY_ZERO:
                        *(grid) = 0;
                        break;
                    case KEY_DELETE:
                        *(grid) = 0;
                        break;
                    case KEY_BACKSPACE:
                        *(grid) = 0;
                        break;
                    case KEY_ONE:
                        *(grid) = 1;
                        break;
                    case KEY_TWO:
                        *(grid) = 2;
                        break;
                    case KEY_THREE:
                        *(grid) = 3;
                        break;
                    case KEY_FOUR:
                        *(grid) = 4;
                        break;
                    case KEY_FIVE:
                        *(grid) = 5;
                        break;
                    case KEY_SIX:
                        *(grid) = 6;
                        break;
                    case KEY_SEVEN:
                        *(grid) = 7;
                        break;
                    case KEY_EIGHT:
                        *(grid) = 8;
                        break;
                    case KEY_NINE:
                        *(grid) = 9;
                        break;
                    }
                }
                else {
                    rect_color = RAYWHITE;
                }
            }
            DrawRectangle(pos_x, pos_y, rect_size, rect_size, rect_color);
            if (*(grid) != 0) {
                sprintf(digit, "%hu", *(grid));
                DrawText(digit, pos_x + 10, pos_y + 5, rect_size - 5, BLACK);
            }
            if ((j + 1) % 3 == 0) {
                pos_x = pos_x + betw_subg_thickness;
            }
            pos_x = pos_x + rect_size + betw_cells_thickness;
            grid++;
        }
        if ((i + 1) % 3 == 0) {
            pos_y = pos_y + betw_subg_thickness;
        }
        pos_y = pos_y + rect_size + betw_cells_thickness;
    }
    free(digit);
    return 0;
}

short finish(short *grid, bool* fl) {
    short i = 0;
    if (*fl == true) {
        return 1;
    }
    for (i = 0; i < 81; i++) {
        if (*(grid) == 0) {
            return 0;
        }
        grid++;
    }
    return 2;
}


bool main(void) {
    bool potentional_digit[9][9][9];
    bool flag = false;
    bool paused = true;
    short fin = 0;
    Vector2 Maus = GetMousePosition();
    Maus.x = 0;
    Maus.y = 0;
    short sudoku_game[9][9] =
    {       {0, 8, 0, 0, 0, 0, 0, 9, 0},
            {0, 7, 0, 0, 6, 0, 2, 1, 0},
            {0, 0, 6, 0, 4, 8, 7, 0, 0},
            {8, 0, 0, 0, 0, 0, 5, 3, 0},
            {0, 2, 0, 0, 0, 0, 0, 0, 0},
            {1, 6, 3, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 4, 0, 1, 9, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 7, 0},
            {2, 0, 9, 7, 0, 0, 0, 0, 5}
        /*{0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0}*/ };
    InitWindow(600, 600, "Sudoku");
    SetTargetFPS(15);
    while (!WindowShouldClose()) {
        Maus.x = 0;
        Maus.y = 0;
        BeginDrawing();
        ClearBackground(BLACK);
        if (fin == 1) {
            DrawText("Too strong sudoku :(", 60, 5, 45, RED);
        }
        else {
            DrawText("Sudoku", 210, 5, 45, RAYWHITE);
            if (fin == 2) {
                DrawText("solved!", 400, 5, 45, GREEN);
            }
            else {
                Maus = GetMousePosition();
            }
        }
        print_table(&Maus, &sudoku_game);
        if ((IsKeyPressed(KEY_ENTER)) && ((fin == 0))){
                paused = !paused;
        }
        if (!paused) {
            clear_potentional_digits(sudoku_game, potentional_digit);
            potentional_digits_all(sudoku_game, potentional_digit);
            flag = potentional_digits_insert(&sudoku_game, potentional_digit);
            fin = finish(&sudoku_game, &flag);       
            paused = true;
        }
        EndDrawing();
    }
    CloseWindow();

    return 0;
}