#include "readerwriter.h"

void rwlock_init(rwlock_t *rw) {
    rw->readers = 0;    //Initialize the number of readers
    sem_init(&rw->lock, 0, 1);  //Initialize the semaphore lock to 1
    sem_init(&rw->writelock, 0, 1); //Initialize the semaphore writelock to 1
    sem_init(&rw->fair, 0, 1);  //Initialize the semaphore fair to 1
}

//Function to acquire the readlock and ensure fairness
void rwlock_acquire_readlock(rwlock_t *rw) {
    sem_wait(&rw->fair);
    sem_wait(&rw->lock);

    rw->readers++;
    if (rw->readers == 1) //first reader gets writelock
        sem_wait(&rw->writelock);
    sem_post(&rw->lock);
    sem_post(&rw->fair);
}

//Function to release the readlock
void rwlock_release_readlock(rwlock_t *rw) {
    sem_wait(&rw->lock);
    rw->readers--;
    if (rw->readers == 0) // last reader lets it go
        sem_post(&rw->writelock);
    sem_post(&rw->lock);
}

//Function to acquire the writelock and ensure fairness
void rwlock_acquire_writelock(rwlock_t *rw) {
    sem_wait(&rw->fair);
    sem_wait(&rw->writelock);
    sem_post(&rw->fair);
}

//Function to release the writelock
void rwlock_release_writelock(rwlock_t *rw) {
    sem_post(&rw->writelock);
}

//Function call to simulate Reading/Writing Operations
void reading_writing() {
    int x = 0, T, i, j;
    T = rand() % 10000;
    for (i = 0; i < T; i++)
        for (j = 0; j < T; j++)
            x = i * j;
}