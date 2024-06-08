#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	int i = 100;

	while (i--)
	{
		printf("%d ", (rand() % 10000));
	}
}
