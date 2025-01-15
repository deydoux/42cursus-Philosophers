<div align="center">
  <img height="128" src="https://github.com/user-attachments/assets/952b5d18-19a8-4648-9713-5d4ad6087044">
  <h1>Philosophers</h1>
  <p>Eat, Sleep, Spaghetti, repeat. This project is about learning how threads work by precisely timing a group of philosophers on when to pick up forks and eat spaghetti without dying from hunger.</p>
</div>

## About the project
The Philosophers project challenges students to solve the **Dining Philosophers problem**, a classic synchronization and resource sharing challenge in computer science. The goal is to create a program that simulates philosophers dining together, where each philosopher needs two forks to eat, and must avoid deadlocks and starvation.

![Visualization](https://github.com/user-attachments/assets/c2580cba-1c11-4f93-8d6c-b78df70d7954)
<p align="center">Visualization of <code>./philo 21 700 200 300 7</code></p>

### Key requirements
- Simulate philosophers dining at a round table with forks between them
- Each philosopher must eat, sleep, and think in a specific order
- No philosopher should die from starvation
- Each fork can only be used by one philosopher at a time
- Proper handling of shared resources using mutexes and threads
- Accurate timing of actions using millisecond precision

### Skills learned
- Multi-threading programming
- Mutex and semaphore usage
- Resource sharing and synchronization
- Deadlock prevention
- Race condition handling
- Performance optimization
- Time management in concurrent programming

## Credits
<img align="right" src="https://github.com/user-attachments/assets/d8f721a0-9c5a-4dfa-bd66-6ef23a5131c0">

- [42](https://42.fr/)
- [Philosophers visualizer](https://nafuka11.github.io/philosophers-visualizer/)
