*This project has ben created as part of the 42 curriculum by eteixeir*

## Description
This project is a training exercise on the basics of threading a process and using mutexes. It simulates the "Dining Philosophers" problem, where one or more philosophers sit at a round table to eat, think, or sleep[cite: 107, 109]. The main goal is to manage shared resources (forks) without causing deadlocks, data races, or starvation

### Key Rules
* Each philosopher is a thread.
* Forks are protected by mutexes to prevent duplication.
* The simulation stops if a philosopher dies of starvation.

## Instructions

### Compilation
To compile the mandatory part, navigate to the `philo/` directory and run:
```bash
make
```

### Execution
Run the program with the following arguments:
```bash
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```
* **Example**: `./philo 5 800 200 200`

## Resources
* **Threads and Mutexes**: Documentation on `pthread` library.
* **Dining Philosophers Problem**: Classic synchronization problem by Edsger Dijkstra.
* **AI Usage**: 
    * Used for: Explaining mutex logic and structuring the Makefile.
    * Tasks: Debugging race conditions and generating this README template
