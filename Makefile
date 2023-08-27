CC=gcc
CFLAGS=-Wall -Werror -Wextra
EXEC=bsq
OBJECTS=main.o lib/output_utils.o lib/reading_utils.o lib/extract_map.o lib/solution.o
HEADER=lib/header.h

all: $(EXEC)

bsq: $(OBJECTS)
	$(CC) -o $(EXEC) $(OBJECTS) $(HEADER)
main.o:	main.c
	$(CC) -o main.o -c main.c $(CFLAGS)
reading_utils.o: lib/reading_utils.c
	$(CC) -o reading_utils.o -c reading_utils.c
output_utils.o: lib/output_utils.c
	$(CC) -o output_utils.o -c output_utils.c
extract_map.o: lib/extract_map.c
	$(CC) -o extract_map.o -c extract_map.c
solution.o: lib/solution.c
	$(CC) -o solution.o -c soluion.c
clean:
	rm -rf $(OBJECTS) $(EXEC)
