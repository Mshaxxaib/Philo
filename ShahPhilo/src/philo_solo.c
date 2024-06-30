/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_solo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshazaib <mshazaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 16:40:57 by mshazaib          #+#    #+#             */
/*   Updated: 2024/06/30 20:43:23 by mshazaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void philo_fork(t_philo *philo)
{
	printf("%lu", philo_utime(philo));
	printf("%d", philo->id);
	printf(" has taken a fork\n");
}
static void philo_dead(t_philo *philo)
{
	printf("%lu", philo_utime(philo));
	printf("%d", philo->id);
	printf(" fainted\n");
}
void philo_solo(t_philo *philo)
{
	philo_fork(philo);
	usleep(philo->table->time_to_die * 1000);
	philo_dead(philo);
}