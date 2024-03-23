#include <iostream>
#include "vector"
#include "algorithm"
using namespace std;

struct dim{
    int m;
    int n;
    int c;

};

long long int gridTravelerNODP(int m, int n, long long int count);
long long int gridTravelerMemo(int m, int n, long long int count, vector<dim> history);
int gridTravelTabulation(int m, int n, vector<vector<int>> T){


    T = vector<vector<int> >(n, vector<int>(m));

    for(int i = 0; i<m; i++){
        T[0][i] = 1;
    };
    for(int i = 0; i<n; i++){
        T[i][0] = 1;
    };

    for(int i = 1; i<n; i++){
        for (int j = 1; j < m; j++) {
            T[i][j] = T[i][j-1] + T[i-1][j];
        };
    };

    return T[n-1][m-1];
}



int findInVector(vector<dim> history, dim d); //Find the index of a dim in history if m and n are found.

int main() {
    int m;
    int n;
    long long int  c = 0;
    vector<vector<int>> T;
    vector<dim> history;

    cin>>m;
    cin>>n;


    cout<<"NO DP approach: "<<gridTravelerNODP(m,n,c)<<endl;
    cout<<"DP Memoization approach: "<<gridTravelerMemo(m,n,c, history)<<endl;
    cout<<"DP Tabulation approach: "<<gridTravelTabulation(m,n,T)<<endl;


    return 0;
}

long long int gridTravelerNODP(int m, int n,long long int count){
    if(m == 0 || n == 0){
        return 0;
    }
    else if (m == 1 || n == 1){
        return 1;
    }
    else{
        return count + gridTravelerNODP(m-1,n,count) + gridTravelerNODP(m,n-1,count);;
    }
}

long long int gridTravelerMemo(int m, int n, long long int count, vector<dim> history){
    if(m == 0 || n == 0){
        return 0;
    }
    else if (m == 1 || n == 1){
        return 1;
    }
    else{
        dim temp;
        temp.m = m;
        temp.n = n;
        int foundCheck = findInVector(history, temp);

        if(foundCheck == -1){
            count  = count + gridTravelerMemo(m-1,n,count, history) + gridTravelerMemo(m,n-1,count, history);
            temp.c = count;
            history.push_back(temp);
            return count;
        }else{
            return history[foundCheck].c;
        }
    }
}

int findInVector(vector<dim> history, dim d){

    for(int i = 0; i<history.size(); i++){
        if(history[i].m == d.m && history[i].n == d.n){
            return i;
        }
    }
    return -1;
}