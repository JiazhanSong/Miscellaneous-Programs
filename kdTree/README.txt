An algorithm to construct a kd-tree for dimension 2. Reads 2n+1 integers from standard input, separated by white space. The first integer is the number of points. The remaining 2n integers are the points themselves, according to their x and y coordinates.

The program prints to standard output the n points in the order they are visited during a pre-order traversal of a kd-tree

Here is an example input and output file.
Input: 4 3 4 2 2 0 1 1 3
Output: 2 2 1 3 0 1 3 4

Solution is implemented in O(nlog(n)) time as opposed to n^2.
