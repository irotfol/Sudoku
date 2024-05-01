#pragma once
bool clear_potentional_digits(short *grid, bool *potent_digit);
bool potentional_digits_subgrid_second(short grid[9][9], short sub_x, short sub_y, bool potent_digit[9][9][9]);
bool potentional_digits_subgrid(short grid[9][9], short y, short x, bool potent_digit[9][9][9]);
bool potentional_digits_collumn_second(short grid[9][9], short column, bool potent_digit[9][9][9]);
bool potentional_digits_collumn(short grid[9][9], short y, short x, bool potent_digit[9][9][9]);
bool potentional_digits_row_second(short grid[9][9], short row, bool potent_digit[9][9][9]);
bool potentional_digits_row(short grid[9][9], short y, short x, bool potent_digit[9][9][9]);
bool potentional_digits(short grid[9][9], short y, short x, bool potent_digit[9][9][9]);
bool potentional_digits_all(short grid[9][9], bool potent_digit[9][9][9]);
bool potentional_digits_insert(short *grid, bool *potent_digit);