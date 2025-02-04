# Base image
FROM gcc:11.3.0

# Set working directory
WORKDIR /app

# Copy necessary files in container
COPY macro.h .
COPY shm_creator.c .
COPY shm_reader.c .
COPY start_programs.sh .

# Compile programs
RUN gcc -o shm_creator shm_creator.c
RUN gcc -o shm_reader shm_reader.c

# Make start.sh executable
RUN chmod +x start_programs.sh

CMD ["./start_programs.sh"]
