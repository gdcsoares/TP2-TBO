CC = gcc
CFLAGS = -Wall -Wno-unused-result -g

SRCS =main.c  source/graph/graph.c source/node/node.c  priority_queue/PQ.c source/algorythm/algorythm.c source/rtt/rtt.c
OBJS = $(SRCS:.c=.o)

all: trab2

trab2: $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) trab2 *.out 

run:
	./trab1

val:
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s time ./main