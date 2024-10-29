#include "libft.h"

int main()
{
    char str[20] = "Hello, World!";
    
    printf("Önce: %s\n", str);

    ft_memset(str, '*', 5);

    printf("Sonra: %s\n", str);
    
    return 0;
}
