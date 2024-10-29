#include "libft.h"

int main()
{
	char c[20] = "ALI BERKE ERENLER";
	for (int i = 0; i < 20; i++)
	{
		printf("%c\t", ft_tolower(c[i]));
	}
}
