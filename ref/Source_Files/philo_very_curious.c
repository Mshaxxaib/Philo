/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_very_curious.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 15:12:31 by amalbrei          #+#    #+#             */
/*   Updated: 2022/11/25 15:22:14 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	philo_curious_dead(t_philo *philo)
{
	printf(RED);
	printf("%lu %d ", philo_utime(philo), philo->id);
	printf(PURPLE);
	printf("fainted\n");
	printf(DEFAULT);
}

static void	philo_curious_thinking(t_philo *philo)
{
	printf(YELLOW);
	printf("%lu ", philo_utime(philo));
	printf(GREEN);
	printf("%d ", philo->id);
	printf(BLUE);
	printf("is fantasizing\n");
	printf(DEFAULT);
}

static void	philo_curious_sleeping(t_philo *philo)
{
	printf(BLUE);
	printf("%lu ", philo_utime(philo));
	printf(PURPLE);
	printf("%d ", philo->id);
	printf(RED);
	printf("is napping\n");
	printf(DEFAULT);
}

static void	philo_curious_eating(t_philo *philo)
{
	printf(RED);
	printf("%lu ", philo_utime(philo));
	printf(YELLOW);
	printf("%d ", philo->id);
	printf(GREEN);
	printf("has ");
	printf(BLUE);
	printf("received ");
	printf(PURPLE);
	printf("a fork\n");
	printf(RED);
	printf("%lu ", philo_utime(philo));
	printf(YELLOW);
	printf("%d ", philo->id);
	printf(GREEN);
	printf("is nibbling\n");
	printf(DEFAULT);
}

void	philo_very_curious(t_philo *philo, t_state state)
{
	pthread_mutex_lock(&philo->t_info->dlock);
	if (philo->t_info->philo_dead == false)
	{
		pthread_mutex_lock(&philo->t_info->plock);
		if (state == EATING)
			philo_curious_eating(philo);
		if (state == SLEEPING)
			philo_curious_sleeping(philo);
		if (state == THINKING)
			philo_curious_thinking(philo);
		pthread_mutex_unlock(&philo->t_info->plock);
	}
	else
	{
		pthread_mutex_lock(&philo->t_info->plock);
		if (state == DEAD)
			philo_curious_dead(philo);
		pthread_mutex_unlock(&philo->t_info->plock);
	}
	pthread_mutex_unlock(&philo->t_info->dlock);
}
