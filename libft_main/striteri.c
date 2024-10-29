#include "libft.h"

static void print_char(unsigned int index, char *c)
{
    printf("Index %d: %c (ASCII: %d)\n", index, *c, *c);
}

int main()
{
    char str[] = "Merhaba";

    ft_striteri(str, print_char);

    return 0;
}
