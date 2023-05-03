#include "../minitalk.h"

void ft_handler(int signal)
{
	static int	bit;
	static int	i;

	if (signal == SIGUSR1)
		i |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", i);
		bit = 0;
		i = 0;
	}
}

int main(int argc, char **argv)
{
	int	pid;
	
	pid = 0;
	(void)argv;
	if (argc != 1)
	{
		ft_printf("Error: Wrong formats\n");
		ft_printf("Try ./serveur");
		return (0);
	}
	pid = getpid();
	if (pid == 0)
	{
		ft_printf("Error: No PID was define\n");
		return (0);
	}
	ft_printf("PID: %d \n", pid);
	ft_printf("Waiting for a message !\n");
	while (argc == 1)
	{
		signal(SIGUSR1, ft_handler);
		signal(SIGUSR2, ft_handler);
		pause ();
	}
	return (0);
}
