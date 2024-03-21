#include <iostream>
#include <algorithm>
#include <limits.h>

#include "vector"

using namespace std;


void get_optimal_splitHelper(const vector<vector<int>>& optimal_split, int i, int j, char& matrix_name);
void get_optimal_split(const vector<vector<int>>& optimal_split, int num_matrices);


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

vector<vector<int>> get_optimal_split(vector<int> d, int n);
void printOptimalSplit(const vector<vector<int>>& S, int i, int j);


int main() {
    /*
    vector<int> d = { 40, 20, 30, 10, 30 };
    int n = d.size()-1;
    vector<vector<int>> S = get_optimal_split(d,n);
    printMatrix(S);*/


    vector<vector<int>> optimal_split = {
            {0, 1, 1, 3},
            {0, 0, 2, 3},
            {0, 0, 0, 3},
            {0, 0, 0, 0}
    };
    int num_matrices = 4;
    get_optimal_split(optimal_split, num_matrices);

    return 0;
}

vector<vector<int>> get_optimal_split(vector<int> d, int n){

    vector<vector<int>> M, S;
    //Array M stores the number of multiplications.
    //Array S stores the position of the parentheses.

    M = vector<vector<int> >(n, vector<int>(n));
    S = vector<vector<int> >(n, vector<int>(n));

    for(int l = 1; l<n; l++){
        for(int i = 0; i<n-l; i++){
            int j = i+l;
            M[i][j] = INT_MAX;
            for (int k = i; k < j; k++) {
                int temp = M[i][k] + M[k+1][j] + d[i]*d[k+1]*d[j+1];
                if (temp < M[i][j]) {
                    M[i][j] = temp;
                    S[i][j] = k+1; // Update split position in S matrix
                }
            };
        }
    };
    return S;
};

// Function to print optimal parenthesization
void get_optimal_splitHelper(const vector<vector<int>>& optimal_split, int i, int j, char& matrix_name) {
    if (i == j) {
        cout << matrix_name++;
        return;
    }
    cout << "(";
    get_optimal_splitHelper(optimal_split, i, optimal_split[i][j], matrix_name);
    get_optimal_splitHelper(optimal_split, optimal_split[i][j] + 1, j, matrix_name);
    cout << ")";
}

void get_optimal_split(const vector<vector<int>>& optimal_split, int num_matrices) {
    char matrix_name = 'A';
    cout << "Optimal Parenthesization: ";
    get_optimal_splitHelper(optimal_split, 0, num_matrices - 1, matrix_name);
    cout << endl;
}

