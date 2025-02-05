# Shared memory and Docker

### Description
Test task in Yadro lab in ETU "LETI", 2025.

### Dependencies
To run program you must have [Docker](https://docs.docker.com/engine/install/ubuntu/) installed.

### Run
To execute programs in Docker container use
```
chmod +x start_docker.sh
./start_docker.sh          # may require sudo
```


### Task

**It is necessary to create 2 programs in the C/C++ language:**
- The first program should create a 1000 byte shared memory region and write the string “Hello world!” and
output the shared memory key to the standard output stream. In case of an error, the program should output the error code and the decoding of the error code;
- The second program should read the shared memory key from the output of the first program, read the contents of the memory section and output it to the
standard output stream as a string. In case of an error, the program should output the error code and the decoding of the error code.
Before terminating, the program must delete the specified portion of shared memory for all processes.
 
**Requirements for completing the task:**
- Programs must be run inside a Docker container. The official gcc image must be used as the base docker image: gcc:11.3.0;
- You need to create your own repository for this task. The repository should contain the source code files, dockerfile, scripts for building and running the job, and instructions for starting and building;
- Programs should not use third-party libraries for interprocess communication that use a shared memory mechanism (standard library functions must be used).
