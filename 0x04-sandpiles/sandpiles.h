#ifndef SANDPILES_H
#define SANDPILES_H

#include <stdlib.h>
#include <stdio.h>

typedef enum {false, true} bool;


void sandpiles_sum(int grid1[3][3], int grid2[3][3]);
bool not_Stable(int grid[3][3]);
void add_Grids(int grid1[3][3], int grid2[3][3]);
void stablize(int grid[3][3]);
void grid_print(int grid[3][3]);

#endif // SANDPIELS_H