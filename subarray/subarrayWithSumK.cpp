#include<bits/stdc++.h>
using namespace std;

int subArraySumKCount (vector<int> &nums, int k){
    //brute force: Check the sum of all the subarrays and count the no. of subarrays with sum as k
    int count = 0;
    for(int i=0; i<nums.size(); i++){
        int sum = 0;
        for(int j=i; j<nums.size(); j++){
            sum += nums[j];
            if(sum == k){
                count++;
            }
        }
    }
    return count; //TC: O(n^2) SC: O(1)

    //better
    
}

int main(){
    vector<int> nums = {1, 2, 3, 4, 5};
    int k = 5;
    cout << subArraySumKCount(nums, k) << endl;
    return 0;
}