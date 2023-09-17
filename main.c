#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/types.h>
#include <semaphore.h>
#include "readerwriter.h"

rwlock_t lock;

void *reader() {
    printf("Create reader\n");  //Indicates that the Reader has been created
    rwlock_acquire_readlock(&lock); //Acquire the read lock
    printf("Reader's is in... reading\n");
    reading_writing();  //Simulate Reading/Writing operations
    printf("Finished reading\n");
    rwlock_release_readlock(&lock); //Release the Read Lock

    return NULL;
}

void *writer() {
    printf("Create writer\n");  //Indicates that the Writer has been created
    rwlock_acquire_writelock(&lock);    //Acquire the write lock
    printf("Writer's in... writing\n");
    reading_writing();  //Simulate Reading/Writing operations
    printf("Finished writing\n");
    rwlock_release_writelock(&lock);    //Release the Write Lock

    return NULL;
}

int main(int argc, char *argv[]) {
    pthread_t thread;
    char readerOrWriter;
    int i;
    FILE *ptr = fopen("scenarios.txt", "r");
    rwlock_init(&lock);
    
    //Check if the scenario file exists
    if(ptr) {
        printf("Scenario Starts:\n");

        //Read each line from the scenario file
        while(fscanf(ptr, "%c", readerOrWriter) != EOF) {
            for(i = 0; i < strlen(threads); i++) {

                //Create a reader thread if the character is 'r'
                if(readerOrWriter == 'r') {
                    pthread_create(&thread, NULL, (void*)reader, NULL);
                }
                else if(readerOrWriter == 'w') {    //Create a writer thread if the character is 'w'
                    pthread_create(&thread, NULL, (void*)writer, NULL);
                }
            }
            //Wait for the last created thread to finish before continuing
            pthread_join(thread, NULL);
        }
        fclose(ptr);
    }
    else {
        printf("Scenario file does not exist. \n");

        return 1;
    }

    return 0;
}

