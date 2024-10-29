#include "libft.h"

int main()
{
	char c;
	printf("'Hello, World!' icinde aramak istediginiz ifadeyi giriniz: ");
	scanf(" %c", &c);
    const char str[] = "Hello, World!";
    char *result = ft_memchr(str, c, sizeof(str));

    if (result != NULL)
        printf("Karakter bulundu: %c\n", *result);
    else
        printf("Karakter bulunamadı.\n");

    return 0;
}
