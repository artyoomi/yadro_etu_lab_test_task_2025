# Stage 1: build
FROM gcc:11.3.0 AS builder
WORKDIR /app
COPY . .
RUN make > /dev/null

# Stage 2: run
FROM alpine:3.17
WORKDIR /app
COPY --from=builder /app/build/shm_creator /app/build/shm_reader .
CMD [ "sh", "-c", "./shm_creator | ./shm_reader" ]
