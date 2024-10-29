#include "libft.h"

int main()
{
    char dest[20];
    const char *src = "Merhaba Dünya";

    unsigned int copied_length = ft_strlcpy(dest, src, sizeof(dest));


    printf("Kopyalanan dizgi: %s\n", dest);
    printf("Kaynak dizinin uzunluğu: %u\n", copied_length);
    return 0;
}
