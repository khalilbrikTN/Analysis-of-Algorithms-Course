#include <iostream>
#include <vector>

using namespace std;

/* Time Complexity Analysis:
 - The time complexity of the provided solution can be analyzed based on the recursive relation and the number of operations performed at each step.
 - At each recursive step, the array is divided into two halves until it reaches subarrays of size 1. Therefore, the depth of recursion is O(log n), where n is the size of the array.
 - At each level of recursion, the function performs a linear number of operations, as it needs to process each element of the subarray. Therefore, the time complexity at each level is O(n).
 - Thus, the overall time complexity of the solution is O(n log n), where n is the size of the input array. This indicates that the time complexity of the solution is logarithmic with respect to the input size n.
   Time Complexity (T(n)) Formula:
   T(n) = O(n log n), where n is the size of the input array.
   This indicates that the time complexity of the solution is logarithmic with respect to the input size n.
*/

int countBins(vector<int> arr, int s, int e);
void testFunction();
int main() {
    testFunction();
    return 0;
}


int countBins(vector<int> arr, int s, int e){
    // Calculate the length of the subarray
    int n = e - s + 1;

    // Base case: If there's only one element in the subarray, return it
    if(n == 1){
        return arr[s];
    }

    // Find the middle index of the subarray
    int mid = (e + s) / 2;
    int left, right;

    // Recursively count the number of bins in the left half
    if(arr[mid] == 0){
        left = 0;
    } else {
        left = countBins(arr, s, mid);
    }

    // Recursively count the number of bins in the right half
    if(arr[mid + 1] == 1){
        right = e - mid;
    } else {
        right = countBins(arr, mid + 1, e);
    }

    // Return the sum of bins in the left and right halves
    return left + right;
}

void testFunction(){
    // Test cases
    vector<vector<int>> testInputs = {
            {0,0,0,0,0,0,0,0,0,0,0,0}, // Result: 0
            {1,1,1,1,1,1,1,1,1,1,1,1}, // Result: 12
            {0,0,0,0,0,1,1,1,1,1,1,1,1,1,1}, // Result: 10
            {0,0,0,0,0,0,0,0,0,0,1}, // Result: 1
            {0,0,0,0,0,0,0,0,1,1,1,1}, // Result: 4
            {0,1,1,1,1,1,1,1,1,1,1,1}, // Result: 11
            {0,0,0,0,0,0,0,0,0,0,1,1,1}, // Result: 3
            {0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1} // Result: 14
    };

    // Iterate through each test case
    for (int i = 0; i < testInputs.size(); ++i) {
        vector<int> items = testInputs[i];
        cout << "Test Case " << i + 1 << " :";
        for (auto u : items){
            cout << u << " ";
        }
        cout << " --> Result : " << countBins(items, 0, items.size() - 1);
        cout << endl;
    }
}

