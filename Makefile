#*************************************************
#    N Queens Puzzle encoder in CNF-SAT DIMACS
#
#       Copyright 2020 Borja González Seoane
#
#               LICENSE BSD 2-Clause
#*************************************************

CC=clang
N_QUEENS=8  # Default value

run: encoder
	./encoder

compile: encoder.c
	$(CC) -o encoder encoder.c -DN=$(N_QUEENS)

clean:
	rm -f encoder clauses.txt coding.cnf result.txt
