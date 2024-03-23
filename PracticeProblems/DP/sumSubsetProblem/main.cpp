#include <iostream>
#include "vector"
using namespace std;

bool sumSubsetNODP(vector<int> w, int i, int j);

int main() {
    vector<int> arr = {10,20,30};
    if(sumSubsetNODP(arr, 2, 10)){cout<<"true";}
    return 0;
}

bool sumSubsetNODP(vector<int> w, int i, int j){
    if(i == 0) {return j == 0;}
    else{
        if(sumSubsetNODP(w, i-1, j)){return true;}
        else if(j-w[i] >= 0){return sumSubsetNODP(w, i-1, j-w[i]);}
        else{
            return false;
        };
    };
};