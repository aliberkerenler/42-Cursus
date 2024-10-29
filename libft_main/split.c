#include "libft.h"

int main()
{
    char str[] = "Bu bir test stringidir.";
    char delimiter = ' ';
    char **result;
    int i = 0;

    result = ft_split(str, delimiter);
    if (!result)
    {
        printf("Bellek tahsis hatası!\n");
        return (1);
    }

    while (result[i])
    {
        printf("Kelime %d: %s\n", i + 1, result[i]);
        free(result[i]);
        i++;
    }
    free(result);

    return 0;
}
