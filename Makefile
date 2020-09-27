CC = gcc
SOURCESRC = src
BUILDSRC = build
LIBRARY = gpiod
PYTHON = python3
SCRIPT = scripts
.PHONY: clean gpio.o main test py

all: clean gpio.o main

main:
	${CC} -o ${BUILDSRC}/main ${BUILDSRC}/gpio.o ${SOURCESRC}/main.c ${SOURCESRC}/gpio.h -l${LIBRARY}

gpio.o: 
	${CC} -c -o ${BUILDSRC}/gpio.o ${SOURCESRC}/gpio.c

test:
	sudo ${BUILDSRC}/main

clean:
	rm -f ${BUILDSRC}/*.o ${BUILDSRC}/main

py:
	sudo ${PYTHON} ${SCRIPT}/main.py
