/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gueberso <gueberso@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 08:15:58 by gueberso          #+#    #+#             */
/*   Updated: 2025/04/19 12:15:22 by gueberso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

#include "common.h"
#include "philo.h"

void	release_forks(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(&philo->l_fork->gatekeeper);
		philo->l_fork->status = AVAILABLE;
		pthread_mutex_unlock(&philo->l_fork->gatekeeper);
		pthread_mutex_lock(&philo->r_fork->gatekeeper);
		philo->r_fork->status = AVAILABLE;
		pthread_mutex_unlock(&philo->r_fork->gatekeeper);
	}
	else
	{
		pthread_mutex_lock(&philo->r_fork->gatekeeper);
		philo->r_fork->status = AVAILABLE;
		pthread_mutex_unlock(&philo->r_fork->gatekeeper);
		pthread_mutex_lock(&philo->l_fork->gatekeeper);
		philo->l_fork->status = AVAILABLE;
		pthread_mutex_unlock(&philo->l_fork->gatekeeper);
	}
}

static int	try_take_first_fork(t_fork *fork)
{
	int	result;

	result = 0;
	pthread_mutex_lock(&fork->gatekeeper);
	if (fork->status == AVAILABLE)
	{
		fork->status = UNAVAILABLE;
		result = 1;
	}
	pthread_mutex_unlock(&fork->gatekeeper);
	return (result);
}

static int	try_take_second_fork(t_philo *philo, t_fork *first, t_fork *second)
{
	int	result;

	result = 0;
	pthread_mutex_lock(&second->gatekeeper);
	if (second->status == AVAILABLE)
	{
		second->status = UNAVAILABLE;
		print_status(philo, "has taken a fork");
		print_status(philo, "has taken a fork");
		result = 1;
	}
	else
	{
		pthread_mutex_lock(&first->gatekeeper);
		first->status = AVAILABLE;
		pthread_mutex_unlock(&first->gatekeeper);
	}
	pthread_mutex_unlock(&second->gatekeeper);
	return (result);
}

int	take_fork(t_philo *philo)
{
	t_fork	*first;
	t_fork	*second;

	if (philo->id % 2 == 0)
	{
		first = philo->l_fork;
		second = philo->r_fork;
	}
	else
	{
		first = philo->r_fork;
		second = philo->l_fork;
	}
	while (check_simulation_state(philo->data) == SIM_ON)
	{
		if (try_take_first_fork(first))
			if (try_take_second_fork(philo, first, second))
				return (0);
		usleep(500);
	}
	return (-1);
}
