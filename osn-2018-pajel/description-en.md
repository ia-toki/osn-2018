## The Game of Pajel

### Description

Pak Dengklek invented a new solitaire game for you called Pajel. This game consists of a grid of N rows and N columns. Initially, each square on the grid is white. You have to color zero or more squares with maroon (M) or blue (B), in such a way that you satisfy all conditions on the outside of the four sides of the grid.

Each square above the top side of the grid contains one of the following conditions:

- A positive integer followed by a character 'M' or 'B': the integer denotes the shortest distance of a colored square from the top side on that column, and the character denotes the color.
- Character '0': denotes that there are no colored squares on that column.
- Character '-': denotes nothing and can be ignored.

The squares on the outside of the left, right, and bottom sides are defined similarly (for left and right sides, replace "column" with "row" in the above rules).

Two squares with the same color (other than white) that share the same side, are considered to be in the same region.

As an example, here are two different solutions to the same Pajel game. In both solutions, there are 3 regions.

[pajel_1.png] [pajel2_.png]

Here is another solution, that has 6 regions.

[pajel_3.png]

In this game, your goal is to color the squares in such a way that the number of regions is as small as possible. Let the number of regions in judge's solution be P, and in your solution be Q. Your score will depend on how close Q to P, using a formula that will be explained in the Scoring section.

### Problem Type Information

This is an "output-only" problem. For each test case, you write the output to a file. 

The input files for this problem can be downloaded here. There are 1 + 8 input files to solve: osn-2018-pajel\_0.in, osn-2018-pajel\_1.in, osn-2018-pajel\_2.in, ..., osn-2018-pajel\_8.in. The sample input (numbered 0) is not scored.

For each input file that you solve (you don't have to solve all input files), create an output file osn-2018-pajel\_X.out, where X is the test case number. Then, compress all files into a single .zip file, and submit.

### Input Format

The input is given with the following format:
    
    N P
    U[1] U[2] ... U[N]
    L[1] R[1]
    L[2] R[2]
    .
    .
    L[N] R[N]
    D[1] D[2] .. D[N]

where:

- N denotes the number of rows and columns.
- P denotes the number of regions in judge's solution.
- U[i] denotes the condition to the top of the i-th column.
- L[i] denotes the condition to the left of the i-th row.
- R[i] denotes the condition to the right of the i-th row.
- D[i] denotes the condition to the bottom of the i-th column.

### Output Format

For each test case, output N rows of N characters each, denoting the color of each square: 'M' for maroon, 'B' for blue, and '-' for white.

### Sample Input

    0
    5 3
    1M - - - -
    - -
    1B 3B
    0 -
    - -
    5M 1M
    4B - 2M - -

### Sample Output

    MM---
    BBB--
    -----
    -MMMM
    ----M

### Explanation

The above output corresponds to the solution in the first image above.

### Constraints

- 5 ≤ N ≤ 500
- 1 ≤ P ≤ N^2
- It is guaranteed that at least one solution exists.

### Scoring

TBA