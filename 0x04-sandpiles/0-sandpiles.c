#include "sandpiles.h"

/**
 * sandpiles_sum - gets the sum of sandpiles grids and prints
 *                 the new grid per iteration
 *@grid1: first grid
 *@grid2: second grid
 */

void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
    add_Grids(grid1, grid2);
    while( stabilizeable(grid1) )
    {
        grid_print(grid1);
        stabilize(grid1);
    }
}

/**
 * not_Stable - Check if a grid is Stable( No value is over 3)
 *@grid: grid to check
 *
 * Return: True / False
 */

bool not_Stable(int grid[3][3])
{
    int i1, i2;

    for(i1 = 0; i1 < 3; i1++)
        for(i2 = 0; i2 < 3; i2++)
            if(grid[i1][i2] > 4)
                return(true);
    return(false);
}

/**
 * add_Grids - add two 3x3 grids
 *
 *@grid1: first Grid
 *@grid2: second Grid
 */

void add_Grids(int grid1[3][3], int grid2[3][3])
{
    int i1, i2;

    for(i1 = 0; i1 < 3; i1++)
        for(i2 = 0; i2 < 3; i2++)
            grid1[i1][i2] = grid1[i1][i2] + grid2[i1][i2];
}

/**
 * stabilize - Reduce values over 3 in grid by sending
 *             1 to the surrounding indecies
 *@grid: grid to stabilize
 */

void stabilize(int grid[3][3])
{
    int i1, i2;

    for(i1 = 0; i1 < 3; i1++)
    {
        for(i2 = 0; i2 < 3; i2++)
        {
            if(grid[i1][i2] >= 4)
            {
                grid[i1][i2] -= 4;
                
                if(i1 != 0)
                    grid[i1 - 1][i2] += 1;
                if(i1 != 2)
                    grid[i1 + 1][i2] += 1;
                if(i2 != 0)
                    grid[i1][i2 - 1] += 1;
                if(i2 != 2)
                    grid[i1][i2 + 1] += 1;
            }
        }
    }
}

/**
 * grid_print - prints the 3x3 grid
 *@grid: grid to print 
 */

void grid_print(int grid[3][3])
{
    int i, j;

    printf("=\n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (j)
                printf(" ");
            printf("%d", grid[i][j]);
        }
        printf("\n");
    }
}
