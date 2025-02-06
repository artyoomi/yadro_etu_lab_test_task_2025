#!/bin/bash

# Write all stdout to /dev/null
make 1> /dev/null

./build/shm_creator | ./build/shm_reader
