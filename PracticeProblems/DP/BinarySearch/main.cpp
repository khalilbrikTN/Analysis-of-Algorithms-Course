#include <iostream>
#include "vector"

using namespace std;

int binarySearch(vector<int> arr, int i, int j, int target);
void testBinarySearch();

int main() {
    testBinarySearch();

    return 0;
}


int binarySearch(vector<int> arr, int i, int j, int target){
    if((i == j) && !(arr[i] == target)){
        return -1;
    }

    int mid = (i+j)/2;
    if(arr[mid] == target){
        return target;
    }else if(arr[mid] < target){
        return binarySearch(arr,mid+1, j, target);
    }else{
        return binarySearch(arr,i, mid, target);
    }

}

void testBinarySearch(){
    vector<int> arr = {10,20,30,40,50,60}; // sorted array
    int target;
    int n = arr.size();

    for(int i = 0; i<4; i++){
        cout<<"Enter target: ";
        cin>>target;
        if(binarySearch(arr, 0, n-1, target) == -1){
            cout<<"Target value of "<<target<<" is not found!"<<endl;
        }else{
            cout<<"Target value of "<<target<<" is Found!"<<endl;
        }
    }
}