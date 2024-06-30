/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_solo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 14:29:01 by amalbrei          #+#    #+#             */
/*   Updated: 2022/11/27 16:52:58 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	philo_fork(t_philo *p)
{
	printf(RED);
	printf("%lu ", philo_utime(p));
	printf(YELLOW);
	printf("%d ", p->id);
	printf(GREEN);
	printf("has ");
	printf(BLUE);
	printf("taken ");
	printf(PURPLE);
	printf("a fork\n");
	printf(DEFAULT);
}

static void	philo_ded(t_philo *p)
{
	printf(RED);
	printf("%lu ", philo_utime(p));
	printf(YELLOW);
	printf("%d ", p->id);
	printf(GREEN);
	printf("fainted\n");
	printf(DEFAULT);
}

/**
 * @brief Should a philosopher be made by themselves
 * which therefore they will die within the time_to_die
 * variable timeframe
 * 
 * @param p Struct containing all information for each individual philosopher
 */
void	philo_solo(t_philo *p)
{
	philo_fork(p);
	usleep(p->t_info->time_to_die * 1000);
	philo_ded(p);
}
