#include "../minitalk.h"

void	ft_send_bit(int	pid, char i)
{
	int	bit;
	
	bit = 0;
	while (bit < 8)
	{
		if ((i & (0x01 << bit)) != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(1000);
		bit++;
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	i = 0;
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		while (argv[2][i] != '\0')
		{
			ft_send_bit(pid, argv[2][i]);
			i++;
		}
		ft_send_bit(pid, '\n');
	}
	(void)argv;
	if (argc != 2)
	{
		return (0);
		
	}
	return (0);
}