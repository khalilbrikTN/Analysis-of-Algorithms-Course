//53. Maximum Subarray
//Given an integer array nums, find the subarray
// with the largest sum, and return its sum.

#include <iostream>
#include "limits.h"
#include "vector"
using namespace std;

int maxSubArray(vector<int>& nums);
int maxSum(vector<int>& nums, int s, int e);
int crossMax(vector<int>& nums, int s, int e, int m);


int main() {
    vector<int> arr = {10,20,30,40};
    cout<<maxSubArray(arr);
    //cout<<crossMax(arr, 0, 3, 1);

    return 0;
}

int maxSum(vector<int>& nums, int s, int e){
    int left, right, cross, mid;

    if(s == e){
        return nums[s];
    }else{
        mid = (e+s)/2;
        left = maxSum(nums, s, mid);
        right = maxSum(nums, mid+1, e);
        cross = crossMax(nums, s, e, mid);
        return max(left, max(right, cross));
    }

};

int crossMax(vector<int>& nums, int s, int e, int m){
    if(s == e){
        return nums[s];
    }
    else{
        int leftSum = INT_MIN;
        int sum = 0;
        for(int i = m; i >= s; i--) {
            sum = sum + nums[i];
            if(sum > leftSum) {
                leftSum = sum;
            }
        }

        // Find the maximum subarray sum on the right side of the middle po>
        int rightSum = INT_MIN;
        sum = 0;
        for(int i = m + 1; i <= e; i++) {
            sum = sum + nums[i];
            if(sum > rightSum) {
                rightSum = sum;
            }
        }

        return leftSum + rightSum;
    }
};


int maxSubArray(vector<int>& nums){
    int n = nums.size();
    int s = 0;
    int e = n-1;
    return maxSum(nums, s, e);
}