/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtcsbza <vtcsbza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 19:34:34 by vtcsbza           #+#    #+#             */
/*   Updated: 2024/06/25 20:05:42 by vtcsbza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int p_strlen(char *str)
{
    int count;

    count = 0;
    while(str[count])
        count++;
    return(count);
}

int p_atoi(char *av, t_philo *philo, t_table *table)
{
    int sign;
    size_t  i;
    size_t  res;

    while (av[i] == ' ' || av[i] == '\f' || av[i] == '\n'
		|| av[i] == '\r' || av[i] == '\t' || av[i] == '\v')
    i++;
    if(av[i] == "+" || av[i] == "-")
    {
        if(av[i++] == '-')
            sign = sign * -1;        
    }
    while(av[i] >= '0' && av[i] <= '9')
    {
        res = (res * 10) + (av[i++] - '0');
    }
    //need to add edge checks
    return(res * sign);
}