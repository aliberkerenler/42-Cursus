#include "libft.h"

int main()
{
    const char str1[] = "Hello, World!";
    const char str2[] = "Hello, World!";
    const char str3[] = "Hello, Berke!";

    int result1 = ft_memcmp(str1, str2, sizeof(str1));
    if (result1 == 0)
        printf("str1 ve str2 eşittir.\n");
    else
        printf("str1 ve str2 eşit değildir.\n");

    int result2 = ft_memcmp(str1, str3, sizeof(str1));
    if (result2 == 0)
        printf("str1 ve str3 eşittir.\n");
    else
        printf("str1 ve str3 eşit değildir. Fark: %d\n", result2);

    return 0;
}
