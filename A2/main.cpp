#include <iostream>
using namespace std;
#include "vector"

struct result{
    int i;
    int e;
    int max;

};

result maxList(vector<int> data);
void testMaxList(vector<vector<int>> testData);


int main() {
    vector<vector<int>> testData;
    testData.push_back({-2,11,-4,13,-5,-2});
    testData.push_back({1, -3, 4, -2, -1, 6});
    testData.push_back({5, -7, 3, 5, -2, 6, -1});

    testMaxList(testData); //this is a function that will run all test cases.
    return 0;
}

result maxList(vector<int> data){
    int e,i,sum,sumMax;
    sumMax = data.at(0);
    e = 0;
    i = 0;

    for(int k = 0; k<data.size();k++){
        sum = 0;
        for(int j = k; j<data.size();j++){
            sum = sum + data.at(j);
            if(sum>sumMax){
                sumMax = sum;
                i = k;
                e = j;
            }
        };
    };
    result r;
    r.max = sumMax;
    r.e = e+1; // +1 because the result start from 1 the index
    r.i = i+1;
    return r;
};

void testMaxList(vector<vector<int>> testData){
    cout<<"Starting the test for the Max Function"<<endl;
    for(int l = 0; l<testData.size();l++){
        cout<<"Result for test data number "<<l+1<<":"<<endl;
        result r = maxList(testData.at(l));
        cout<<"Max Value: "<<r.max<<endl;
        cout<<"i = "<<r.i<<" to "<<"e = "<<r.e<<endl;
    };
}