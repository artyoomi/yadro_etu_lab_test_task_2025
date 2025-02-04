#!/bin/bash

docker build -t shm-app .
docker run --rm shm-app
