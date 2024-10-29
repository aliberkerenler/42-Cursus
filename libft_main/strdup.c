#include "libft.h"

int main()
{
    char *original = "Merhaba, Dünya!";
    char *copy = ft_strdup(original);

    if (copy != NULL)
    {
        printf("Orijinal: %s\n", original);
        printf("Kopya: %s\n", copy);
        free(copy);
    }
    else
    {
        printf("Bellek ayırma başarısız oldu.\n");
    }

    return 0;
}
