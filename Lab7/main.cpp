#include <algorithm>
#include <iostream>
#include <vector>
#include "limits.h"
using namespace std;


vector<vector<int>> get_optimal_split(vector<int> d, int n);
string print_optimal(const vector<vector<int>>& k, int i, int j);


//A Function I use to print any matrix of any size.
void printMatrix(const vector<vector<int>>& matrix);




int main() {

    vector<int> d = { 4, 4, 6, 12, 7 };
    int n = d.size()-1;
    vector<vector<int>> K = get_optimal_split(d,n);
    printMatrix(K);

    string expression = print_optimal(K, 1, n);
    cout << "Optimal expression: " << expression << endl;

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


string print_optimal(const vector<vector<int>>& k, int i, int j) {
    if (i == j) {
        return "A_" + to_string(i + 1); // Base case: single matrix
    }

    int min_k = k[i][j];
    string expr1 = print_optimal(k, i, min_k);
    string expr2 = print_optimal(k, min_k + 1, j);
    return "(" + expr1 + " * " + expr2 + ")"; // Combine expressions with parentheses
}

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


