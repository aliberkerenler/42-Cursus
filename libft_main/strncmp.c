#include "libft.h"

int main()
{
    char *str1 = "Merhaba";
    char *str2 = "Merhaba Dünya";

    int result = ft_strncmp(str1, str2, 7); // Karşılaştırma yap

    if (result == 0)
        printf("İki dizi eşit.\n"); 
	else if (result < 0)
        printf("Dizi 1, Dizi 2'den küçüktür.\n"); 
	else printf("Dizi 1, Dizi 2'den büyüktür.\n");

    return 0;
}
