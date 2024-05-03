#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
#include <raylib.h>
#include <ctype.h>
#include "potentional.h"


bool print_table(Vector2* mouse_pos, short *grid) {
    short pos_x = 0;
    short pos_y = 0;
    short i = 0;
    short j = 0;
    static short rect_size = 55;
    const short con_x = (rect_size / 2);
    static short betw_cells_thickness = 5;
    static short betw_subg_thickness = 3;
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

bool savefile(char let, short table[9][9]) {
    FILE* fp;
    char fname[6] = { let, '\0' };
    strcat(fname, ".txt");
    unsigned short i = 0;
    unsigned short j = 0;
    char symbol[2] = { '\0' };
    fp = fopen(fname, "wb");
    if (!fp) {
        fprintf(stderr, "Error: Unable to open the output file!\n");
        return EXIT_FAILURE;
    }
    for (i = 0; i < 9; i++) {
        j = 0;
        for (j = 0; j < 9; j++) {
            if (table[i][j] != 0) {
                sprintf(symbol, "%d", table[i][j]);
            }
            else
            {
                symbol[0] = ' ';
            }
            fputs(symbol, fp);
        }
        fputs("\0", fp);
        fputs("\n", fp);
    }
    fclose(fp);
    return 0;
}

bool loadfile(char let, short table[9][9]) {
    FILE* fp;
    char fname[6] = { let, '\0' };
    strcat(fname, ".txt");
    unsigned short i = 0;
    unsigned short j = 0;
    int digit = 0;
    char str[11] = {'\0'};
    fp = fopen(fname, "r");
    if (!fp) {
        fprintf(stderr, "Error: Unable to open the output file!\n");
        return EXIT_FAILURE;
    }
    for (i = 0; i < 9; i++) {
        j = 0;
        fgets(str, 11, fp);
        for (j = 0; j < 9; j++) {
            if ((str[j] != '\n') && (str[j] != '\0')) {
                if (str[j] != ' ') {
                    digit = (int)(str[j]) - 48;
                    table[i][j] = digit;
                }
                else
                {
                    table[i][j] = 0;
                }
            }
        }
    }
    fclose(fp);
    return 0;
}

bool colis(Rectangle rect, Vector2 mouse_pos) {
    if ((mouse_pos.x >= rect.x) && (mouse_pos.y >= rect.y) && (mouse_pos.x <= (rect.x + rect.width)) && (mouse_pos.y <= (rect.y + rect.height))) {
        DrawRectangleRec(rect, BLUE);
        return true;
    }
    else {
        DrawRectangleRec(rect, RAYWHITE);
        return false;
    }

}

bool main(void) {
    bool potentional_digit[9][9][9];
    bool flag = false;
    bool paused = true;

    Rectangle load_button;
    load_button.x = 5;
    load_button.y = 25;
    load_button.width = 40;
    load_button.height = 20;

    Rectangle save_button;
    save_button.x = 50;
    save_button.y = 25;
    save_button.width = 40;
    save_button.height = 20;

    Rectangle file_name;
    file_name.x = 95;
    file_name.y = 5;
    file_name.width = 40;
    file_name.height = 40;

    short fin = 0;
    short key = 0;
    char letter[2] = { 's','\0' };
    Vector2 Maus = GetMousePosition();
    Maus.x = 0;
    Maus.y = 0;
    short sudoku_game[9][9] =
    {       {0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0} };
    InitWindow(600, 600, "Sudoku");
    SetTargetFPS(60);
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
        DrawText("Load", 10, 5, 15, RAYWHITE);
        if (colis(load_button, Maus)) {
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                loadfile(letter[0], sudoku_game);
            }
        }
        DrawText("Save", 50, 5, 15, RAYWHITE);
        if (colis(save_button, Maus)) {
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                savefile(letter[0], sudoku_game);
            }
        }
        if (colis(file_name, Maus)) {
            key = GetKeyPressed();
            if ((key >= 32) && (key <= 125))
            {
                letter[0] = tolower((char)key);
            }
        }
        DrawText(letter, 105, 5, 35, BLACK);
        print_table(&Maus, &sudoku_game);
        EndDrawing();
        if ((IsKeyPressed(KEY_ENTER)) && ((fin == 0))){
                paused = !paused;
        }
        if (!paused) {
            clear_potentional_digits(&sudoku_game, &potentional_digit);
            potentional_digits_all(sudoku_game, potentional_digit);
            flag = potentional_digits_insert(&sudoku_game, &potentional_digit);
            fin = finish(&sudoku_game, &flag);       
            paused = true;
        }
    }
    CloseWindow();

    return 0;
}