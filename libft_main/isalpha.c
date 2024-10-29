#include "libft.h"

int main()
{
	char c;
	printf("Bir char giriniz: "); scanf(" %c", &c);
	if (ft_isalpha(c) == 1)
		printf("Girdiginiz char bir harf!");
	else printf("Girdiginiz char bir harf degildir!");
	return 0;
}
