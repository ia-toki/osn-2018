## Triplet Challenge

### Description

Pak Dengklek has N numbers: A[1], A[2], ..., A[N]. Count the number of triplets (i, j, k) satisfying all of the following conditions:

- 1 ≤ i < j < k ≤ N
- A[i] ≠ A[j]
- A[i] ≠ A[k]
- A[j] ≠ A[k]

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

    N
    A[1] A[2] .. A[N]

### Output Format

A single line containing the number of triplets satisfying the conditions.

### Sample Input

    0..3456
    4
    1 4 1 2

### Sample Output

    2

### Explanation of Sample

The triplets satisfying the conditions are (1, 2, 4) and (2, 3, 4).

### Subtasks

For all subtasks:

- 3 ≤ N ≤ 100.000
- 1 ≤ A[i] ≤ 100.000

#### Subtask 1:

Consists of only the following test case:

TODO

#### Subtask 2:

Consists of only the following test case:

TODO

### Subtask 3:

- N ≤ 100

#### Subtask 4:

- N ≤ 2.000

#### Subtask 5:

- A[i] ≤ 100

#### Subtask 6:

- No additional constraints.
