/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_life.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshazaib <mshazaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 17:01:42 by mshazaib          #+#    #+#             */
/*   Updated: 2024/06/30 18:40:16 by mshazaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

/// @brief sleeping time
/// @param philo 
void philo_sleep(t_philo *philo)
{
	if((philo->state != DEAD || philo->table->philo_dead == false) && (philo->meals != philo->table->goal))
	{
		philo->state = SLEEPING;
		philo_print(philo, philo->state);
		philo_snooze(philo, philo->table->time_to_sleep);
		philo_think(philo);
	}
}
/// @brief thinking time
/// @param philo 
void philo_think(t_philo *philo)
{
	if((philo->state != DEAD || philo->table->philo_dead == false) && (philo->meals != philo->table->goal))
	{
		philo->state = THINKING;
		philo_print(philo, philo->state);
	}
}
/// @brief 
/// @param philo 
void philo_snooze(t_philo *philo, unsigned int target)
{
	unsigned int timer;
	unsigned int new;
	
	timer = 0;
	new = philo_utime(philo);
	while(timer < target)
	{
		usleep(100);
		timer = philo_utime(philo) - new;
		if(philo_check_pulse(philo))
			break;
	}
	philo_check_pulse(philo);
}
/// @brief the eating time 
/// @param philo 
void philo_eat(t_philo *philo)
{
	if((philo->state != DEAD || philo->table->philo_dead == false) && (philo->meals != philo->table->goal))
	{
		(*philo->lfork) = true;
		(*philo->rfork) = true;
		(*philo->lmfork) = philo->id;
		(*philo->rmfork) = philo->id;
		philo_unlock_forks(philo);
		philo->meals++;
		philo->p_lastate = philo_utime(philo);
		philo_check_pulse(philo);
		philo->state = EATING;
		philo_print(philo, philo->state);
		philo_snooze(philo, philo->table->time_to_eat);
		philo_lock_forks(philo);
		(*philo->lfork) = false;
		(*philo->rfork) = false;
		philo_unlock_forks(philo);
		philo_sleep(philo);
	}
}