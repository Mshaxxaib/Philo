/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshazaib <mshazaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 17:21:26 by mshazaib          #+#    #+#             */
/*   Updated: 2024/06/30 20:22:08 by mshazaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void philo_dead(t_philo *philo)
{
	printf("%lu %d died\n", philo_utime(philo), philo->id);
}
static void philo_thinking(t_philo *philo)
{
	printf("%lu %d is thinking\n", philo_utime(philo), philo->id);
}
static void philo_sleeping(t_philo *philo)
{
	printf("%lu %d is sleeping\n", philo_utime(philo), philo->id);
}
static void philo_eating(t_philo *philo)
{
	printf("%lu %d has takken a fork\n", philo_utime(philo), philo->id);
	printf("%lu %d has takken a fork\n", philo_utime(philo), philo->id);
	printf("%lu %d is eating\n", philo_utime(philo), philo->id);
}

void philo_print(t_philo *philo, t_state state)
{
	pthread_mutex_lock(&philo->table->dlock);
	if(philo->table->philo_dead == false)
	{
		if(state == EATING)
			philo_eating(philo);
		if(state == SLEEPING)
			philo_sleeping(philo);
		if(state == THINKING)
			philo_thinking(philo);
		pthread_mutex_unlock(&philo->table->dlock);
	}
	else
	{
		pthread_mutex_lock(&philo->table->dlock);
		if(state == DEAD)
			philo_dead(philo);
		pthread_mutex_unlock(&philo->table->dlock);
	}
	pthread_mutex_unlock(&philo->table->dlock);	
}