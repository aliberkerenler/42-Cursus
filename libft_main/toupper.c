#include "libft.h"

int main()
{
	char c[20] = "ali berke erenler";
	for (int i = 0; i < 20; i++)
	{
		printf("%c\t", ft_toupper(c[i]));
	}
}
