all: preptime

preptime: preptime.c
	gcc -Wall preptime.c -o preptime

install: preptime
	cp ./preptime /usr/local/bin
