This code implements the matrix chain multiplication algorithm to find the optimal order of multiplying a chain of matrices.

Features:

Calculates the minimum number of scalar multiplications needed for matrix multiplication.
Determines the optimal parenthesization for matrix multiplication.
Provides a function to print any matrix (useful for debugging).

Input:

The code takes a vector d representing the dimensions of the matrices
in the chain. In this example, d = {4, 4, 6, 12, 7} represents matrices
of dimensions (4x4), (4x6), (6x12), and (12x7).

Output:

The optimal parenthesization for matrix multiplication will be printed.
The minimum number of scalar multiplications will be printed.

Note:

This code assumes valid matrix dimensions (positive integers).
