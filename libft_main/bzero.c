#include "libft.h"

int main()
{
	char str[5] = {'1','1','1','1','1'};
	ft_bzero(str, 5);
	for (int i = 0; i < 5; i++)
	{
		printf("%d",str[i]);
	}
}
