## Online Taxi

### Description

There are V cities in West Sumatra, numbered 1 through V. There are E two-way roads connecting the cities, numbered 1 through E. The i-th road connects city X[i] with city Y[i], and has length of K[i]. Each pair of cities are directly connected by at most one road. No roads connect a city with itself.

There are only two modes of transportation: local taxis and online taxis. You can book either of them via your phone, which will then come over to you wherever you are.

There are some rules on booking taxis, which depends on where you currently are and the taxi type, which will be explained below:

- If you are currently in a city (i.e., at either ends of a road), you can book and get on a local taxi or an online taxi.
- If you are currently on any part of a road having integer distance from either end (which will be called "integer part" from now on), except cities as explained above, you can:
  - book and get on a local taxi.
  - book and get on an online taxi, only if the road is NOT controlled by local taxis. The i-th road is controlled by local taxis if Q[i] = 1.

After you book a taxi and get on it, for either taxi types, you can ride it along any cities and roads, and then get off in any cities and on any integer parts of any roads.

For local taxis, the fare for a single trip is C\_p (flat fares), and the maximum distance allowed for a single trip is M\_p.

For online taxis, the fare for a single trip is C\_d × (distance traveled), and the maximum distance allowed for a single trip is M\_d.

You want to go from city A to city B, using only taxis (i.e., without walking). Determine the cheapest possible total fares!

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

    V E
    C_d M_d
    M_p M_p
    A B
    X[1] Y[1] K[1] Q[1]
    X[2] Y[2] K[2] Q[2]
    .
    .
    X[E] Y[E] K[E] Q[E]

### Output Format

A single line containing the cheapest possible total fares to get from city A to city B. 

### Sample Input 1

    0...4567
    4 4
    1 3
    2 1
    1 2
    1 2 7 1
    1 3 2 0
    3 4 4 0
    4 2 6 0
    
### Sample Output 1

    11

### Explanation of Sample 1

TODO

### Sample Input 2

    0...4567
    7 9
    1 1
    2 1
    1 7
    1 2 1 1
    2 3 1 1
    3 1 1 1
    3 4 1 1
    4 5 1 1
    5 3 1 1
    5 6 1 1
    6 7 1 1
    7 5 1 1

### Sample Output 2

    3

### Explanation of Sample 2

TODO

### Subtasks

For all subtasks:

- 2 ≤ V ≤ 200
- V - 1 ≤ E ≤ V × (V - 1) / 2
- 1 ≤ C\_p, C\_d ≤ 10^9
- 1 ≤ M\_p, M\_d ≤ 200
- 1 ≤ A, B, X[i], Y[i] ≤ V
- A != B
- For each i, X[i] != Y[i]
- 1 ≤ K[i] ≤ 10^9
- 0 ≤ Q[i] ≤ 1
- Each pair of cities are directly connected by at most one road.
- It is guaranteed that it is possible to go from each city to every other cities via cities and roads.

#### Subtask 1:

Consists of only the following test case:

TODO

#### Subtask 2:

Consists of only the following test case:

TODO

#### Subtask 3:

- C\_d = C\_p = 1
- M\_d = M\_p = 1
- K[i] = 1

#### Subtask 4:

- M\_d = M\_p = 1

#### Subtask 5:

- K[i] ≤ 10

#### Subtask 6:

- K[i] ≤ 200

#### Subtask 7:

- No additional constraints.
