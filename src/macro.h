#ifndef MACRO_H
#define MACRO_H

// Size in bytes of shared memory region
#define REGION_SIZE 1000

/*
 * Macro function to automate error msg printing
 * Requires included: stdio.h, errno,h, string.h
 */
#define PRINT_ERRMSG(func_name) \
        fprintf(stderr, "%d: %s: %s\n", errno, (func_name), (strerror(errno)))

#endif
