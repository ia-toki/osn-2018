## The Game of Mejik

### Description

Pak Dengklek invented a new solitaire game for you called Mejik. This game consists of a grid of N rows and N columns. Rows and columns are numbered 1 through N.

Initially, each square is empty. You have to fill each square with a number from 1 through N^2, each exactly once, by considering the clues on the outside of the right and bottom sides of the grid.

Each square outisde of the right and bottom sides of the grid contains one of the following clues:

- A sum clue: a positive integer that denotes the sum of all numbers on that row (for right-side clues) or column (for bottom-side clues).
- An empty clue: a character '-', which can be ignored.

As an example, here are two different solutions to the same Mejik game. In both solutions, all sum clues are satisfied.

[mejik_1.png] [mejik_2.png]

Here is another solution. In this solution, only a single sum clue is satisfied (the first column).

[mejik_3.png]

In this game, your score depends on the number of sum clues that are satisfied. The more, the better, as explained in the Scoring section.

### Problem Type Information

This is an "output-only" problem. For each test case, you write the output to a file. 

The input files for this problem can be downloaded here. There are 1 + 5 input files to solve: osn-2018-mejik\_0.in, osn-2018-mejik\_1.in, osn-2018-mejik\_2.in, ..., osn-2018-mejik\_5.in. The sample input (numbered 0) is not included in the final score.

For each input file that you solve (you don't have to solve all input files), create an output file osn-2018-mejik\_X.out, where X is the test case number. Then, compress all files into a single .zip file, and submit.

### Input Format

The input is given in the following format:

    N
    R[1] R[2] .. R[N]
    C[1] C[2] .. C[N]

where:

- R[i] denotes the clue to the right of the i-th row.
- D[i] denotes the clue to bottom of the i-th column.

### Output Format

N rows of N numbers each, denoting the numbers in the solution.

### Sample Input

    5
    - 38 64 - 92
    15 - 67 - -

### Sample Output

    1 20 8 9 14
    2 6 7 10 13
    3 22 16 11 12
    4 17 21 19 18
    5 25 15 23 24

### Explanation of Sample

The above output corresponds to the solution in the first image above.

### Scoring

For each test case, your score is 20 × (the number of satisfied sum clues) / (the number of sum clues), rounded down.

### Test Cases

For each test case:

- 4 ≤ N ≤ 8
- It is guaranteed that at least one solution exists that satisfies all clues.

#### osn-2018-mejik_1.in

- N = 4
- All rows and columns contain sum clues.

#### osn-2018-mejik_2.in

- N = 5
- Only the first and last rows and columns contain sum clues.

#### osn-2018-mejik_3.in

- N = 6
- All clues are sum clues of the same integer.

#### osn-2018-mejik_4.in

- N = 7
- All rows contain sum clues.
- All columns contain empty clues.

#### osn-2018-mejik_5.in

- N = 8
