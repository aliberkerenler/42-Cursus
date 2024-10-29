#include "libft.h"

int main() {
    char dest[20] = "Merhaba";
    const char *src = " Dünya";
    unsigned int size = sizeof(dest);

    unsigned int new_length = ft_strlcat(dest, src, size);

    printf("Yeni dizgi: %s\n", dest);
    printf("Yeni uzunluk: %u\n", new_length);

    return 0;
}
