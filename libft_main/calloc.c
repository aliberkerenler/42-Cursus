#include "libft.h"

int main()
{
    int *array;
    int n = 5;

    array = (int *)ft_calloc(n, sizeof(int));

    if (array == NULL)
	{
        printf("Bellek tahsisi başarısız!\n");
        return 1;
    }
    for (int i = 0; i < n; i++)
	{
        printf("array[%d] = %d\n", i, array[i]);
    }
    free(array);

    return 0;
}
