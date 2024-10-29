#include "libft.h"

int main()
{
    char const *str = "Merhaba, Dünya!";
    
    char *substr = ft_substr(str, 7, 9);
    if (substr)
    {
        printf("Alt dizi: '%s'\n", substr);
        free(substr);
    }
    else
    {
        printf("Bellek ayırma hatası.\n");
    }

    return 0;
}
