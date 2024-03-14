#include <iostream>
#include "vector"
#include <limits.h>

using namespace std;
/*

Analysis of Time Complexity and T(n) Formula:

The provided solution uses a divide and conquer approach to find the maximum subarray.
At each recursive step, the array is divided into two halves until reaching the base case where the
subarray contains only one element.In each recursive call, the work is divided into three
parts: finding the maximum subarray in the left half, in the right half, and a subarray crossing the
middle. The time complexity can be expressed by the recurrence relation:
 T(n) = 2T(n/2)+O(n)
*/


// Structure to represent a subarray period with start index, end index, and profit
struct period {
    int s; // Start index of the subarray
    int e; // End index of the subarray
    int profit; // Profit (sum of elements) of the subarray
};

// Function to find the maximum subarray that crosses the middle point
period maxCrossingSubarray(vector<int> arr, int s, int e);

// Function to find the maximum subarray within a given range [s, e]
period maxProfit(vector<int> arr, int s, int e);

// Function to print test results
void printTestResults();

int main() {
    printTestResults();
    return 0;
}

// Function to find the maximum subarray within a given range [s, e]
period maxProfit(vector<int> arr, int s, int e){

    period result;

    // Base case: If the subarray has only one element
    if(s == e) {
        result.s = s;
        result.e = e;
        result.profit = arr[s];
        return result;
    }

    period leftProfit, rightProfit, crossProfit;
    int m;
    m = (e + s) / 2;

    // Recursively find the maximum subarrays in left, right, and crossing the middle
    leftProfit = maxProfit(arr, s, m);
    rightProfit = maxProfit(arr, m + 1, e);
    crossProfit = maxCrossingSubarray(arr, s, e);

    // Compare the profits of left, right, and cross subarrays to find the maximum profit
    if(leftProfit.profit > max(rightProfit.profit, crossProfit.profit)) {
        result = leftProfit;
    } else if (rightProfit.profit > max(leftProfit.profit, crossProfit.profit)) {
        result = rightProfit;
    } else {
        result = crossProfit;
    }

    return result;
}

// Function to find the maximum subarray that crosses the middle point
period maxCrossingSubarray(vector<int> arr, int s, int e) {
    period result;

    int leftIndex, rightIndex;
    int mid = (e + s) / 2;

    // Find the maximum subarray sum on the left side of the middle point
    int leftSum = INT_MIN;
    int sum = 0;
    for(int i = mid; i >= s; i--) {
        sum = sum + arr[i];
        if(sum > leftSum) {
            leftSum = sum;
            leftIndex = i;
        }
    }

    // Find the maximum subarray sum on the right side of the middle point
    int rightSum = INT_MIN;
    sum = 0;
    for(int i = mid + 1; i <= e; i++) {
        sum = sum + arr[i];
        if(sum > rightSum) {
            rightSum = sum;
            rightIndex = i;
        }
    }

    // Store the indices and sum of the maximum crossing subarray
    result.s = leftIndex;
    result.e = rightIndex;
    result.profit = leftSum + rightSum;
    return result;
}

// Function to print test results
void printTestResults() {

    // Test cases
    vector<vector<int>> testCases = {
            {1, 2, 3, 4, 5},
            {-1, -2, -3, -4, -5},
            {2, -1, 2, 3, 4, -5},
            {3, -2, 3, -1, 2, 4, 5, -6},
            {-2, -5, 6, -2, -3, 1, 5, -6},
            {4, 1, 3, 7, -1, -5, 6},
            {1, 2, -4, 5, -1, -2, 6},
            {-1, -2, 10, 10, 5}
    };

    // Iterate through each test case
    for(int i = 0; i < testCases.size(); i++) {
        vector<int> arr = testCases[i];
        period result = maxProfit(arr, 0, arr.size() - 1);

        // Print the input array
        cout << "Test " << i << " : ";
        for (int num : arr) {
            cout << num << " ";
        }
        cout << endl;

        // Print the maximum subarray
        cout << "Maximum Subarray: ";
        for (int i = result.s; i <= result.e; ++i) {
            cout << arr[i] << " ";
        }
        cout << endl;

        // Print the maximum profit (sum of elements)
        cout << "Maximum Profit: " << result.profit << endl;
        cout << "-------------------------------------" << endl;
    }
}
