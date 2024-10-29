#include "libft.h"

int main()
{
	char c;
	printf("Bir char giriniz: "); scanf(" %c", &c);
	if (ft_isdigit(c) == 1)
		printf("Girdiginiz char bir digit!");
	else printf("Girdiginiz char bir digit degildir!");
	return 0;
}
