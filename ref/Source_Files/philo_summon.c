/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_summon.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 18:02:49 by amalbrei          #+#    #+#             */
/*   Updated: 2022/11/27 16:46:30 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * @brief Unlocks forks with mutexes
 */
void	philo_unlock_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->lffork);
	pthread_mutex_unlock(philo->rffork);
}

/**
 * @brief Locks forks with mutexes
 */
void	philo_lock_forks(t_philo *philo)
{
	if (philo->id < philo->t_info->nop)
	{
		pthread_mutex_lock(philo->lffork);
		pthread_mutex_lock(philo->rffork);
	}
	else
	{
		pthread_mutex_lock(philo->rffork);
		pthread_mutex_lock(philo->lffork);
	}
}

/**
 * @brief Returns the current time of the simulation
 * 
 * @param person Struct containing all information for each 
 * individual philosopher
 * @return size_t The current time represented as person->p_life
 */
size_t	philo_utime(t_philo *person)
{
	gettimeofday(&person->life, NULL);
	person->p_life = (person->life.tv_sec * 1000)
		+ (person->life.tv_usec / 1000);
	person->p_life = person->p_life - person->t_info->p_start;
	return (person->p_life);
}

/**
 * @brief The Scene of the simulation where philosophers look for a fork
 * 
 * @param philo Struct containing all information for each individual philosopher
 * @return void* Threads need to return something so its safest to return 
 * a NULL here since not return is required
 */
void	*philo_table(void *philo)
{
	t_philo	*p;

	p = (t_philo *) philo;
	p->p_lastate = 0;
	while (1)
	{
		philo_lock_forks(philo);
		if (!(*p->lfork) && !(*p->rfork)
			&& (*p->lmfork) != p->id && (*p->rmfork) != p->id)
			philo_chowder(p);
		else
			philo_unlock_forks(philo);
		pthread_mutex_lock(&p->t_info->dlock);
		if ((p->t_info->philo_dead == true) || (philo_utime(p) - p->p_lastate
				>= p->t_info->time_to_die) || (p->meals == p->t_info->goal))
		{
			pthread_mutex_unlock(&p->t_info->dlock);
			philo_check_pulse(p);
			return (NULL);
		}
		pthread_mutex_unlock(&p->t_info->dlock);
		usleep(100);
	}
	return (NULL);
}

/**
 * @brief Creates the threads representing every philosopher
 * 
 * @param philo Struct containing all information for each individual philosopher
 * @param table Struct containing table variables, available to all philosophers
 */
void	philo_summon(t_philo *philo, t_table *table)
{
	unsigned int	i;

	philo_start_clock(philo, table);
	if (philo->t_info->nop == 1)
		philo_solo(philo);
	else
	{
		i = -1;
		while (++i < philo->t_info->nop)
		{
			if (pthread_create(&philo[i].thread, NULL, &philo_table,
					&philo[i]) != 0)
				philo_free(ERR_THREAD, philo, table);
			usleep(100);
		}
		i = -1;
		while (++i < philo->t_info->nop)
		{
			if (pthread_join(philo[i].thread, NULL) != 0)
				philo_free(ERR_JOIN, philo, table);
		}
	}
}
