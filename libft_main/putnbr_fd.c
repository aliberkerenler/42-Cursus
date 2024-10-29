#include "libft.h"

int main()
{
    ft_putnbr_fd(12345, 1);
    write(1, "\n", 1);
    return 0;
}
