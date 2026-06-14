#include <bits/stdc++.h>
using namespace std;

int majorityElement(vector<int>& nums) {
        // sort(nums.begin(), nums.end());
        // return nums[nums.size()/2];  //TC: O(nlogn) brute
        // map<int, int>mp;
        // for(int i =0; i<nums.size(); i++){  //nlogn
        //     mp[nums[i]]++; //logn
        // }
        // for (auto it:mp){
        //     if(it.second > nums.size()/2)
        //         return it.first;
        // }
        // return -1; // TC: O(n + nlogn) //SC: O(n)

        //moore's voting algo
        int el, count=0;
        for(int i=0; i<nums.size(); i++){
            if(count==0){
                count=1;
                el = nums[i];
            }
            else if(nums[i]==el)
                count++;
            else if(nums[i]!=el)
                count--;
            
        } 
        return el; //TC: O(n)
    }

int main(){
    vector<int> nums={2,2,1,1,1,2,2};
    cout<<majorityElement(nums)<<endl;
    return 0;
}