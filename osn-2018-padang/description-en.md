## Padang Defense

### Description

Padang city is famous for its "binary poems". A binary poem is a string consisting of only characters '0' or '1'. An "alternating binary poem" is a string S that satisfies all of the following conditions:

- S is a binary poem.
- S consists of 1 or more characters.
- S[0] = '1'. (0-based indexing.)
- S[i] and S[i-1] differ, for i > 0.

For example, "1", "10", "101", and "1010" are all alternating binary poems.

One day, Padang city is being attacked by an evil creature! Pak Dengklek, the ruler of Padang city, is now negotiating with the evil creature for it to go away. It turns out that the evil creature only wants a binary poem S that satisfies all of the following conditions: 

- S contains exactly A subsequences that are alternating binary poems of odd length.
- S contains exactly B subsequences that are alternating binary poems of even length.

A subsequence of S is produced by removing zero or more characters from S. For example, the binary poem "011" contains exactly 7 subsequences that are binary poems: "0" (1 time), "1" (2 times) "01" (2 times), "11" (1 time), and "011" (1 time).

Since it is possible that there are multiple binary poems that satisfy the conditions, the evil creature wants the lexicographically smallest such binary poem (see the Notes section).

Since S can be very long, the evil creature will take it easy by only asking Q questions. The i-th question is: what are the characters of S at indices from L[i] through R[i], inclusive?

Help Pak Dengklek answer the questions!

### Notes

The lexicographical ordering is defined as follows: a string U is considered to be lexicographically smaller than a string V if U is a prefix of V, or at the smallest index i where U[i] and V[i] differ, U[i] < V[i].

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

    A B Q
    L[1] R[1]
    L[2] R[2]
    .
    .
    L[Q] R[Q]
    
### Output Format

If there is no possible binary poem S that satisfies the conditions, output a single line containing:

    TIDAK MUNGKIN

(It is an Indonesian phrase that means "impossible".)
    
If there is a solution, output:

    MUNGKIN
    T[1]
    T[2]
    .
    .
    T[Q]
    
where T[i] is the answer to the i-th question, if L[i] and R[i] are both valid indices of S, or `DI LUAR BATAS` otherwise.

("MUNGKIN" is an Indonesian phrase that means "possible", and "DI LUAR BATAS" is an Indonesian phrase that means "out of bound".)

### Sample Input 1

    0....56.8
    5 2 4
    0 3
    1 2
    3 3
    0 4

### Sample Output 1

    MUNGKIN
    1101
    10
    1
    DI LUAR BATAS

### Explanation of Sample 1

The lexicographically smallest binary poem that satisfies the conditions is S = "1101":

- There are exactly A = 5 subsequences that are alternating binary poems of odd length: "1" (3 times) and "101" (2 times").
- There are exactly B = 2 subsequences that are alternating binary poems of even length: "10" (2 times).

### Sample Input 2

    0....56.8
    3 2 4
    0 3
    1 2
    3 3
    0 4

### Sample Output 2

    TIDAK MUNGKIN

### Subtasks

For all subtasks:

- 0 ≤ A, B ≤ 10^15
- A + B > 0
- 0 ≤ Q ≤ 20.000
- 0 ≤ L[i] ≤ R[i] < 10^16
- R[i] - L[i] ≤ 50

#### Subtask 1:

Consists of only the following test case:

    .1..456.8
    3 9 1
    1 4

#### Subtask 2:

Consists of only the following test case:

    ..2..56.8
    25 3 4
    0 7
    0 8
    0 9
    0 10

#### Subtask 3: 

- 0 ≤ A + B ≤ 8
- Q = 1

#### Subtask 4:

- 0 ≤ A + B ≤ 18
- Q = 1

#### Subtask 5:

- 0 ≤ A, B ≤ 2.000

#### Subtask 6:

- 0 ≤ A, B ≤ 1.000.000

#### Subtask 7:

- Q = 0

#### Subtask 8:

- No additional constraints.
