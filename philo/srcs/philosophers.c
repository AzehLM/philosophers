#include <string.h>

#include "philo.h"

int	main(int ac, char **av)
{
	t_data	data;

	memset(&data, 0, sizeof(t_data));
	if (parser(ac, av, &data) == -1)
		return (-1);
	if (init_simulation(&data) == -1)
		return (-1);
	// if (init_threads(&data) == -1)
	// {
	// 	cleanup(&data);
	// 	return (-1);
	// }
	// init thread/mutexes
	// routine ? simulation ? pas compris encore ca
	cleanup(&data);
	return (0);
}
