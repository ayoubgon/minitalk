#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include "minitalk.h"

void	handler_seg(int sig)
{
	static int	i = 0;
	static char	c;

	c = 0;
	if (sig == SIGUSR1)
		c |= (1 << i);
	i++;
	if (i == 8)
	{
		printf ("%c", c);
		if (!c)
			printf("\n");
		c = 0;
		i = 0;
	}
}

int	main()
{
	ft_printf("My Server PID is: %d\n", getpid());
	signal(SIGUSR2,handler_seg);
	signal(SIGUSR1,handler_seg);
	while (1)
	{
		//write(1,"whiting for the signal from the clinet\n",40);
		pause();
	}
	return (0);
}