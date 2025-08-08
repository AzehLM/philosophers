/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gueberso <gueberso@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 08:16:03 by gueberso          #+#    #+#             */
/*   Updated: 2025/08/08 12:19:08 by gueberso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

#include "philo.h"
#include "common.h"

bool	check_meal_counter(t_philo *philo)
{
	bool	result;

	pthread_mutex_lock(&philo->eater_mutex);
	if (philo->data->nb_meal != -1 \
		&& philo->eat_counter >= philo->data->nb_meal)
		result = false;
	else
		result = true;
	pthread_mutex_unlock(&philo->eater_mutex);
	return (result);
}

static void	handle_single_philo(t_philo *philo)
{
	print_status(philo, "has taken a fork");
	usleep_enhanced(philo->data->tt_die);
}

static void	initial_stagger(t_philo *philo)
{
	int	delay;

	if (philo->id % 2 == 0)
		delay = 10;
	else if (philo->id % 3 == 0)
		delay = 1;
	else
		return ;
	usleep_enhanced(delay);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	pthread_mutex_lock(&philo->eater_mutex);
	philo->last_time_eaten = get_time();
	pthread_mutex_unlock(&philo->eater_mutex);
	if (philo->data->nb_philos == 1)
	{
		handle_single_philo(philo);
		return (NULL);
	}
	initial_stagger(philo);
	while (check_simulation_state(philo->data) == SIM_ON)
	{
		usleep_enhanced(1);
		if (!check_meal_counter(philo))
			break ;
		eating(philo);
		if (check_simulation_state(philo->data) == SIM_OFF)
			break ;
		sleep_think(philo);
	}
	return (NULL);
}
