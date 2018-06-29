## Pizza Slices

### Description

You and Pak Dengklek love pizzas. Every day, both of you go to the nearest restaurant chain to eat N boxes of pizza with different flavors. Each of you and Pak Dengklek knows the flavors that each of you loves. The pizza with the i-th flavor consists of A[i] slices.

You will only eat pizzas of flavors that you love, and Pak Dengklek will only eat pizzas of flavors that he loves. For it to be fair, you and Pak Dengklek decided to take those N boxes of pizza in turns, one slice at a time in each turn.

Both of you and Pak Dengklek want to take as many slices as possible. Suppose K is the maximum mathematically possible number of slices that you can take, if both of you and Pak Dengklek use the optimal strategy. Then, you have to take K slices of pizza.

However, there are times when Pak Dengklek will always take a slice of pizza with the smallest index of flavor that he loves. Then, you have to take at least K slices of pizza (not necessarily the maximum possible number). 

### Information of Problem Type

This is an interactive problem. In this problem, you will write a program that shows the process of you taking the slices. Your program will interact with judge's program, which shows the process of Pak Dengklek taking the slices.

### Interaction Format

Initially, your proram will receive the "test case label". The label is a string with the following specification:

- The length of the string is the number of subtasks plus one.
- The first character (the index starts from 0) is '0' if the test case is a sample test case, or '.' otherwise.
- For each i, i from 1 to the number of subtasks, the following apply:
  - if the test case satisfies the constraints of the i-th subtask, then the i-th character is i, or
  - if the test case does not satisfy the constraints of the i-th subtask, then the i-th character is '.'.

For example, if the label of a test case is `0..345`, then

- The task has 5 subtasks.
- The test case is a sample test case.
- The test case satisfies the constraints of the 3rd, 4th, and 5th subtasks.

Then, your program will receive a line in the following format:

    N S

with S denoting Pak Dengklek's selection strategy:

- `1`: In each of his turns, Pak Dengklek will always take a slice of pizza with the smallest index of flavor that he loves.
- `2`: Pak Dengklek will always take the slices of pizza optimally, in such a way that he will take the maximum possible total number of slices.

Then, your program will receive a line in the following format:

    P X[1] X[2] .. X[P]

with P denoting the number of flavors of pizza that you love, and X denoting the flavors of pizza that you love.

Then, your program will receive a line in the following format:

    Q Y[1] Y[2] .. Y[Q]

with Q denoting the number of flavors of pizza that Pak Dengklek loves, and Y denoting the flavors of pizza that he loves.

Then, you and the judge (Pak Dengklek) will take the slices of pizza in turns. You start the turn.

In each of your turns, your program must output a line containing an integer C denoting that you will take a slice of pizza of flavor C. If you decide to not take a slice of pizza (for instance there is no more pizza of flavor that you love), then C must be 0.

In each of Pak Dengklek's turns, the judge's program will output a line containing an integer D denoting that Pak Dengklek will take a slice of pizza of flavor D. If there is no more pizza of flavor that Pak Dengklek loves, then D will be 0.

The interaction is over and your program **must terminate** if at any point in the interaction, the values of C and D are both 0. (In other words, both of you cannot take any more slices of pizza).

Please note that the value of K is not given as an input.

### Sample Interaction 1

| Your Program         | Judge's Program |
| ---------------------| --------------- |
|                      | 0..34\n3 1\n2 4 4\n2 3 2\n2 1 3\n |
| 2                    | |
|                      | 1 |
| 3                    | |
|                      | 1 |
| 3                    | |
|                      | 3 |
| 3                    | |
|                      | 0 |
| 2                    | |
|                      | 0 |
| 2                    | |
|                      | 0 |
| 2                    | |
|                      | 0 |
| 0                    | |
| (Interaction is over)  | (Interaction is over) |

### Explanation of Sample 1

You managed to take 7 slices of pizza. Actually, if Pak Dengklek used the optimal strategy, you would only have been able to take at most K = 6 slices. Even if you only managed to take 6 slices, your program would have been still declared correct.

### Sample Interaction 2

| Your Program         | Judge's Program |
| ---------------------| --------------- |
|                      | 0...4\n3 1\n3 4 4\n1 1\n2 1 2\n |
| 1                    | |
|                      | 1 |
| 1                    | |
|                      | 2 |
| 0                    | |
|                      | 2 |
| 0                    | |
|                      | 2 |
| 0                    | |
|                      | 2 |
| 0                    | |
|                      | 0 |
| (Interaction is over)  | (Interaction is over) |

### Explanation of Sample 2

You managed to take 2 slices of pizza. If Pak Dengklek used the optimal strategy, you would only have been able to take K = 2 slices as well, so your program is declared correct.

### Sample Interaction 3 (Declared Incorrect)

| Your Program         | Judge's Program |
| -------------------- | ------------ |
|                      | 0..34\n1 1\n4\n1 1\n1 1\n |
| 1                    | |
|                      | 1 |
| 0                    | |
|                      | 1 |
| 0                    | |
|                      | 1 |
| 0                    | |
|                      | 0 |
| (Interaction is over)  | (Interaction is over) |

### Explanation of Sample 3

Each of you and Pak Dengklek should have been able to take 2 slices of pizza, so K = 2. Because you only managed to take only 1 slice, your program is declared incorrect.

### Sample Interaction 4 (Declared Incorrect)

| Your Program         | Judge's Program |
| -------------------- | ------------ |
|                      | 0..34\n1 1\n4\n1 1\n1 1\n |
| 2                    | |
| (Interaction is over)  | (Interaction is over) |

### Explanation of Sample 4

You took a slice of non-existing pizza (there is no pizza of flavor 2), so your program is immediately declared incorrect.

### Subtasks

For all subtasks:

- 1 ≤ N ≤ 10
- 1 ≤ S ≤ 2
- 1 ≤ A[i] ≤ 10
- 0 ≤ P, Q ≤ N
- Each of X and Y consists of numbers from 1 through N without repetitions.

#### Subtask 1 (15 points):

Consists of only the following test case:

    .1.34
    4 1
    2 4 6 8
    2 3 4
    2 2 4

Note: in this test case, it is known that K = 10. The game can be played here.

#### Subtask 2 (15 points):

Consists of only the following test case:

    ..2.4
    6 1
    1 2 3 4 5 6
    6 1 2 3 4 5 6
    3 4 5 6

Note: in this test case, it is known that K = 14. The game can be played here.

#### Subtask 3 (40 points):

- S = 1
- All A[i] are even.

#### Subtask 4 (30 points):

- No additional constraints.

### Warning

After each output, you have to flush by using the following command.

- Pascal:
  ```
  flush(output);
  ```
- C/C++:
  - if you use stdio.h (cstdio) library:
    ```
    fflush(stdout);
    ```
  - if you use iostream library:
    ```
    std::cout << std::flush;
    ```
