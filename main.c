#include <stdio.h>
#include <stdbool.h>
#include <math.h>

void print_table(short grid[9][9]) {
        short i = 0;
        short j = 0;
        for (i = 0; i < 9; i++) {
                j = 0;
                for (j = 0; j < 9; j++) {
                        if (grid[i][j] != 0) {
                                printf("%i ", grid[i][j]);
                        }
                        else {
                                printf("_ ");
                        }
                }
                printf("\n");
        }
}

int potentional_digits_print(bool potent_digit[9][9][9]) {
        short i = 0;
        short j = 0;
        short k = 0;
        for (i = 0; i < 9; i++) {
                j = 0;
                for (j = 0; j < 9; j++) {
                        k = 0;
                        printf("(");
                        for (k = 0; k < 9; k++) {
                                if (potent_digit[i][j][k] == true) {
                                        printf("%i", (k + 1));
                                }
                        }
                        printf(")");
                }
                printf("\n");
        }
        return 0;
}

int clear_potentional_digits(short grid[9][9], bool potent_digit[9][9][9]) {
        short i = 0;
        short j = 0;
        short k = 0;
        for (i = 0; i < 9; i++) {
                j = 0;
                for (j = 0; j < 9; j++) {
                        k = 0;
                        for (k = 0; k < 9; k++) {
                                if (grid[i][j] == 0) {
                                        potent_digit[i][j][k] = true;
                                }
                                else
                                {
                                        potent_digit[i][j][k] = false;
                                }
                        }
                }
        }
        return 0;
}

int potentional_digits_subgrid(short grid[9][9], short y, short x, bool potent_digit[9][9][9]) {
        short i = 0;
        short j = 0;
        short k = 0;
        short sub_end_x = (int)floor(x / 3);
        sub_end_x = (sub_end_x * 3) + 2;
        short sub_end_y = (int)floor(y / 3);
        sub_end_y = (sub_end_y * 3) + 2;
        for (i = sub_end_y - 2; i <= sub_end_y; i++) {
                j = 0;
                for (j = sub_end_x - 2; j <= sub_end_x ;j++) {
                        k = 0;
                        for (k = 0; k < 9; k++) {
                                if ((k + 1) == grid[i][j]) {
                                        potent_digit[y][x][k] = false;
                                }
                        }
                }
        }
        return 0;
}

int potentional_digits_collumn(short grid[9][9], short y, short x, bool potent_digit[9][9][9]) {
        short i = 0;
        short k = 0;
        for (i = 0; i < 9; i++) {
                k = 0;
                for (k = 0; k < 9; k++) {
                        if ((k + 1) == grid[i][x]) {
                                potent_digit[y][x][k] = false;
                        }
                }
        }
        return 0;
}

int potentional_digits_row(short grid[9][9], short y, short x, bool potent_digit[9][9][9]) {
        short j = 0;
        short k = 0;
        for (j = 0; j < 9; j++) {
                k = 0;
                for (k = 0; k <= 9; k++) {
                        if ((k + 1) == grid[y][j]) {
                                potent_digit[y][x][k] = false;
                        }
                }
        }
        return 0;
}

int potentional_digits(short grid[9][9], short y, short x, bool potent_digit[9][9][9]) {
        potentional_digits_row(grid, y, x, potent_digit);
        potentional_digits_collumn(grid, y, x, potent_digit);
        potentional_digits_subgrid(grid, y, x, potent_digit);
        return 0;
}

int potentional_digits_all(short grid[9][9], bool potent_digit[9][9][9]) {
        short i = 0;
        short j = 0;
        for (i = 0; i < 9; i++) {
                j = 0;
                for (j = 0; j < 9; j++) {
                        potentional_digits(grid, i, j, potent_digit);
                }
        }
        return 0;
}
int potentional_digits_insert(short grid[9][9], bool potent_digit[9][9][9]) {
        short i = 0;
        short j = 0;
        short k = 0;
        short inser = 0;
        short amount = 0;
        for (i = 0; i < 9; i++) {
                j = 0;
                for (j = 0; j < 9; j++) {
                        amount = 0;
                        for (k = 0; k < 9; k++) {
                        		if (potent_digit[i][j][k] == true) {
                        				amount++;
                        				inser = k + 1;
                        		}
                		}
                		if (amount == 1) {
                			grid[i][j] = inser;
                		}
                }
        }
        return 0;
}

bool finish(short grid[9][9]) {
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
        if (amount == 0) {
        return 1;
        } else
        {
        	return 0;
        }
}


int main(void) {
        short i = 0;
        short j = 0;
        bool potentional_digit[9][9][9];
        short sudoku_game[9][9] =
        {        {5, 0, 0, 6, 2, 7, 9, 4, 8},
                {0, 0, 0, 0, 0, 0, 0, 0, 0},
                {0, 2, 0, 5, 9, 4, 6, 0, 0},
                {0, 0, 6, 1, 0, 0, 0, 0, 0},
                {0, 1, 8, 0, 0, 9, 0, 5, 4},
                {7, 0, 0, 0, 0, 0, 1, 0, 9},
                {9, 6, 2, 4, 0, 0, 0, 8, 7},
                {3, 7, 4, 9, 8, 0, 0, 1, 0},
                {0, 0, 5, 0, 3, 6, 0, 0, 2} };
        print_table(sudoku_game);
        while (finish(sudoku_game) == 0) {
        		clear_potentional_digits(sudoku_game, potentional_digit);
        		potentional_digits_all(sudoku_game, potentional_digit);
        		potentional_digits_insert(sudoku_game, potentional_digit);
        printf("\n");
        print_table(sudoku_game);
        }
        return 0;
}