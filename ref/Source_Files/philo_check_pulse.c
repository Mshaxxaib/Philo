/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_check_pulse.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:53:45 by amalbrei          #+#    #+#             */
/*   Updated: 2022/11/27 16:58:32 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * @brief Checks if the philosopher should have died or if there is an already
 * dead philosopher
 * 
 * @param p Struct containing all information for each individual philosopher
 * @return int Whether there is a phlosopher dead: 1 or not: 0
 */
int	philo_check_pulse(t_philo *p)
{
	pthread_mutex_lock(&p->t_info->dlock);
	if (p->t_info->philo_dead == true)
	{
		pthread_mutex_unlock(&p->t_info->dlock);
		return (1);
	}
	if (philo_utime(p) - p->p_lastate >= p->t_info->time_to_die
		&& p->t_info->philo_dead == false)
	{
		p->state = DEAD;
		p->t_info->philo_dead = true;
		pthread_mutex_unlock(&p->t_info->dlock);
		philo_print(p, p->state);
	}
	else
		pthread_mutex_unlock(&p->t_info->dlock);
	return (0);
}
