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

int potentional_digits_subgrid_second(short grid[9][9], short sub_x, short sub_y ,bool potent_digit[9][9][9]) {
        short i = 0;
        short j = 0;
        short k = 0;
        short x = 0;
        short y = 0;
        short amount = 0;
        short sub_end_x = sub_x * 3 + 2;
        short sub_end_y = sub_y * 3 + 2;
        for (k = 0; k < 9; k++) {
        		i = 0;
        		amount = 0;
        		for (i = sub_end_y - 2; i <= sub_end_y; i++) {
                		j = 0;
                		for (j = sub_end_x - 2; j <= sub_end_x ;j++) {
                			if (potent_digit[i][j][k]) {
                				x = j;
                				y = i;
                				amount++;
                			}
                		}
                }
                if (amount == 1) {
                	for (amount = 0; amount < 9; amount++)
                	if (amount != k) {
                		potent_digit[y][x][amount] = false;
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

int potentional_digits_collumn_second(short grid[9][9], short column, bool potent_digit[9][9][9]) {
        short i = 0;
        short y = 0;
        short k = 0;
        short amount = 0;
        for (k = 0; k < 9; k++) {
                i = 0;
                amount = 0;
                for (i = 0; i < 9; i++) {
                        if (potent_digit[i][column][k]) {
                        		y = i;
                				amount++;
                		}
                }
                if (amount == 1) {
                	for (amount = 0; amount < 9; amount++)
                	if (amount != k) {
                		potent_digit[y][column][amount] = false;
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

int potentional_digits_row_second(short grid[9][9], short row, bool potent_digit[9][9][9]) {
        short x = 0;
        short j = 0;
        short k = 0;
        short amount = 0;
        for (k = 0; k < 9; k++) {
                j = 0;
                amount = 0;
                for (j = 0; j < 9; j++) {
                        if (potent_digit[row][j][k]) {
                        		x = j;
                				amount++;
                		}
                }
                if (amount == 1) {
                	for (amount = 0; amount < 9; amount++)
                	if (amount != k) {
                		potent_digit[row][x][amount] = false;
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
        for (i = 0; i < 9; i++) {
                potentional_digits_collumn_second(grid, i, potent_digit);
potentional_digits_row_second(grid, i, potent_digit);
                
        }
        for (i = 0; i < 3; i++) {
        	for (j = 0; j < 3; j++) {
        		potentional_digits_subgrid_second( grid, j, i, potent_digit);
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
                        				if (amount == 1){
                        					inser = k + 1;
                        				}
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
        if (amount == 0){
        	printf ("sudoku solved!\n");
        return 1;
        } else
        {
        	return 0;
        }
}


int main(void) {
        bool potentional_digit[9][9][9];
        short sudoku_game[9][9] =
        {       {2, 1, 0, 4, 0, 5, 0, 3, 0},
                {0, 0, 0, 0, 6, 0, 5, 0, 0},
                {0, 0, 4, 0, 9, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 6, 0, 0, 0},
                {0, 8, 0, 0, 0, 0, 0, 9, 0},
                {0, 0, 1, 5, 0, 2, 8, 0, 0},
                {3, 0, 0, 0, 0, 0, 0, 0, 7},
                {0, 0, 0, 0, 4, 0, 0, 0, 0},
                {0, 0, 2, 1, 0, 8, 9, 0, 0} };
        print_table(sudoku_game);
       do {
        clear_potentional_digits(sudoku_game, potentional_digit);
        potentional_digits_all(sudoku_game, potentional_digit);
 	potentional_digits_insert(sudoku_game, potentional_digit);
        printf("\n");
        potentional_digits_print( potentional_digit);
        print_table(sudoku_game);
        getchar();
        } while (finish(sudoku_game) == 0);
        return 0;
}