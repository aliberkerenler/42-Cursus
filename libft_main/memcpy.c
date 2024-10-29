#include "libft.h"

int main()
{
    char src[] = "Hello, World!";
    char dest[20];

    ft_memcpy(dest, src, 13);

    printf("Kopyalanan dize: %s\n", dest);
    return 0;
}
