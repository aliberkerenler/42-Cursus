#include "libft.h"

int main()
{
    const char *str1 = "Merhaba, ";
    const char *str2 = "Dünya!";
    char *result;


    result = ft_strjoin(str1, str2);
    
    if (result != NULL)
    {
        printf("Birleşik Dizi: %s\n", result);
        free(result);
    }
    else
    {
        printf("Bellek ayırma başarısız oldu.\n");
    }

    return 0;
}