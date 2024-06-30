/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 16:51:18 by amalbrei          #+#    #+#             */
/*   Updated: 2022/11/30 15:42:58 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	philo_dead(t_philo *philo)
{
	printf(RED);
	printf("%lu %d died\n", philo_utime(philo), philo->id);
	printf(DEFAULT);
}

static void	philo_thinking(t_philo *philo)
{
	printf(CYAN);
	printf("%lu %d is thinking\n", philo_utime(philo), philo->id);
	printf(DEFAULT);
}

static void	philo_sleeping(t_philo *philo)
{
	printf(GREEN);
	printf("%lu %d is sleeping\n", philo_utime(philo), philo->id);
	printf(DEFAULT);
}

static void	philo_eating(t_philo *philo)
{
	printf(YELLOW);
	printf("%lu %d has taken a fork\n", philo_utime(philo), philo->id);
	printf("%lu %d has taken a fork\n", philo_utime(philo), philo->id);
	printf("%lu %d is eating\n", philo_utime(philo), philo->id);
	printf(DEFAULT);
}

/**
 * @brief Handles which message to be printed depending on the philosopher's
 * state
 * 
 * @param philo Struct containing all information for each individual philosopher
 * @param state The state of a philosopher based on the enum declared in 
 * the header file
 */
void	philo_print(t_philo *philo, t_state state)
{
	if (philo->id == 69 || philo->t_info->nop == 1 || philo->t_info->nop == 69)
		philo_very_curious(philo, state);
	else
	{
		pthread_mutex_lock(&philo->t_info->dlock);
		if (philo->t_info->philo_dead == false)
		{
			pthread_mutex_lock(&philo->t_info->plock);
			if (state == EATING)
				philo_eating(philo);
			if (state == SLEEPING)
				philo_sleeping(philo);
			if (state == THINKING)
				philo_thinking(philo);
			pthread_mutex_unlock(&philo->t_info->plock);
		}
		else
		{
			pthread_mutex_lock(&philo->t_info->plock);
			if (state == DEAD)
				philo_dead(philo);
			pthread_mutex_unlock(&philo->t_info->plock);
		}
		pthread_mutex_unlock(&philo->t_info->dlock);
	}
}
