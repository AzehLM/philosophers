#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "philo.h"

/**
 * Recheck dans la struct mais tv_sec = secondes, tv_usec = microsecondes en PLUS
 *
 */
long long	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

/**
 * Meilleure attente, pas possible de ctrl + d
 * Mon timer c'est la boucle, on sort quand on a attendu le temps voulu
 */
void	usleep_enhanced(long long ms)
{
	long long	start;
	long long	elapsed;

	start = get_time();
	while (1)
	{
		elapsed = get_time() - start;
		if (elapsed >= ms)
			break ;
		usleep(500);
	}
}
