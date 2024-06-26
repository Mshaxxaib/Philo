/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtcsbza <vtcsbza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 19:19:23 by vtcsbza           #+#    #+#             */
/*   Updated: 2024/06/25 19:58:09 by vtcsbza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void print_error(char **error)
{
    write(2, error, p_strlen(error));
    exit(1);
}

int philo_num_check(char **av)
{
    int i;
    int j;
    
    i = 1;

    while(av[1])
    {
        j = 0;
        while(av[i][j])
        {
            if(!(av[1][i] >= 48 && av[1][i] <= 57))
                return(1);
            j++;
        }
        i++;
    }
    return(0);
}

int main(int ac, char **av)
{
    t_philo philo;
    t_table table;

    if(philo_num_check(av) && av != 5 || av != 6)
        print_error("ERROR in the INPUT\n");
    // philo = 
    //  need to check the number of philos 
    
}