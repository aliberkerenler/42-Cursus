#include "libft.h"

int main()
{
	char c;
	printf("Bir char giriniz: "); scanf(" %c", &c);
	if (ft_isalnum(c) == 1)
		printf("Girdiginiz char bir harf veya rakam!");
	else printf("Girdiginiz char bir harf veya rakam degildir!");
	return 0;
}
