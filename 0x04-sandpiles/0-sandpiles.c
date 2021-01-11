#include "sandpiles.h"

bool not_Stable(int grid[3][3]);
void add_Grids(int grid1[3][3], int grid2[3][3]);
void stablize(int grid[3][3]);
void grid_print(int grid[3][3]);

void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
    add_Grids(grid1, grid2);
    while( not_Stable(grid1) )
    {
        grid_print(grid1);
        stablize(grid1);
    }
}

bool not_Stable(int grid[3][3])
{
    int i1, i2;

    for(i1 = 0; i1 < 3; i1++)
        for(i2 = 0; i2 < 3; i2++)
            if(grid[i1][i2] > 4)
                return(true);
    return(false);
}

void add_Grids(int grid1[3][3], int grid2[3][3])
{
    int i1, i2;

    for(i1 = 0; i1 < 3; i1++)
        for(i2 = 0; i2 < 3; i2++)
            grid1[i1][i2] = grid1[i1][i2] + grid2[i1][i2];
}

void stablize(int grid[3][3])
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
