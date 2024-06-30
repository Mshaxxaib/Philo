/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_check_pulse.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshazaib <mshazaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 17:16:33 by mshazaib          #+#    #+#             */
/*   Updated: 2024/06/30 18:03:50 by mshazaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

/// @brief checks if the dude should die or is already dead
/// @param philo 
/// @return 1 if DEAD 0 if alive
int philo_check_pulse(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->dlock);
	if(philo->table->philo_dead == true)
	{
		pthread_mutex_unlock(&philo->table->dlock);
		return(1);
	}
	if(philo_utime(philo) - philo->p_lastate >= philo->table->time_to_die && philo->table->philo_dead == false)
	{
		philo->state = DEAD;
		philo->table->philo_dead = true;
		pthread_mutex_unlock(&philo->table->dlock);
		philo_print(philo, philo->state);
	}
	else
		pthread_mutex_unlock(&philo->table->dlock);
	return(0);
}