#include <stdlib.h>
#include <unistd.h>
#include "functions.h"

//line fits if 1
int line_fits(int line, int **grid, char dir, int ind)
{
    int i;
    int t;
    
    if (dir == 'h')
    {
        i = 0;
        t = 1000;
        while (i < 4)
        {
            if ((line / t) % 10 != grid[ind][i] && grid[ind][i] != 0)
                return (0);
            i++;
            t /= 10;
        }
    }
    if (dir == 'v')
    {
        i = 0;
        t = 1000;
        while (i < 4)
        {
            if ((line / t) % 10 != grid[i][ind] && grid[i][ind] != 0)
                return (0);
            i++;
            t /= 10;
        }
    }
    return (1);
}

int **write_line(int line, int **grid, char dir, int ind)
{
    int i;
    int t;
    
    if (dir == 'h')
    {
        i = 0;
        t = 1000;
        while (i < 4)
        {
            if (grid[ind][i] == 0)
                grid[ind][i] = (line / t) % 10;
            i++;
            t /= 10;
        }
    }
    if (dir == 'v')
    {
        i = 0;
        t = 1000;
        while (i < 4)
        {
            if (grid[i][ind] == 0)
                grid[i][ind] = (line / t) % 10;
            i++;
            t /= 10;
        }
    }
    return (grid);
}

int **solve(int **grid, struct numPair *npArr)
{
    int i;
    int npair;
    char dir;
    int ind;

    i = 0;
    while(i < 8)
    {
        //kesin olanlar
        npair = 10 * npArr[i].num1 + npArr[i].num2;
        dir = npArr[i].direction;
        ind = npArr[i].index;
        if (npair == 14 && line_fits(4321, grid, dir, ind) == 1)
            write_line(4321, grid, dir, ind);
        if (npair == 41 && line_fits(1234, grid, dir, ind) == 1)
            write_line(1234, grid, dir, ind);
        if (npair == 12 && line_fits(4003, grid, dir, ind) == 1)            write_line(4003, grid, dir, ind);
        if (npair == 21 && line_fits(3004, grid, dir, ind) == 1)
            write_line(3004, grid, dir, ind);
        if (npair == 13 && line_fits(4000, grid, dir, ind) == 1)            write_line(4000, grid, dir, ind);
        if (npair == 31 && line_fits(10004, grid, dir, ind) == 1)
            write_line(10004, grid, dir, ind);
        if (npair == 23 && line_fits(10400, grid, dir, ind) == 1)            write_line(10400, grid, dir, ind);
        if (npair == 32 && line_fits(10040, grid, dir, ind) == 1)
            write_line(10040, grid, dir, ind);
        i++;
    }
    while(i < 8)
    {
        npair = 10 * npArr[i].num1 + npArr[i].num2;
        dir = npArr[i].direction;
        ind = npArr[i].index;
        if (npair == 12 && line_fits(4213, grid, dir, ind) == 0)
            write_line(4123, grid, dir, ind);
        if (npair == 21 && line_fits(3124, grid, dir, ind) == 0)
            write_line(3214, grid, dir, ind);

        i++;
    }
    return (grid);
}

int **create_grid(void)
{
    int i;
    int j;
    int k;
    int    **res;

    res = (int**)malloc(16 * 16);
    k = 0;
    while (k < 4)
    {
        res[k] = (int*)malloc(16 * 16);
        k++;
    }

    i = 0;
    while (i < 4)
    {
        j = 0;
        while (j < 4)
        {
            res[i][j] = 0;
            j++;
        }
        i++;
    }
    return (res);
}

void    print(int **input)
{
    int i;
    int j;
    char digit;

    i = 0;
    while (i < 4)
    {
        j = 0;
        while (j < 4)
        {
            digit = input[i][j] + '0';
            write(1, &digit, 1);
            write(1, " ", 1);
            j++;
        }
        write(1, "\n", 1);
        i++;
    }
}

struct numPair    *array_to_struct(int* input)
{
    struct numPair *res;
    int i;
   
    res    = (struct numPair*)malloc(16 * 8);
    i = 0;
    while(i < 4)
    {
        res[i].num1 = input[8 + i];
        res[i].num2 = input[12 + i];
        res[i].index = i;
        res[i].direction = 'h';
        i++;
    }
    i = 0;
    while(i < 4)
    {
        res[i + 4].num1 = input[i];
        res[i + 4].num2 = input[4 + i];
        res[i + 4].index = i;
        res[i + 4].direction = 'v';
        i++;
    }
    return (res);
}

int * input_to_array(char* input)
{
    int    *r;
    int i;
    int c;

    r = (int*)malloc(32 * 16);
    i = 0;
    c = 0;
    while (i < 32)
    {
        r[c] = input[i] - 48;
        i++;
        i++;
        c++;
    }
    return (r);
}

