#include "libft.h"

int main()
{
    const char *str = "Merhaba, dünya!";
    const char *substr = "dünya";

    char *result = ft_strnstr(str, substr, 15);

    if (result)
	{
        printf("Alt dizi bulundu: %s\n", result);
    } else
	{
        printf("Alt dizi bulunamadı.\n");
    }

    return 0;
}
