/*
 * Program logic:
 * 1. Input key of shared memory from stdout of first program;
 * 2. Read data from shared memory region;
 * 3. Print recieved data to stdout or error code with message;
 * 4. Delete shared memory region for all processes.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#include "macro.h"

int main()
{
        key_t shm_key;
        int   shmid;
        char* segm_seq;
        char  recieved_data[REGION_SIZE];

        // Get data from stdout of first program
        scanf("%d", &shm_key);
        
        // Create shared memory segment
        if ((shmid = shmget(shm_key, REGION_SIZE, 0666)) == -1) {
                PRINT_ERRMSG("shmget");
                exit(EXIT_FAILURE);
        }

        // Attach segm_seq to shared memory segment
        if ((segm_seq = (char*)shmat(shmid, NULL, 0)) == (void*) -1) {
                PRINT_ERRMSG("shmat");
                exit(EXIT_FAILURE);
        }

        // Read data from shared memory region
        strncpy(recieved_data, segm_seq, REGION_SIZE);

        // Detach from shared memory region
        if (shmdt(segm_seq) == -1) {
                PRINT_ERRMSG("shmat");
                exit(EXIT_FAILURE);
        }

        // Delete shared memory region
        if (shmctl(shmid, IPC_RMID, NULL) == -1) {
                PRINT_ERRMSG("shmctl");
                exit(EXIT_FAILURE);
        }

        // Write data from shared memory region to stdout
        printf("%s\n", recieved_data);
        
        return 0;
}
