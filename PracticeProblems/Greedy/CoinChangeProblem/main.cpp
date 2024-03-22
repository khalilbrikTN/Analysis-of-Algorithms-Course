#include <iostream>
#include <iomanip>
#include "vector"

using namespace std;


vector<int> minCoins(vector<int> bills, int value, int n);

void testMinCoins();


int main() {
    testMinCoins();
    return 0;
}


vector<int>minCoins(vector<int> bills, int value, int n){

    int i = 0;
    int count = 0;
    int total;
    total = value;
    vector<int> occ;

    while (total != 0 && i < n){
        if(bills[i] <= total){
            total-= bills[i];
            count++;
        }else{
            occ.push_back(count);
            i++;
            count = 0;
        };
    };
    occ.push_back(count);

    return occ;
};

void testMinCoins(){
    vector<int> bills = {15,10,5,1};
    int n = bills.size();
    int value;

    cout<<"Enter the value owed: ";
    cin>>value;

    vector<int> occ = minCoins(bills, value, n);

    int numCoins = 0;
    cout<<setw(20)<<"billValue"<<setw(20)<<"occurences"<<endl;
    for(int i = 0; i<n; i++){
        cout<<setw(20)<<bills[i]<<setw(20)<<occ[i]<<endl;
        numCoins = numCoins + occ[i];
    }

    cout<<"Number of coins returned is : "<<numCoins<<endl;
}