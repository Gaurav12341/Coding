#include <bits/stdc++.h>
using namespace std;

int longestSubarrayWithSumK(vector <int>& nums, int k){
    //all subarrays 
    int longest=0;
    // for(int i=0;i<nums.size(); i++){
    //     int sum=0;
    //     for(int j=i;j<nums.size(); j++){
    //         sum+=nums[j];
    //         if(sum==k){
    //             longest=max(longest, j-i+1);
    //         }
    //     }
    // }
    // return longest;
    //TC: O(n^2)

    //using hashing
    unordered_map<int, int> hash; // create a hash map to store the prefix sum and its index. We can use a hash map to store the prefix sum and its index in O(n) time and O(n) space.
    int prefixSum=0;
    for(int i=0; i<nums.size(); i++){
        prefixSum+= nums[i];
        if(prefixSum == k){
            longest = max(longest, i+1); // if the prefix sum is equal to k, then we can update the longest subarray length to i+1, because the subarray from index 0 to index i has a sum of k.
        }
        if(hash.find(prefixSum-k) !=hash.end()){
            longest = max(longest, i-hash[prefixSum-k]); // if the prefix sum minus k is present in the hash map, then we can update the longest subarray length to i-hash[prefixSum-k], because the subarray from index hash[prefixSum-k]+1 to index i has a sum of k.
        } 
        if(hash.find(prefixSum) == hash.end())  // this will work with arrays with 0 as well, because if the prefix sum is already present in the hash map, then we don't need to update it, because we want the longest subarray, so we only store the first occurrence of the prefix sum in the hash map. 

            hash[prefixSum] = i; // store the prefix sum and its index in the hash map
    }
    return longest;
    //TC: O(n), but rare O(n^2) in case of unordered map, in case of collisions. if we use map then O(nLogn), SC: O(n) where n is the size of the input array, which is efficient for large n.
}

//using two pointer approach, but this will work only for positive numbers, because if we have negative numbers then we can't guarantee that the sum will be less than k, so we can't move the right pointer, because we don't know if the sum will be less than k or not.

//move right pointer until the sum is less than k, if the sum = k then update the longest subarray, if the sum is greater than k then move the left pointer until the sum is less than k.
int loongestSubarrayWithKPositives(vector<int>& nums, long long k){
    if(nums.size()<2 && nums[0]==k){
        return 1;
    }
    int left=0;
    int right=0;
    int sum=nums[left];
    int longest=0;
    while(right<nums.size()){
        while (sum>k){
            sum-=nums[left];
            left++;
        }
        if(sum==k){
            longest=max(longest, right-left+1);
        }
        right++;
        if(right<nums.size()){
            sum+=nums[right];
        }
    }
    return longest;
} // TC: O(2n), SC: O(1)

int main(){
    vector <int> nums = {1, 2, 3, 4, 5};
    int k = 9;
    cout << longestSubarrayWithSumK(nums, k) << endl;
    cout<< loongestSubarrayWithKPositives(nums,k) << endl;
    return 0;
}