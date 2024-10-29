#include "libft.h"

char my_function(unsigned int index, char c)
{
    return c + 1; 
}

int main()
{
    char *str = "Merhaba";
    char *result;

    result = ft_strmapi(str, my_function);

    if (result)
	{
        printf("Sonuç: %s\n", result);
        free(result);
    }
	else printf("Hata: Bellek ayrılmadı.\n");

    return 0;
}
