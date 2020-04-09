# N Queens Puzzle encoder in CNF-SAT DIMACS

This program is designed for purely demonstrative academic use and its purpose is not the resolution of the N Queens Puzzle itself, which is delegated to **Clasp**, but its formalization as a set of clauses in conjunctive normal form (CNF) in CNF-SAT DIMACS format; and its layout representation in a easy to understand TUI board. In this way, problems for a variable number of queens can be conveniently represented in CNF to solve it with Clasp or even with other SAT solvers that manage DIMACS CNF format.

An example output for an `N=7` puzzle:

```
N Queens Puzzle SATISFIABLE for 7 queens.
This is a possible model:

  . . . . Q . .
  . . Q . . . .
  Q . . . . . .
  . . . . . Q .
  . . . Q . . .
  . Q . . . . .
  . . . . . . Q

```

**This software uses [Clasp](https://potassco.org/clingo/) during its execution, so `clasp` has to be installed and reachable in your shell `PATH` variable or the program will break.**

## How works

This program receives in terminal a natural number `N`, which represents the dimension of the problem (board dimension and number of queens to put).

Then, the program writes the problem specification in DIMACS CNF format and delegates its resolution to Clasp. [Clasp](https://potassco.org/clingo/), from Potassco, is a mandatory dependency of this software.

The program generates the files:

- `clauses.txt`: with only the CNF-SAT DIMACS clauses.
- `coding.cnf`: with the full CNF-SAT DIMACS.
- `solution.txt`: with the Clasp solution replay.

## Use of the software

These commands use the Clang compiler, but it is fully replaceable by GCC.

### Compilation

```sh
make compile
```

### Compilation editing the number of queens

```sh
make compile N_QUEENS=<n_queens>
```

When is the desired number of queens, e.g. 16.

### Run

```sh
make run
```

### Clean

```sh
make clean
```