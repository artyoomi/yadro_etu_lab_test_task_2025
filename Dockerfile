# Base image
FROM gcc:11.3.0

ARG APP_DIR=/shm_app

# Set working directory
WORKDIR ${APP_DIR}

# Copy necessary files in container
COPY src ${APP_DIR}/src
COPY Makefile start_programs.sh ${APP_DIR}/

# Compile and execute programs 
CMD ["./start_programs.sh"]
