#include "libft.h"

int main()
{
    const char *str = "Merhaba, Dünya!";
    char *result = ft_strchr(str, 'D');

    if (result != NULL)
        printf("Karakter bulundu: %s\n", result);
    else
        printf("Karakter bulunamadı.\n");

    return 0;
}
