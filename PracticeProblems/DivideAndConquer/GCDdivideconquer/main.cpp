#include <iostream>
#include <algorithm>

using namespace std;

//This is the function of the GCD using divide and conquer approach.
int GCD(int i, int j);


int main() {
    cout<<GCD(168,64)<<endl;
    return 0;
}
int GCD(int i, int j){
    int M = max(i,j);
    int m = min(i,j);

    int rem = M%m;

    if(rem == 0){
        return m;
    }else{
        return GCD(m, rem);
    };
}

