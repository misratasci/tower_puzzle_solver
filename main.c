
#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int	main(int argc, char** argv)
{
	char*	input_str;
	int*	p;
	struct numPair*	np;
	int		i;
	int		**grid;

	grid = create_grid();
	//print(grid);

	input_str = argv[1];
	p = input_to_array(input_str);
	np = array_to_struct(p);
	print(solve(grid, np));
	
    i = 0;
    while (i < 8)
    {
        printf("%d%d%c, ", np[i].num1, np[i].num2, np[i].direction);
        i++;
    }
    
	printf("%d, %s", argc, argv[0]);
	free(grid);
	free(p);
	free(np);
	return (0);
}
