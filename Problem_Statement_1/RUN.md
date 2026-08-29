# How to Run Your Submission

## Honest note from my side:
I did use AI for RUN.md as I had no idea how to make this.
I used windows.h because threads wasn't working.
My exception handling is bad as the program crashes if exception arises so please enter input exactly as it was mentioned in each test case.
I have used the exact same input format and output format as test cases.
Do not enter a grid in 'classify' feature which requires over 100 generation to show oscillation as it is its max scan limit.
The rest below is exactly what you asked for  :)

## Language

**C++17**

## Platform

**Windows**

> The program uses Windows-specific functionality such as `windows.h`, `Sleep()`, and `system("cls")`, so it is intended to be compiled and run on Windows.

## Source File

```text
PS1_soln_final.cpp
```

## Compilation

Open a terminal in the directory containing `PS1_soln_final.cpp` and run:

```bash
g++ -std=c++17 PS1_soln_final.cpp -o PS1_soln_final
```

This will create the executable:

```text
PS1_soln_final.exe
```

## Running the Program

Run the executable using:

```bash
PS1_soln_final.exe
```

Alternatively:

```bash
./PS1_soln_final
```

---

# Input Format

The program first takes the mode, followed by the grid dimensions and the required input for that mode.

## Standard Game of Life

Leave the mode blank, then enter:

```text
<rows> <columns>
<generations>
<initial grid>
```

Example:

```text
5 5
3
.....
..#..
..#..
..#..
.....
```

## Toroidal Mode

Enter:

```text
toroidal
<rows> <columns>
<generations>
<initial grid>
```

Example:

```text
toroidal
5 5
3
.....
..#..
..#..
..#..
.....
```

## Classification Mode

Enter:

```text
classify
<rows> <columns>
<initial grid>
```

The generation count is **not required as input** for this mode.

The program internally runs the simulation for a sufficient number of generations to detect patterns such as **extinction, still lifes, and oscillators**.

Example:

```text
classify
5 5
.....
..##.
..##.
.....
.....
```

## Metrics Mode

Enter:

```text
metrics
<rows> <columns>
<generations>
<initial grid>
```

Example:

```text
metrics
5 5
3
.....
..#..
..#..
..#..
.....
```

## Animation Mode

Enter:

```text
animate
<rows> <columns>
<generations>
<initial grid>
```

Example:

```text
animate
5 5
3
.....
..#..
..#..
..#..
.....
```

---

# Grid Format

The initial grid uses:

* `#` — living cell
* `.` — dead cell

Each row of the grid must contain exactly the specified number of columns.

For example, a `5 × 5` grid can be:

```text
.....
..#..
..#..
..#..
.....
```

---

# Running with an Input File

Input can also be provided through a text file.

For example:

```bash
PS1_soln_final.exe < input.txt
```

or:

```bash
./PS1_soln_final < input.txt
```

The contents of `input.txt` should follow the input format corresponding to the selected mode.
