## GCD Festival

### Description

At a small village in Padang, there are N houses lined up in a row. The i-th house consists of A[i] family members.

To increase the village income, the mayor is organizing a program called "GCD Festival". Every day, the mayor will pick one or more houses, then split them into exactly K groups in such a way that two consecutive houses are considered to be in the same group. Then, each group will donate an amount that equals to the greatest common divisor (GCD) of the number of family members in every house in that group.

The mayor will always choose a different way of choosing K groups every day. The festival is over when all possible ways have occurred.

The mayor is now curious, in the end, what is the total income obtained from this festival? Since the amount can be very large, he is only interested in the result modulo 1.000.000.007.

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

    N K
    A[1] A[2] .. A[N]

### Output Format

A single line containing the total income, modulo 1.000.000.007.

### Sample Input

    0..3.56..9
    3 2
    6 4 5

### Sample Output

    44

### Explanation

Here are all possible ways to choose K groups along with the respective incomes:

- [6] [4] 5: GCD(6) + GCD(4) = 6 + 4 = 10.
- [6] 4 [5]: GCD(6) + GCD(5) = 6 + 5 = 11.
- [6] [4 5]: GCD(6) + GCD(4, 5) = 6 + 1 = 7.
- [6 4] [5]: GCD(6, 4) + GCD(5) = 2 + 5 = 7.
- 6 [4] [5]: GCD(4) + GCD(5) = 4 + 5 = 9.

Therefore, the total income is 10 + 11 + 7 + 7 + 9 = 44.

### Subtasks

For all subtasks:

- 1 ≤ N ≤ 50.000
- 1 ≤ K ≤ min(N, 20)
- 1 ≤ A[i] ≤ 100.000

#### Subtask 1:

Consists of only the following test case:

    .1.34567.9
    9 1
    30 15 3 48 24 8 12 100 52


#### Subtask 2:

Consists of only the following test case:

    ..23..6.89
    9 3
    1 1 1 1 1 1 1 1 1

#### Subtask 3:

- 1 ≤ N ≤ 10

#### Subtask 4:

- 1 ≤ N ≤ 500
- K = 1

#### Subtask 5:

- 1 ≤ N ≤ 500
- 1 ≤ K ≤ min(N, 2)

#### Subtask 6:

- 1 ≤ N ≤ 500

#### Subtask 7:

- K = 1

#### Subtask 8:

- All values of A[i] are equal.

#### Subtask 9:

- No additional constraints.
