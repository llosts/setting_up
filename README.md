
# Setting Up

**Setting Up** is a project focused on finding the largest square on a grid while avoiding obstacles. The grid is provided via a file or can be generated based on given parameters. The goal is to use dynamic programming to find and mark the largest possible square space on the grid. The project simulates setting up an optimal workspace in a laboratory environment, making room for further experimentation.

## Compilation

The project is compiled using the provided Makefile. It includes the following rules:

- **`make`**: Compiles the project.
- **`make clean`**: Cleans up the compiled object files.
- **`make fclean`**: Removes all generated files, including the binary.

### Compilation Instructions

To compile the project, run the following command in your terminal:

```bash
make
```

This will compile the project and create the executable `setting_up`.

To clean up object files, use the command:

```bash
make clean
```

To remove all generated files, including the binary:

```bash
make fclean
```

### File Input Format

- The first line of the file contains the number of lines on the board.
- The remaining lines represent the grid, with `.` indicating empty spaces and `o` indicating obstacles.
- All lines must have the same length, except the first one.
- The board must contain at least one line, and each line must end with a newline (`
`).

### Example Input File

```text
9
...........................
....o....................
............o............
...........................
....o....................
..............o..........
...........................
......o..............o...
..o.......o................
```

### Example Usage

1. **Classic Execution**: Using a file as input:

```bash
./setting_up example_file | cat -e
```

Output:

```text
.....xxxxxxx................$
....oxxxxxxx................$
.....xxxxxxxo...............$
.....xxxxxxx................$
....oxxxxxxx................$
.....xxxxxxx...o............$
.....xxxxxxx................$
......o...............o....$
..o.......o.................$
```

2. **Generating Execution**: Generating a board based on given parameters:

```bash
./setting_up 6 "..o.."
```

Output:

```text
..oxx.$
.o.xx.$
o....o$
....o.$
...o..$
..o...$
```

### Dynamic Programming

The program uses dynamic programming to calculate the largest square that can be formed by empty spaces (denoted by `.`). It efficiently calculates the square’s position and size and prints it on the board by replacing `.` with `x` to represent the largest square.

If multiple solutions exist, the program selects the largest square, and if there are still ties, it chooses the square on the leftmost side.

## Tests

### Basic Tests

- **Generating Square of 14 with 25% Obstruction**: Passed
- **Opening Rectangle (97 x 21) with 50% Obstruction**: Passed

### Advanced Tests

- **Algorithm Application - Generating Column**: Passed
- **Data Structure - Generating**: Passed
- **Optimization - Generating 100 to 500**: Passed
- **Robustness - Generating Valid Board**: Passed

### Code Coverage

The project has **91% line coverage** as indicated by the code coverage report. Files with lower coverage include:

- **`src/generate_or_read_map.c`** (80% coverage)
- **`src/error_gestion.c`** (87% coverage)