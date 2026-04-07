/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eteixeir <eteixeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 06:46:08 by eteixeir          #+#    #+#             */
/*   Updated: 2026/04/08 00:01:24 by eteixeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int philo_eat(t_philo *philo)
{
    // Pegar o primeiro garfo (Esquerdo)
    pthread_mutex_lock(philo->left_fork);
    print_status(philo, "has taken a fork");
    
    // Caso especial: se só houver 1 filósofo, ele nunca pegará o segundo garfo
    if (philo->data->number_of_philosophers == 1)
    {
        ft_usleep(philo->data->time_to_die);
        pthread_mutex_unlock(philo->left_fork);
        return (-1);
    }
    // Pegar o segundo garfo (Direito)
    pthread_mutex_lock(philo->right_fork);
    print_status(philo, "has taken a fork");

    // Comer propriamente dito
    print_status(philo, "is eating");
    // Atualizar o tempo da última refeição (Proteja isso com mutex depois!)
    philo->last_meal_time = get_time();
    ft_usleep(philo->data->time_to_eat);
    philo->meals_eaten++;
    // Largar os garfos (Ordem inversa ou mesma ordem, mas soltar ambos!)
    pthread_mutex_unlock(philo->right_fork);
    pthread_mutex_unlock(philo->left_fork);
    return (0);
}

void *philo_routine(void *arg)
{
    t_philo *philo;

    philo = (t_philo *)arg;
    
    // Se o ID for par, damos um pequeno atraso para dessincronizar
    if (philo->id % 2 == 0)
        ft_usleep(10); // 10ms é geralmente o suficiente

    // Loop principal: continua enquanto ninguém morreu
    // (Você precisará de uma flag global ou check no data para parar)
    while (1) 
    {
        // 1. Tentar comer
        if (philo_eat(philo) == -1)
            break;
            
        // 2. Dormir
        print_status(philo, "is sleeping");
        ft_usleep(philo->data->time_to_sleep);
        
        // 3. Pensar
        print_status(philo, "is thinking");
    }
    return (NULL);
}

void	print_status(t_philo *philo, char *msg)
{
	long long	now;

	// Bloqueia a escrita para que ninguém mais imprima ao mesmo tempo
	pthread_mutex_lock(&philo->data->write_lock);
	
	// Verifica se a simulação ainda deve continuar (se alguém já morreu, paramos)
	if (!get_simulation_status(philo->data)) {
	    pthread_mutex_unlock(&philo->data->write_lock);
	    return;
	}

	now = get_time() - philo->data->start_time;
	printf("%lld %d %s\n", now, philo->id, msg);

	pthread_mutex_unlock(&philo->data->write_lock);
}

void *monitor_routine(void *arg)
{
    t_context *data;
    int i;

    data = (t_context *)arg;
    while (1) // Loop infinito de vigilância
    {
        i = 0;
        while (i < data->number_of_philosophers)
        {
            // 1. Verificar Morte
            pthread_mutex_lock(&data->meal_lock); // Você precisará criar esse mutex
            if (get_time() - data->philos[i].last_meal_time > data->time_to_die)
            {
                print_status(&data->philos[i], "died");
                
                pthread_mutex_lock(&data->stop_lock);
                data->simulation_stop = 1; // Flag para avisar as outras threads
                pthread_mutex_unlock(&data->stop_lock);
                
                pthread_mutex_unlock(&data->meal_lock);
                return (NULL);
            }
            pthread_mutex_unlock(&data->meal_lock);
            i++;
        }
        
        // 2. Verificar se todos comeram o suficiente (se ac == 6)
        // ... lógica extra aqui ...

        usleep(1000); // Pequena pausa para não fritar o processador
    }
    return (NULL);
}
