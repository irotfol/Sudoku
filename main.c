#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
#include <raylib.h>
#include "potentional.h"

void print_table(Vector2 mouse_pos, short screenW, short screenH, short grid[9][9]) {
    short pos_x = 0;
    short pos_y = 0;
    short rect_size = 30;
    short i = 0;
    short j = 0;
    KeyboardKey key = 0;
    Color rect_color = RAYWHITE;
    char *digit = malloc(2 * sizeof(char));
    for (i = 0; i < 9; i++) {
        j = 0;
        for (j = 0; j < 9; j++) {
            pos_x = (j + 1) * screenW / 9 - 60;
            pos_y = (i + 1) * screenH / 10 + 15;
            if ((mouse_pos.x >= pos_x) && (mouse_pos.x <= (pos_x + rect_size)) && (mouse_pos.y >= pos_y) && (mouse_pos.y <= (pos_y + rect_size))){
                rect_color = BLUE;
                key = GetKeyPressed();
                switch (key)
                {
                case KEY_ZERO:
                    grid[i][j] = 0;
                    break;
                case KEY_DELETE:
                    grid[i][j] = 0;
                    break;
                case KEY_BACKSPACE:
                    grid[i][j] = 0;
                    break;
                case KEY_ONE:
                    grid[i][j] = 1;
                    break;
                case KEY_TWO:
                    grid[i][j] = 2;
                    break;
                case KEY_THREE:
                    grid[i][j] = 3;
                    break;
                case KEY_FOUR:
                    grid[i][j] = 4;
                    break;
                case KEY_FIVE:
                    grid[i][j] = 5;
                    break;
                case KEY_SIX:
                    grid[i][j] = 6;
                    break;
                case KEY_SEVEN:
                    grid[i][j] = 7;
                    break;
                case KEY_EIGHT:
                    grid[i][j] = 8;
                    break;
                case KEY_NINE:
                    grid[i][j] = 9;
                    break;
                default:
                    break;
                }
            }
            else {
                rect_color = RAYWHITE;
            }
            DrawRectangle(pos_x, pos_y, rect_size, rect_size, rect_color);
            if (grid[i][j] != 0) {
                sprintf(digit, "%hu", grid[i][j]);
                DrawText(digit, pos_x + 10, pos_y + 4, 25, BLACK);
            }
        }
    }
    free(digit);
}

short finish(short grid[9][9], bool fl) {
    short i = 0;
    short j = 0;
    short amount = 0;
    for (i = 0; i < 9; i++) {
        j = 0;
        for (j = 0; j < 9; j++) {
            if (grid[i][j] == 0) {
                amount++;
            }
        }
    }
    if (fl == true){
        return 1;
    }
    if (amount == 0) {
        return 2;
    }
    else
    {
        return 0;
    }
}


int main(void) {
    bool potentional_digit[9][9][9];
    bool flag = false;
    short fin = 0;
    Vector2 Maus = GetMousePosition();
    bool paused = true;
    short sudoku_game[9][9] =
    {     /*{0, 8, 0, 0, 0, 0, 0, 9, 0},
            {0, 7, 0, 0, 6, 0, 2, 1, 0},
            {0, 0, 6, 0, 4, 8, 7, 0, 0},
            {8, 0, 0, 0, 0, 0, 5, 3, 0},
            {0, 2, 0, 0, 0, 0, 0, 0, 0},
            {1, 6, 3, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 4, 0, 1, 9, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 7, 0},
            {2, 0, 9, 7, 0, 0, 0, 0, 5}*/
            {0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0}};
    //raylib
    const int screenWidth = 800;
    const int screenHeight = 600;
    InitWindow(screenWidth, screenHeight, "Sudoku");
    SetTargetFPS(60);
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);
        Maus = GetMousePosition();
        DrawText("Sudoku", screenWidth / 2 - 50, 20, 35, RAYWHITE);
        print_table(Maus ,screenWidth, screenHeight, sudoku_game);
        if (fin == 1) {
            DrawText("too strong sudoku :(", screenWidth / 2 - 240, screenHeight / 2 - 25, 50, RED);
        }
        if (fin == 2) {
            DrawText("sudoku solved", screenWidth / 2 - 180, screenHeight / 2 - 25, 50, GREEN);
        }
        if ((IsKeyPressed(KEY_ENTER)) && ((fin == 0))){
                paused = !paused;
        }
        if (!paused) {
            clear_potentional_digits(sudoku_game, potentional_digit);
            potentional_digits_all(sudoku_game, potentional_digit);
            flag = potentional_digits_insert(sudoku_game, potentional_digit);
            fin = finish(sudoku_game, flag);
            paused = true;
        }
        EndDrawing();
    }
    CloseWindow();
    //
    return 0;
}