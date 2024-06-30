/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_life.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 20:03:42 by amalbrei          #+#    #+#             */
/*   Updated: 2022/11/27 16:53:21 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * @brief A dressed usleep that ensures every increment and use of regular
 * usleep is accounted for in calculating the time vs the philosopher's life
 * 
 * @param p Struct containing all information for each individual philosopher
 * @param target The amount of time the usleep will have to reach each increment
 */
void	philo_snooze(t_philo *p, unsigned int target)
{
	unsigned int	timer;
	unsigned int	new;

	timer = 0;
	new = philo_utime(p);
	while (timer < target)
	{
		usleep(100);
		timer = philo_utime(p) - new;
		if (philo_check_pulse(p))
			break ;
	}
	philo_check_pulse(p);
}

/**
 * @brief The thinking portion of the simulation
 */
void	philo_thinker(t_philo *p)
{
	if ((p->state != DEAD || p->t_info->philo_dead == false)
		&& (p->meals != p->t_info->goal))
	{
		p->state = THINKING;
		philo_print(p, p->state);
	}
}

/**
 * @brief The sleep portion of the simulation
 */
void	philo_slumber(t_philo *p)
{
	if ((p->state != DEAD || p->t_info->philo_dead == false)
		&& (p->meals != p->t_info->goal))
	{
		p->state = SLEEPING;
		philo_print(p, p->state);
		philo_snooze(p, p->t_info->time_to_sleep);
		philo_thinker(p);
	}
}

/**
 * @brief The eat portion of the simulation
 * 
 * @note Changes need to occur BEFORE the message is printed
 * and placed within the usleep function: philo_snooze
 */
void	philo_chowder(t_philo *p)
{
	if ((p->state != DEAD || p->t_info->philo_dead == false)
		&& (p->meals != p->t_info->goal))
	{
		(*p->lfork) = true;
		(*p->rfork) = true;
		(*p->lmfork) = p->id;
		(*p->rmfork) = p->id;
		philo_unlock_forks(p);
		p->meals++;
		p->p_lastate = philo_utime(p);
		philo_check_pulse(p);
		p->state = EATING;
		philo_print(p, p->state);
		philo_snooze(p, p->t_info->time_to_eat);
		philo_lock_forks(p);
		(*p->lfork) = false;
		(*p->rfork) = false;
		philo_unlock_forks(p);
		philo_slumber(p);
	}
}
