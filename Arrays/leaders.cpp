#include   <bits/stdc++.h>
using namespace std;

vector<int> leaders(vector<int> &nums)
{
    vector<int> ans;
    int maxi=INT_MIN;
    for(int i=nums.size()-1; i>=0; i--){
        if(nums[i]>maxi){
            ans.push_back(nums[i]);
            maxi = nums[i];
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    vector<int> nums = {16, 17, 4, 3, 5, 2};
    vector<int> ans = leaders(nums);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}