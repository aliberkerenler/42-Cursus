#include "libft.h"

int main()
{
    char const *str = "!!!Merhaba, Dünya!!!";
    char const *set = "! ";
    char *trimmed_str = ft_strtrim(str, set);

    if (trimmed_str) {
        printf("Trimlenmiş string: '%s'\n", trimmed_str);
        free(trimmed_str);
    } else {
        printf("Bellek ayırma hatası.\n");
    }

    return 0;
}
