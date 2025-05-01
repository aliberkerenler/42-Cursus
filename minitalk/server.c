/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerenler <aerenler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 23:54:13 by aerenler          #+#    #+#             */
/*   Updated: 2025/03/22 15:10:08 by aerenler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>

static void	ft_putpid(pid_t num)
{
	char	c;

	if (num > 9)
		ft_putpid(num / 10);
	c = 48 + (num % 10);
	write(1, &c, 1);
}

static void	signal_process(int signal)
{
	static unsigned char	x;
	static int				i;

	if (signal == SIGUSR1)
		x = x | 1;
	i++;
	if (i == 8)
	{
		write(1, &x, 1);
		i = 0;
		x = 0;
	}
	x = x << 1;
}

int	main(void)
{
	pid_t	server_id;

	server_id = getpid();
	write(1, "PID: ", 5);
	ft_putpid(server_id);
	write(1, "\n", 1);
	signal(SIGUSR1, signal_process);
	signal(SIGUSR2, signal_process);
	while (1)
	{
		pause();
	}
	return (0);
}
