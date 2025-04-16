#include <stdio.h>

#include "common.h"
#include "philo.h"

void	eating(t_philo *philo)
{
	if (check_simulation_state(philo->data) == SIM_OFF)
		return ;
	if (take_fork(philo) == -1)
		return ;
	pthread_mutex_lock(&philo->eater_mutex);
	philo->last_time_eaten = get_time();
	philo->eat_counter++;
	print_status(philo, "is eating");
	pthread_mutex_unlock(&philo->eater_mutex);
	usleep_enhanced(philo->data->tt_eat);
	release_forks(philo);
}

void	sleep_think(t_philo *philo)
{
	if (check_simulation_state(philo->data) == SIM_ON)
	{
		print_status(philo, "is sleeping");
		usleep_enhanced(philo->data->tt_sleep);
		if (check_simulation_state(philo->data) == SIM_ON)
			print_status(philo, "is thinking");
	}
}
