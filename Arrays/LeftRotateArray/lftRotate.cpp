#include <bits/stdc++.h>
using namespace std;

void rotateArrayByOne(vector<int>& nums) 
{
    int first = nums[0];
    int i = 1;
    for (; i<nums.size();i++){
        nums[i-1] = nums[i];
    }
    nums[i-1] = first;
} // TC: O(n) SC: O(1)

void rotateArrayByK(vector<int>& nums, int k) 
{
    k = k % nums.size(); // if k is size of array, then we can rotate it by 0 times, so we take mod of k with size of array
    // for(int i=0 ; i<k ; i++){
    //     rotateArrayByOne(nums);
    // }
    // TC: O(n*k) SC: O(1) -> tc O(n^2)

    //better 
    vector<int> temp = vector<int>(nums.begin(), nums.begin()+k); // store first k elements in temp array
    for (int i=k ; i<nums.size();i++){
        nums[i-k] = nums[i]; 
    }

    for(int i=k+1; i<nums.size();i++){
        nums[i] = temp[i-k-1];
    }
    //TC: O(n) SC: O(k)
} 

int main() {
    vector<int> nums = {1,2,3,4,5};
    // rotateArrayByOne(nums);
    // for(int i=0 ; i<nums.size() ; i++){
    //     cout << nums[i] << " ";
    // }
    // cout << endl;
    rotateArrayByK(nums, 2);
    for(int i=0 ; i<nums.size() ; i++){
        cout << nums[i] << " ";
    }
    return 0;
}


