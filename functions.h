struct    numPair
{
    int num1;
    int num2;
    int index;
    char direction; //v for vertical, h for horizontal
};

struct  npLine
{
    struct numPair np;
    int *lines;
    int size;
};

int line_fits(int line, int **grid, char dir, int ind);
int **write_line(int line, int **grid, char dir, int ind);
int **solve(int **grid, struct numPair *npArr);
int **create_grid(void);
void    print(int **input);
struct numPair    *array_to_struct(int* input);
int * input_to_array(char* input);
