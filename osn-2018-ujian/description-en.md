## Skybridges

In Padang city, there is a famous college called the University of Dengklek. All students stay in an N-level dorm building. This year, the college has finished constructing a new N-level dorm building.

There are K skybridges between the two buildings. The i-th skybridge is mounted at the height of level H[i]. Each level in each building is only connected to exactly one skybridge via a special tunnel. Level i in the old building is only connected to the A[i]-th skybridge, and level i in the new building is only connected to the B[i]-th skybridge.

The college wants to relocate all students to the new building. Students on each level in the old building will be relocated to a level in a new building. No two levels in the old building will be relocated to the same level in the new building. In other words, the college wants to figure out a permutation P over {1, 2, ..., N} denoting that students on level i in the old building will be relocated to level P[i] in the new building.

For security reasons, the college wants to impose the following restrictions for each level in the relocation:

- Students on each level in the old building will go to the only connected skybridge, then walk along the skybridge, and then go to a level in the new building that is connected to the skybridge.
- The old level in the old building and the new level in the new building must not be both higher or both lower than the connecting skybridge.

Or, more formally, for each i, all of the following conditions must be satisfied:

- A[i] = B[P[i]]
- If i > H[A[i]], then it must be the case that P[i] ≤ H[A[i]].
- If i < H[A[i]], then it must be the case that P[i] ≥ H[A[i]].

Now, the college is curious: how many different permutations are possible?

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
    H[1] H[2] .. H[K]
    A[1] A[2] A[3] .. A[N]
    B[1] B[2] A[3] .. B[N]

### Output Format

A single line consisting of the number of possible permutations, modulo 1.000.000.007.

### Sample Input 1

    0...45.7
    6 1
    3
    1 1 1 1 1 1
    1 1 1 1 1 1

### Sample Output 1

    36

### Explanation of Sample 1

There are 6 levels, and 1 skybridge located at the height of level 3. Each level in both old and new buildings is connected to the skybridge.

According to the restrictions:

- Level 1 in the old building can only be relocated to levels 3, 4, 5, or 6 in the new building.
- Level 2 in the old building can only be relocated to levels 3, 4, 5, or 6 in the new building.
- Level 3 in the old building can be relocated to any level in the new building.
- Level 4 in the old building can only be relocated to levels 1, 2, or 3 in the new building.
- Level 5 in the old building can only be relocated to levels 1, 2, or 3 in the new building.
- Level 6 in the old building can only be relocated to levels 1, 2, or 3 in the new building.

Notice that levels 4, 5, and 6 in the old buildings must be relocated to levels 1, 2, and 3 in the new buildings. There are 3! = 6 possible ways. The remaining levels, levels 1, 2, and 3 in the old building can be relocated to levels 4, 5, 6 in the new buildings. There are 3! = 6 possible ways. Therefore, there are 6 × 6 = 36 possible permutations.

### Sample Input 2

    0...4..7
    6 2
    1 4
    1 1 2 2 2 2
    2 2 1 2 1 2

### Sample Output 2

    0

### Explanation of Sample 2

Notice that level 2 in the old building is connected to a skybridge at the height of level 1 (the level is higher than the skybridge), but only levels 3 and 5 in the new building are connected to the skybridge (which are also higher than the skybridge). In this case, level 2 cannot be relocated anywhere without violating the restrictions. Thus, there is no possible permutation.

### Subtasks

For all subtasks

- 1 ≤ K ≤ N ≤ 200.000
- 1 ≤ H[i] ≤ N
- All values of H[i] are different.
- 1 ≤ A[i], B[i] ≤ K
- A[i] contains all numbers from 1 to K.
- B[i] contains all numbers from 1 to K.
- For each skybridge, the number of connected levels in the old building, is equal to the number of connected levels in the new building.

#### Subtask 1:

Consists of only the following test case:

    .1..45.7
    5 1
    3
    1 1 1 1 1
    1 1 1 1 1

#### Subtask 2:

Consists of only the following test case:

    ..2.4..7
    9 4
    2 3 5 8
    2 2 1 3 3 2 3 4 4
    2 1 3 2 3 3 2 4 4

#### Subtask 3:

- K = N

#### Subtask 4:

- 1 ≤ K ≤ N ≤ 10

#### Subtask 5:

- K = 1

#### Subtask 6:

- For each i, H[A[i]] ≠ i
- For each i, H[B[i]] ≠ i

#### Subtask 7:

- No additional constraints.
