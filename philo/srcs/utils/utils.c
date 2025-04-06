#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>


#include <errno.h>


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

long long	proper_get_time(void)
{
	struct timeval	tv;
	int				ret;

	if (gettimeofday(&tv, NULL) == 1)
	{
		ret = errno;
		if (ret == EFAULT)
			printf("memory machin\n"); // One of tv or tz pointed outside the accessible address space.
		else if (ret == EINVAL)
			printf("relou celui ci il y a trois erreurs possibles...\n"); // check le map
		return (-1);
	}
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

void	proper_usleep(long long ms)
{
	long long	start;
	long long	elapsed;
	int			ret;

	start = get_time();
	if (start == -1)
		return ;
	while (1)
	{
		elapsed = get_time();
		if (elapsed == -1)
			return ;
		elapsed -= start;
		if (elapsed >= ms)
			break ;
		if (usleep(500) == -1)
		{
			ret = errno;
			if (ret == EINTR) // Interrupted by a signal; see signal(7). maaaaais en meme temps a quel moment
				printf("X Signal received\n");
			else if (ret == EINVAL) // usec is greater than or equal to 1000000.  (On systems where that is considered an  error.)
				printf("machin");
			return ;
		}
	}
}
