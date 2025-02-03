/*
 * Program logic:
 * 1. Create shared memory region;
 * 2. Write "Hello world!" in this region;
 * 3. Print to stdout shared memory key or
 * error code and message (if occured).
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

// Size in bytes of shared memory region
#define REGION_SIZE 1000

// String to output in shared memory segment
#define OUTPUT_STR  "Hello world!"

/*
 * Macro function to automate error msg printing
 * Requires included: stdio.h, errno,h, string.h
 */
#define PRINT_ERRMSG(func_name) \
        fprintf(stderr, "%d: %s: %s\n", errno, (func_name), (strerror(errno)))

int main()
{
        key_t shm_key;
        int   shmid;
        char* segm_seq;
        
        // Generate shared memory key
        if ((shm_key = ftok("Dockerfile", 'x')) == -1) {
                PRINT_ERRMSG("ftok");
                exit(EXIT_FAILURE);
        }

        // Create shared memory segment
        if ((shmid = shmget(shm_key, REGION_SIZE, IPC_CREAT | IPC_EXCL | 0600)) == -1) {
                PRINT_ERRMSG("shmget");
                exit(EXIT_FAILURE);
        }

        // Attach segm_seq to shared memory segment
        if ((segm_seq = (char*)shmat(shmid, NULL, 0)) == (void*) -1) {
                PRINT_ERRMSG("shmat");
                exit(EXIT_FAILURE);
        }

        // Write OUTPUT_STR to shared memory region
        strncpy(segm_seq, OUTPUT_STR, REGION_SIZE);

        // Detach from shared memory region
        if (shmdt(segm_seq) == -1) {
                PRINT_ERRMSG("shmat");
                exit(EXIT_FAILURE);
        }

        // Write shared memory region key to stdout
        printf("%d", shm_key);
        
        return 0;
}
