#include <bits/stdc++.h>
using namespace std;

bool bruteTwoSum(vector<int>& nums, int target){
    for(int i=0; i<nums.size(); i++){
        for(int j=i+1; j<nums.size(); j++){
            if(nums[i]+nums[j] == target){
                return true;
            }
        }
    }
    return false;
    //TC: O(n^2), SC: O(1)
}

bool betterTwoSum(vector<int>& nums, int target){
    unordered_map<int, int> hash;
    for(int i=0; i<nums.size();i++){
        if(hash.find(target - nums[i]) != hash.end())
            return true;
        hash[nums[i]] = i;
    }
    return false;
} //TC: O(n), in worst case  too many collisions O(n^2), for map it would be O(nlogn)

int main(){
    vector<int> nums={1,2,3,4,5};
    int target=9;
    cout<<bruteTwoSum(nums, target)<<endl;
    cout << betterTwoSum(nums,target)<<endl;
    return 0;
}