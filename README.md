# philosophers


[Visualizer #1](https://nafuka11.github.io/philosophers-visualizer/)

[Visualizer #2](https://rom98759.github.io/Philosophers-visualizer/)

---

#### Ressources
- [Code(quoi)](https://www.codequoi.com/threads-mutex-et-programmation-concurrente-en-c/)
- [Posix thread (pthread) libraries](https://www.cs.cmu.edu/afs/cs/academic/class/15492-f07/www/pthreads.html#BASICS)
- [POSIX Threads - Systemes multi-taches - bien-programmer](https://www.bien-programmer.fr/pthreads.htm)
- [Posix Threads in OS - Geekforgeeks](https://www.geeksforgeeks.org/posix-threads-in-os/)
- [Dining philosophers problem - Wikipedia](https://en.wikipedia.org/wiki/Dining_philosophers_problem)

#### Books
- [Programming with POSIX threads](https://www.google.fr/books/edition/Programming_with_POSIX_Threads/_xvnuFzo7q0C?hl=fr&gbpv=0)
- [PThreads Programming - A POSIX Standard for better Multiprocessing](https://www.google.fr/books/edition/PThreads_Programming/rgrRr1i1MJgC?hl=fr&gbpv=0)
- [UNIX Systems Programming - Communication, Concurrency, and Threads](https://www.google.fr/books/edition/UNIX_Systems_Programming/tdsZHyH9bQEC?hl=fr&gbpv=0)

---


valgrind --tool=helgrind --tool=drd

pas les deux en meme temps

pour les leaks autres flags normaux

bonus: flags pour fork

****
### Project overview:

- One or more philo at the table
  - **One** fork for **each** philo at the table
- 3 states : eating, thinking, sleeping
- Needs **two** forks to eat
- **State order:** eating -> sleeping -> thinking.
- If a philosophers dies of starvation, the program stops.
- Philosophers can't communicate **so** they **don't have** information about each others **states**.






---


### Studies

- Les threads d'un meme processus partagent:
  - Les instructions du process en cours
  - La plupart des données (lesquels ne partagent-ils pas ?)
  - les fds
  - les signaux
  - le dossier courant
- Les threads ne partagent pas:
  - le meme ID (comme les process enfant, chaqu'un a son pthread_id)
  - les pointeurs sur la stack


### Mutex supplementaire

- De meme que pour l'etat de la fourchette, on va avoir un mutex pour ecrire et un mutex pour l'etat global de la simulation
