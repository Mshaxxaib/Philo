/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_spawn.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshazaib <mshazaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 16:33:33 by mshazaib          #+#    #+#             */
/*   Updated: 2024/06/30 19:05:37 by mshazaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void philo_unlock_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->lffork);
	pthread_mutex_unlock(philo->rffork);
}

void philo_lock_forks(t_philo *philo)
{
	if(philo->id < philo->table->nop)
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
/// @brief the table where the dudes sit
/// @param philo 
/// @return 
void *philo_table(void *philo)
{
	t_philo *p;
	
	p = (t_philo *) philo;
	p->p_lastate = 0;
	while(1)
	{
		philo_lock_forks(philo);
		if(!(*p->lfork) && !(*p->rfork) && (*p->lmfork) != p->id && (*p->rmfork) != p->id)
			philo_eating(p);
		else
			philo_unlock_forks(philo);
		pthread_mutex_lock(&p->table->dlock);
		if((p->table->philo_dead == true) || (philo_utime(p) - p->p_lastate >= p->table->time_to_die) || (p->meals == p->table->goal))
		{
			pthread_mutex_unlock(&p->table->dlock);
			philo_check_pulse(p);
			return(NULL);
		}
		pthread_mutex_unlock(&p->table->dlock);
		usleep(100);
	}
	return(NULL);
}


void philo_spawn(t_philo *philo, t_table *table)
{
	unsigned int i;

	philo_start_clock(philo, table);
	if(philo->table->nop == 1)
		pholo_solo(philo);
	else
	{
		
		i = -1;
		while(++i < philo->table->nop)
		{
			if(pthread_create(&philo[i].thread, NULL, &philo_table, &philo[i] != 0 ))
				philo_free(ERR_THREAD,philo, table);
			usleep(100);
		}
		i = -1;
		while(++i < philo->table->nop)
		{
			if(pthread_join(philo[i].thread, NULL) != 0)
				philo_free(ERR_JOIN, philo, table);
		}
	}	
}

size_t philo_utime(t_philo *philo)
{
	gettimeofday(&philo->life, NULL);
	philo->p_life = (philo->life.tv_sec * 1000) + (philo->life.tv_usec / 1000);
	philo->p_life = philo->p_life - philo->table->p_start;
	return(philo->p_life);
}