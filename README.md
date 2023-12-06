<p align="center">
    <img src="philosophersm.png" alt="Badge Name">
</p>

## Project Overview
In the "Philosophers" project, we explore the classic synchronization problem known as the Dining Philosophers. The goal of this project is to solve this problem using threading and mutexes in C, ensuring that no philosopher starves, while maintaining a deadlock-free and race condition-free environment.

### Objectives
- Understand and implement threading and mutexes.
- Solve the Dining Philosophers problem.
- Ensure no deadlocks or race conditions.
- Optimize for performance and resource management.
- Semaphores and forking instead of pthread for bonuses.

### Skills
- Rigorous
- Unix
- Algorithms & AI

### Technologies Used
- Language: C
- Threading: POSIX threads
- Mutexes: POSIX mutexes
- Semaphores and PIDs

## Challenges Faced
1. Managing Threads: Creating and managing multiple threads without causing race conditions was a critical challenge.
2. Deadlock Prevention: Ensuring that the philosophers do not enter a deadlock required careful planning and implementation.
3. Resource Allocation: Optimizing resource allocation to prevent starvation was complex and required an in-depth understanding of threading and mutexes.

## Outcomes
- Successfully implemented a multithreaded solution to the Dining Philosophers problem.
- Gained a deeper understanding of threads, mutexes, and synchronization issues in concurrent programming.
- Developed an efficient algorithm for resource allocation and deadlock prevention.

## How to Run
1. Clone the repository:
``` bash
git clone https://github.com/Darrens24/Philo42.git
```
2. Compile with:
``` bash
make
make bonus
```
3. Run the program:
```bash
./philo [number_of_philosophers] [time_to_die] [time_to_eat] [time_to_sleep] [number_of_times_each_philosopher_must_eat]
./philo_bonus [number_of_philosophers] [time_to_die] [time_to_eat] [time_to_sleep] [number_of_times_each_philosopher_must_eat]
```
