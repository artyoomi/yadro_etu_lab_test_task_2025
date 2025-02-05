CC     := gcc
CFLAGS := -Wall -Wextra -Werror

SRCDIR   := src
BUILDDIR := build

TARGET1 := ${BUILDDIR}/shm_creator
TARGET2 := ${BUILDDIR}/shm_reader

.PNONY: all clean

all: ${BUILDDIR} ${TARGET1} ${TARGET2}

${TARGET1}: ${SRCDIR}/macro.h ${SRCDIR}/shm_creator.c
	${CC} ${CFLAGS} -o $@ $^

${TARGET2}: ${SRCDIR}/macro.h ${SRCDIR}/shm_reader.c
	${CC} ${CFLAGS} -o $@ $^

${BUILDDIR}:
	mkdir -p ${BUILDDIR}

clean:
	rm -rf ${BUILDDIR}
