#include <algorithm>
#include <iostream>
#include <vector>
#include "limits.h" // For using INT_MAX
using namespace std;

// Function prototypes
vector<vector<int>> get_optimal_split(vector<int> d, int n);
string print_optimal(const vector<vector<int>>& k, int i, int j);
void printMatrix(const vector<vector<int>>& matrix);

int main() {
    // Given dimensions of matrices
    vector<int> d = { 4, 4, 6, 12, 7 };
    int n = d.size() - 1; // Number of matrices

    // Calculate optimal split using dynamic programming
    vector<vector<int>> K = get_optimal_split(d, n);

    // Print the matrix showing optimal split positions
    printMatrix(K);

    // Print the optimal expression
    string expression = print_optimal(K, 1, n);
    cout << "Optimal expression: " << expression << endl;

    return 0;
}

// Function to calculate optimal split positions using dynamic programming
vector<vector<int>> get_optimal_split(vector<int> d, int n) {
    vector<vector<int>> M, S;
    // M stores the minimum number of multiplications required
    // S stores the position of the optimal split

    M = vector<vector<int>>(n, vector<int>(n));
    S = vector<vector<int>>(n, vector<int>(n));

    // Dynamic programming loop to fill M and S matrices
    for (int l = 1; l < n; l++) {
        for (int i = 0; i < n - l; i++) {
            int j = i + l;
            M[i][j] = INT_MAX;
            for (int k = i; k < j; k++) {
                int temp = M[i][k] + M[k + 1][j] + d[i] * d[k + 1] * d[j + 1];
                if (temp < M[i][j]) {
                    M[i][j] = temp;
                    S[i][j] = k + 1; // Update split position in S matrix
                }
            }
        }
    }
    return S;
}

// Function to recursively print the optimal expression
string print_optimal(const vector<vector<int>>& k, int i, int j) {
    if (i == j) {
        return "A_" + to_string(i + 1); // Base case: single matrix
    }

    int min_k = k[i][j]; // Optimal split position
    string expr1 = print_optimal(k, i, min_k);
    string expr2 = print_optimal(k, min_k + 1, j);
    return "(" + expr1 + " * " + expr2 + ")"; // Combine expressions with parentheses
}

// Function to print a matrix
void printMatrix(const vector<vector<int>>& matrix) {
    int rows = matrix.size();
    if (rows == 0) {
        cout << "Matrix is empty" << endl;
        return;
    }
    int cols = matrix[0].size();
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}
