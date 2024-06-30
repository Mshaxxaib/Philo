/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshazaib <mshazaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 16:01:42 by codespace         #+#    #+#             */
/*   Updated: 2024/06/30 19:12:41 by mshazaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void    philo_free(char **err, t_philo *philo, t_table *table)
{
    unsigned int    i;

    i = 0;
    free(table);
    free(philo);
    print_error(err);
}
void philo_cleanup(t_table *table, t_philo *philo)
{
    unsigned int    i;

    i = 0;
    while(++i < table->nop)
        pthread_mutex_destroy(&table->fo_lock[i++]);
    pthread_mutex_destroy(&table->dlock);
    pthread_mutex_destroy(&table->plock);
    free(table->forks);
    free(table->m_fork);
    free(table->fo_lock);
    free(table);
    free(philo);
}