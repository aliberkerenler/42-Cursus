#include "libft.h"

int main()
{
	char c;
	printf("Bir char giriniz: "); scanf(" %c", &c);
	if (ft_isascii(c) == 1)
		printf("Girdiginiz char bir ascii!");
	else printf("Girdiginiz char bir ascii degildir!");
	return 0;
}
