#include <stdlib.h>
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <semaphore.h>

typedef struct _rwlock_t {
    sem_t lock; // binary semaphore (basic lock)
    sem_t writelock; // allow ONE writer/MANY readers
    sem_t fair;
    int readers; // #readers in critical section
} rwlock_t;

void rwlock_init(rwlock_t* rw);
void rwlock_acquire_readlock(rwlock_t* rw);
void rwlock_release_readlock(rwlock_t* rw);
void rwlock_acquire_writelock(rwlock_t* rw);
void rwlock_release_writelock(rwlock_t* rw);
void reading_writing();