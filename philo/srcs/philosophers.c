#include <string.h>

#include "philo.h"

int	main(int ac, char **av)
{
	t_data	data;

	memset(&data, 0, sizeof(t_data));
	if (parser(ac, av, &data) == -1)
		return (-1); // en sortie de ca on initialise la/les structures. (en ayant decide ce qu'on met dedans)
	// donc init data
	// init thread/mutexes
	// routine ? simulation ? pas compris encore ca
	// cleanup
	return (0);
}
