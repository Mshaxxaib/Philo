/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshazaib <mshazaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 20:11:56 by mshazaib          #+#    #+#             */
/*   Updated: 2024/06/28 20:16:09 by mshazaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"





t_table *philo_init(char **av, t_philo *philo)
{
	unsigned int	i;
	t_table			*table_info;

	i = 0;

	table_info = malloc(sizeof(t_table));
	if(!table_info)
		philo_free("Error in Malloc", philo, table_info);
	table_info = table_init(av, philo, table_info);
}