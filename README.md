
*This project has been created as part of the 42 curriculum by eteixeir*

# Philosophers

## Description

This project is an introduction to **concurrent programming** using threads and mutexes in C.

It simulates the classic **Dining Philosophers problem**, originally proposed by Edsger Dijkstra.

In the simulation:

- Philosophers sit around a round table.
- Each philosopher alternates between **thinking, eating, and sleeping**.
- To eat, a philosopher must pick up **two forks** (left and right).
- Forks are shared resources protected by **mutexes**.

The main objective is to manage synchronization between threads while avoiding:

- **Deadlocks**
- **Data races**
- **Starvation**

The simulation stops when a philosopher **dies of starvation** or when all philosophers have eaten the required number of meals (if specified).

---

## Key Rules

- Each philosopher is implemented as a **separate thread**.
- Each fork is protected by a **mutex**.
- Philosophers must take two forks before eating.
- The program must avoid **data races and deadlocks**.
- A philosopher dies if they do not eat within `time_to_die`.

---

## Compilation

Navigate to the `philo/` directory and run:

```bash
make
````

This will generate the executable:

```
philo
```

---

## Execution

Run the program using:

```bash
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```

Example:

```bash
./philo 5 800 200 200
```

Example with meal limit:

```bash
./philo 5 800 200 200 5
```

---

## Example Output

```
0 1 has taken a left fork
0 1 has take0 1 has taken a left fork
0 1 h0 1 has taken a left fork
0 1 has take0 1 has taken a left fork
0 1 has taken a right fork
0 1 is eating
200 1 is sleeping
400 1 is thinkingn a right fork
0 1 is eating
200 1 is sleeping
400 1 is thinkingas taken a right fork
0 1 is eating
200 1 is sleeping
400 1 is thinkingn a right fork
0 1 is eating
200 1 is sleeping
400 1 is thinking
```

---

## Allowed Functions

The project allows the following external functions:

```
memset
printf
malloc
free
write
usleep
gettimeofday
pthread_create
pthread_detach
pthread_join
pthread_mutex_init
pthread_mutex_destroy
pthread_mutex_lock
pthread_mutex_unlock
```

---

## Resources

* pthread documentation
* Dining Philosophers problem
* POSIX threads synchronization

---

## AI Usage

AI tools were used to assist with:

* Understanding mutex synchronization
* Debugging race conditions
* Structuring documentation

All generated code was reviewed and understood before integration.
