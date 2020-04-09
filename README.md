# N Queens Puzzle encoder in CNF-SAT DIMACS

The purpose of this program is not the resolution of the N Queens Puzzle itself, which is delegated to the **Clasp** SAT-solver, but its formalization as a set of clauses in conjunctive normal form (CNF) using the CNF-SAT DIMACS format. This program also prints a layout representation in a easy to understand TUI board.

In this way, problems for a variable number of queens can be conveniently represented to solve it with Clasp or even with other SAT solvers that manage CNF-SAT DIMACS format.

**This program is designed for purely demonstrative academic use.**

An example output for an 8x8 puzzle:

```
. . . . Q . . .
. . Q . . . . .
Q . . . . . . .
. . . . . . Q .
. Q . . . . . .
. . . . . . . Q
. . . . . Q . .
. . . Q . . . .
```

**This software uses [Clasp](https://potassco.org/clingo/) during its execution, so `clasp` has to be installed and reachable in your shell `PATH` variable or the program will break.**

## How works

This program takes a natural number `N` as macro, which represents the dimension of the problem (board dimension and number of queens to put). Then, the program writes the problem specification in DIMACS CNF format and delegates its resolution to Clasp.

The program generates the files:

- `clauses.txt`: with only the CNF-SAT DIMACS clauses.
- `coding.cnf`: with the full CNF-SAT DIMACS specification.
- `solution.txt`: with the Clasp solution replay.

## Use of the software

By default these commands use the Clang compiler, but it is fully replaceable by GCC.

### Compilation

```sh
make compile
```

### Compilation editing the number of queens

```sh
make compile N_QUEENS=<n_queens>
```

When `<n_queens>` is the desired number of queens, e.g. 16.

### Run

```sh
make run
```

### Clean

```sh
make clean
```