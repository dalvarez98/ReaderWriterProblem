This code implements a solution to the Reader-Writer problem using semaphores for synchronization. The rwlock_t structure contains counters and semaphores for readers, writers, and fairness. The provided functions allow acquiring and releasing read and write locks while ensuring fairness in access. The reading_writing() function simulates reading and writing operations with random delays.

To compile the program:
using this command: make

or

using this command:  $ gcc -o rwmain main.c readerwriter.c  -l pthread

To run the program:
- Include scenarios.txt to run a scenario for the program.
- In addition, you could modify that scenario to test other scenarios (1 scenario per run). 
- run ./rwmain to see the result.

Scenario.txt (rwrrrrwrr)
$ gcc -o rwmain main.c readerwriter.c  -l pthread
 ./rwmain

Scenario Starts:
Create reader
Create writer
Create reader
Reader's is in... reading
Create reader
Create reader
Reader's is in... reading
Create writer
Writer's in... writing
Writer's in... writing
Create reader
Reader's is in... reading
Create reader
Finished writing
Create reader
Reader's is in... reading
Reader's is in... reading
Reader's is in... reading
Reader's is in... reading
Finished reading
Finished reading
Finished writing
Finished reading
Finished reading
Finished reading
Finished reading
Finished reading

Scenario.txt (wwrrrrwr)
$ gcc -o rwmain main.c readerwriter.c  -l pthread
 ./rwmain

Scenario Starts:
Create writer
Create writer
Create reader
Create reader
Reader's is in... reading
Create reader
Reader's is in... reading
Writer's in... writing
Writer's in... writing
Reader's is in... reading
Create reader
Reader's is in... reading
Create reader
Reader's is in... reading
Create writer
Writer's in... writing
Finished writing
Finished writing
Finished reading
Finished writing
Finished reading
Finished reading
Finished reading
Finished reading

Scenario.txt (rwrrrrwrr wwrrrrwr)
$ gcc -o rwmain main.c readerwriter.c  -l pthread
 ./rwmain

Scenario Starts:
Create writer
Create reader
Create reader
Create reader
Writer's in... writing
Reader's is in... reading
Create reader
Reader's is in... reading
Create writer
Reader's is in... reading
Reader's is in... reading
Create reader
Reader's is in... reading
Writer's in... writing
Create reader
Reader's is in... reading
Create reader
Reader's is in... reading
Finished reading
Finished reading
Finished reading
Create writer
Writer's in... writing
Create reader
Reader's is in... reading
Create reader
Create writer
Reader's is in... reading
Create writer
Writer's in... writing
Create reader
Reader's is in... reading
Create reader
Reader's is in... reading
Create reader
Reader's is in... reading
Writer's in... writing
Finished writing
Finished reading
Finished reading
Finished reading
Finished writing
Finished reading
Finished reading
Finished writing
Finished writing
Finished writing
Finished reading
Finished reading
Finished reading
Finished reading
