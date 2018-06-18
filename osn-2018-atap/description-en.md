## Rooftop Decoration

### Description

Pak Dengklek wants to make a decoration for his rooftop. He has N bricks of sizes 1 × N, 1 × (N-1), ..., 1 × 1. He will put the bricks one-by-one from the longest to the shortest, in that order.

Firstly, Pak Dengklek puts the longest brick so that it is placed at columns 1 through N. Then, he will put each of the next bricks above the immediate previous brick, in one of the following ways: left-aligned, or right-aligned.

For example, suppose N = 7. Initially, Pak Dengklek puts the 1 × 7 brick at columns 1 through 7. Suppose that for the next 6 bricks, the alignments are left, right, right, left, right, right. Then, the final result of the rooftop decoration is as follows:

[atap.png]

Since Pak Dengklek has so many bricks, the configuration of brick placements will be denoted by the concatenation of K copies of a string S. Therefore, N = |S| × K + 1. The i-th character of the concatenated string is the alignment of the (i+1)-th brick, with 'A' denoting left alignment and 'B' denoting right alignment. For example, the above illustration can be denoted by S = "ABB" and K = 2.

Pak Dengklek is now curious about the height of the highest brick within a column range. For example, from columns 1 through 7, the height is 7 (the highest brick is at column 5). Another example, from column 2 through 4, the height is 6 (the highest brick is at column 4).

Pak Dengklek has Q questions. The i-th question asks for the height of the highest block from columns L[i] through R[i], inclusive. Help him answer the questions!

### Input Format

The first line contains the "test case label". The label is a string with the following specification:

- The length of the string is the number of subtasks plus one.
- The first character (the index starts from 0) is '0' if the test case is a sample test case, or '.' otherwise.
- For each i, i from 1 to the number of subtasks, the following apply:
  - if the test case satisfies the constraints of the i-th subtask, then the i-th character is i, or
  - if the test case does not satisfy the constraints of the i-th subtask, then the i-th character is '.'.

For example, if the label of a test case is `0..345`, then

- The task has 5 subtasks.
- The test case is a sample test case.
- The test case satisfies the constraints of the 3rd, 4th, and 5th subtasks.

The next lines are given in the following format:

    S
    K Q
    L[1] R[1]
    L[2] R[2]
    .
    .
    L[Q] R[Q]

### Output Format

Q lines, containing the answers to each question.

### Sample Input

    0.......8
    ABB
    2 4
    1 7
    2 4
    6 7
    1 1

### Sample Output

    7
    6
    4
    2

### Explanation

This sample test case corresponds to the illustration in the problem description.

### Subtasks

For all subtasks:

- 1 ≤ |S| ≤ 100.000
- S consists of only characters 'A' or 'B'.
- 1 ≤ K ≤ 10^9
- 1 ≤ Q ≤ 100.000
- 1 ≤ L[i] ≤ R[i] ≤ N

#### Subtask 1:

Consists of only the following test case:

    .1......8
    AABA
    3 6
    1 4
    5 9
    10 13
    1 2
    3 5
    10 12

#### Subtask 2:

Consists of only the following test case:

    ..2.....8
    AABABAABB
    11 7
    1 100
    1 1
    2 2
    3 3
    98 98
    99 99
    100 100

#### Subtask 3:

- |S| ≤ 1.000
- K = 1

#### Subtask 4:

- K = 1
- Q = 1

#### Subtask 5:

- Q = 1

#### Subtask 6:

- |S| ≤ 2

#### Subtask 7:

- For each i, L[i] = R[i]

#### Subtask 8:

- No additional constraints.
