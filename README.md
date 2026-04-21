*This project has been created as part of the 42 curriculum by eteixeir*

# Philosophers

## Description

This project is an introduction to **concurrent programming** using threads and mutexes in C.
It simulates the classic **Dining Philosophers problem**, originally proposed by Edsger Dijkstra in 1965.

In the simulation:
- Philosophers sit around a round table with one fork between each pair of neighbours.
- Each philosopher alternates between three states: **thinking**, **eating**, and **sleeping**.
- To eat, a philosopher must pick up **two forks** — the one to their left and the one to their right.
- Forks are shared resources protected by **mutexes** to prevent concurrent access.
- A **monitor thread** continuously checks whether any philosopher has starved or whether all philosophers have eaten enough.

The main objective is to manage synchronization between threads while avoiding:
- **Deadlocks** — threads waiting on each other indefinitely
- **Data races** — unsynchronised concurrent access to shared memory
- **Starvation** — a philosopher never getting access to both forks

The simulation stops when a philosopher **dies of starvation** or when all philosophers have eaten the required number of meals (if specified).

---

## Key Rules

- Each philosopher is implemented as a **separate POSIX thread** (`pthread_create`).
- Each fork is protected by a **mutex** (`pthread_mutex_t`).
- Philosophers must acquire **two forks** before eating and release both after.
- To prevent deadlock, **even-numbered philosophers** pick up the right fork first; **odd-numbered** pick up the left fork first.
- A philosopher dies if they do not start eating within `time_to_die` milliseconds of their last meal.
- Death must be reported within **10ms** of the actual time of death.
- The program must produce **no data races** (verified with `valgrind --tool=helgrind --history-level=approx`).

---

## Instructions

### Compilation

Navigate to the `philo/` directory and run:

```bash
make
```

This will compile all source files with `-Wall -Wextra -Werror` and generate the executable:

```
philo
```

To remove object files and the executable:

```bash
make fclean
```

---

### Execution

```bash
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```

| Argument | Description |
|---|---|
| `number_of_philosophers` | Number of philosophers (and forks) at the table |
| `time_to_die` | Time in ms before a philosopher dies if they have not started eating |
| `time_to_eat` | Time in ms a philosopher spends eating |
| `time_to_sleep` | Time in ms a philosopher spends sleeping |
| `number_of_times_each_philosopher_must_eat` | *(optional)* Simulation stops when all philosophers have eaten this many times |

---

### Examples

Run with 5 philosophers, no meal limit (runs until someone dies):
```bash
./philo 5 800 200 200
```

Run until all philosophers have eaten 7 times:
```bash
./philo 5 800 200 200 7
```

Single philosopher (always dies — only one fork available):
```bash
./philo 1 800 200 200
```

---

### Checking for Data Races

To verify the absence of data races, run with helgrind:

```bash
valgrind --tool=helgrind --history-level=approx ./philo 5 800 200 200 5
```

The `--history-level=approx` flag reduces memory usage, which is necessary on school machines when running with multiple philosopher threads. A clean run produces:

```
ERROR SUMMARY: 0 errors from 0 contexts
```

---

### Example Output

```
0 1 has taken a fork
0 1 has taken a fork
0 1 is eating
200 2 has taken a fork
200 2 has taken a fork
200 2 is eating
200 1 is sleeping
400 1 is thinking
400 2 is sleeping
```

Each line follows the format:
```
[timestamp_in_ms] [philosopher_id] [state]
```

---

### Behaviour Reference

| Input | Expected behaviour |
|---|---|
| `./philo 1 800 200 200` | Philosopher 1 dies at ~800ms |
| `./philo 5 800 200 200` | No one dies, runs indefinitely |
| `./philo 4 310 200 100` | A philosopher dies |
| `./philo 5 800 200 200 7` | Stops cleanly after each philosopher eats 7 times |
| `./philo 2 800 0 0` | Runs indefinitely, no deaths |

---

## Technical Choices

- **Deadlock prevention**: philosophers are divided into two groups by parity — even IDs pick up the right fork first, odd IDs pick up the left fork first. This breaks the circular wait condition.
- **Starvation prevention**: even-numbered philosophers delay their start by `time_to_eat` milliseconds, giving odd-numbered philosophers time to acquire their forks first. For odd numbers of philosophers or when `time_to_sleep = 0`, a calculated think time (`t_eat × 2 − t_sleep`, bounded by `t_die − t_eat`) ensures no philosopher monopolises the forks.
- **Precise sleeping**: `ft_usleep` loops in 500µs increments and exits early if the simulation stops, ensuring death is detected promptly.
- **Lock separation**: `meal_lock` protects meal data and the `stop` flag; `write` protects console output. They are never held simultaneously to prevent deadlock.

---

## Resources

### Documentation
- [POSIX Threads Programming — Lawrence Livermore National Laboratory](https://hpc-tutorials.llnl.gov/posix/)
- [pthread man pages — Linux manual](https://man7.org/linux/man-pages/man7/pthreads.7.html)
- [Dining Philosophers Problem — Wikipedia](https://en.wikipedia.org/wiki/Dining_philosophers_problem)

### Articles & Tutorials
- Dijkstra, E.W. (1971). *Hierarchical ordering of sequential processes*. Acta Informatica, 1(2), 115–138.
- [Codecademy — Introduction to Threads](https://www.codecademy.com/article/introduction-to-threads)
- [Beej's Guide to C Programming — Threads](https://beej.us/guide/bgc/html/split/multithreading.html)

### AI Usage

AI tools (Claude by Anthropic) were used to assist with:

- **Debugging**: identifying a deadlock caused by holding `meal_lock` while calling `print_state`, which then attempted to acquire `write` — resolved by releasing `meal_lock` before printing.
- **Mutex audit**: verifying that all mutexes initialised in `init_mutex_table` were also destroyed in `cleanup`, and that `last_meal` was declared as `long` (not `int`) to avoid truncation of millisecond timestamps.
- **Starvation analysis**: understanding why a fixed 500ms startup delay caused philosophers to die before eating when `time_to_die < 500`, and deriving an adaptive think time formula to distribute fork access fairly under edge cases (`t_sleep = 0`, odd number of philosophers).
- **Documentation**: structuring and writing this README in accordance with the 42 curriculum requirements.

All generated suggestions were read, understood, tested, and validated before integration into the project.