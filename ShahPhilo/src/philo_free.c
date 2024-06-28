/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshazaib <mshazaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 16:01:42 by codespace         #+#    #+#             */
/*   Updated: 2024/06/28 20:49:35 by mshazaib         ###   ########.fr       */
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