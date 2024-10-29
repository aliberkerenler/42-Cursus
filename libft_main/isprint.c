#include "libft.h"

int main()
{
	char c;
	printf("Bir char giriniz: "); scanf(" %c", &c);
	if (ft_isprint(c) == 1)
		printf("Girdiginiz char bir printable!");
	else printf("Girdiginiz char bir printable degildir!");
	return 0;
}
