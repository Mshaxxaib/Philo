/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshazaib <mshazaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 20:11:56 by mshazaib          #+#    #+#             */
/*   Updated: 2024/06/30 20:44:11 by mshazaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"
static void assign_forks(t_philo *philo, t_table *table)
{
	unsigned int i;
	
	i = -1;
	while(++i < table->nop)
	{
		philo[i].lfork = &table->forks[i];
		if(i == table->nop - 1)
			philo[i].rfork = &table->forks[0];
		else
			philo[i].rfork = &table->forks[i + 1];
		philo[i].lmfork = &table->m_fork[i];
		if(i == table->nop - 1)
			philo[i].rmfork = &table->m_fork[0];
		else
			philo[i].rmfork = &table->m_fork[i + 1];
		philo[i].lffork = &table->fo_lock[i];
		if(i == table->nop - 1)
			philo[i].rffork = &table->fo_lock[0];
		else
			philo[i].rffork = &table->fo_lock[i + 1];
	}
	
}


static void fork_init(t_philo *philo, t_table *table)
{
	unsigned int i;

	table->m_fork = malloc(sizeof(int) * table->nop);
	if(!table->m_fork)
		philo_free(ERR_MALLOC, philo, table);
	table->forks = malloc(sizeof(int) * table->nop);
	if(!table->forks)
		philo_free(ERR_MALLOC, philo, table);
	table->fo_lock = malloc(sizeof(pthread_mutex_t) * table->nop);
	if(!table->fo_lock)
		philo_free(ERR_MALLOC, philo, table);
	i = -1;
	while(++i < table->nop)
	{
		table->forks[i] = false;
		table->m_fork = 0;
		pthread_mutex_init(&table->fo_lock[i], NULL);
	}
	assign_forks(philo, table);
}



/// @brief init the values for the table
/// @param av		input
/// @param philo	
/// @param table
/// @return init'ed table
static t_table *table_init(char **av, t_philo *philo, t_table *table)
{
	int i;

	i = 1;
	table->nop = p_atoi(av[i++], philo, table);
	table->time_to_eat = p_atoi(av[i++], philo, table);
	table->time_to_sleep = p_atoi(av[i++], philo, table);
	table->time_to_die = p_atoi(av[i++], philo, table);
	if(av[i])
		table->goal = p_atoi(av[i], philo, table);
	else
		table->goal = 0;
	table->philo_dead = false;
	fork_init(philo, table);
	pthread_mutex_init(&table->dlock, NULL);
	pthread_mutex_init(&table->plock, NULL);
	return(table);
}

t_table *philo_init(char **av, t_philo *philo)
{
	unsigned int	i;
	t_table			*table_info;

	i = 0;
	table_info = malloc(sizeof(t_table));
	if(!table_info)
		philo_free(ERR_MALLOC, philo, table_info);
	table_info = table_init(av, philo, table_info);
	while(i < table_info->nop)
	{
		philo[i]. id = i + 1;
		philo[i].state = SPAWNED;
		if(table_info->goal != 0)
			philo[i].meals = 0;
		else
			philo[i].meals = 1;
		philo[i].table = table_info;
		i++;
	}
	return (table_info);
}