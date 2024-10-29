#include "libft.h"

int main()
{
    const char *str = "Merhaba, dünya!";
    int c = 'a';

    char *result = ft_strrchr(str, c);

    if (result)
	{
        printf("Karakterin son geçtiği yer: %s\n", result);
    }
	else
	{
        printf("Karakter bulunamadı.\n");
    }

    return 0;
}
