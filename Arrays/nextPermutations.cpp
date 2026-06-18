#include <bits/stdc++.h>
using namespace std;

void nextPermutation(vector<int> &nums){
    int index=-1;
    int n=nums.size();
    for(int i=n-2; i>=0; i--){
        if(nums[i]<nums[i+1]){
            index=i;
            break;  
        }
    }
    if(index==-1){  //The array is in descending order, so we need to reverse the array to get the next permutation.
        reverse(nums.begin(), nums.end());
        return;
    }
    for(int i=n-1; i>index; i--){
        if(nums[i]>nums[index]){
            swap(nums[i], nums[index]);
            break;
        }
    }
    reverse(nums.begin() + index + 1, nums.end());
}

int main()
{
    vector<int> nums = {5, 3, 1, 3, 2};
    nextPermutation(nums);
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    return 0;
}