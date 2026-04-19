#include "./philo.h"

void	take_eat(t_philo *philo)
{
	// Caso especial: 1 filósofo só tem 1 garfo, ele morre de fome
	if (philo->table->n_philo == 1)
	{
		pthread_mutex_lock(philo->l_fork);
		print_state(philo, "has taken a fork");
		ft_usleep(philo->table->t_die, philo->table);
		pthread_mutex_unlock(philo->l_fork);
		return ;
	}
	// Ordem de garfos para evitar deadlock
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->r_fork);
		print_state(philo, "has taken a fork");
		pthread_mutex_lock(philo->l_fork);
	}
	else
	{
		pthread_mutex_lock(philo->l_fork);
		print_state(philo, "has taken a fork");
		pthread_mutex_lock(philo->r_fork);
	}
	print_state(philo, "has taken a fork");
	print_state(philo, "is eating");
	pthread_mutex_lock(&philo->table->meal_lock);
	philo->last_meal = get_time();
	philo->meals++;
	pthread_mutex_unlock(&philo->table->meal_lock);
	ft_usleep(philo->table->t_eat, philo->table);
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
}

void	take_sleep(t_philo *philo)
{
	print_state(philo, "is sleeping");
	ft_usleep(philo->table->t_sleep, philo->table);
}

void take_think(t_philo *philo)
{
    print_state(philo, "is thinking");
}