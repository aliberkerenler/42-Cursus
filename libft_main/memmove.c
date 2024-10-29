#include "libft.h"

int main()
{
    char str[] = "Hello, World!";
    
    ft_memmove(str + 7, str, 6);

    printf("Sonuc: %s\n", str);
    
    return 0;
}
